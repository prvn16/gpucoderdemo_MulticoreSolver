/*
 * slexMulticoreSolverExample.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "slexMulticoreSolverExample".
 *
 * Model version              : 1.16
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jan 17 08:52:03 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "slexMulticoreSolverExample.h"
#include "slexMulticoreSolverExample_private.h"

/* Tasks */
RT_MODEL_slexMulticoreSolverE_T task_M_[2];
RT_MODEL_slexMulticoreSolverE_T *task_M[2];

/* Continuous states of tasks */
X_slexMulticoreSolverExample_T slexMulticoreSolverExample_X;

/* Block signals (auto storage) */
B_slexMulticoreSolverExample_T slexMulticoreSolverExample_B;

/* Block states (auto storage) */
DW_slexMulticoreSolverExample_T slexMulticoreSolverExample_DW;

/* Real-time model */
RT_MODEL_slexMulticoreSolverE_T slexMulticoreSolverExample_M_;
RT_MODEL_slexMulticoreSolverE_T *const slexMulticoreSolverExample_M =
  &slexMulticoreSolverExample_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void Periodic_Thread1_rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetSolverOutputComputed(si, true);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);

  /* Derivatives for ModelReference: '<Root>/Model 1' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x2,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread1 *) task_M[0]->derivs)
      ->Model1_CSTATE));

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  rtsiSetSolverOutputComputed(si, false);
  Periodic_Thread1_step();

  /* Derivatives for ModelReference: '<Root>/Model 1' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x2,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread1 *) task_M[0]->derivs)
      ->Model1_CSTATE));
  rtsiSetSolverOutputComputed(si, true);

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  rtsiSetSolverOutputComputed(si, false);
  Periodic_Thread1_step();

  /* Derivatives for ModelReference: '<Root>/Model 1' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x2,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread1 *) task_M[0]->derivs)
      ->Model1_CSTATE));
  rtsiSetSolverOutputComputed(si, true);

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
  rtsiSetSolverOutputComputed(si, false);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void Periodic_Thread2_rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetSolverOutputComputed(si, true);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);

  /* Derivatives for ModelReference: '<Root>/Model 2' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x1_m,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread2 *) task_M[1]->derivs)
      ->Model2_CSTATE));

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  rtsiSetSolverOutputComputed(si, false);
  Periodic_Thread2_step();

  /* Derivatives for ModelReference: '<Root>/Model 2' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x1_m,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread2 *) task_M[1]->derivs)
      ->Model2_CSTATE));
  rtsiSetSolverOutputComputed(si, true);

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  rtsiSetSolverOutputComputed(si, false);
  Periodic_Thread2_step();

  /* Derivatives for ModelReference: '<Root>/Model 2' */
  slexMulticoreSolverMdlref_Deriv(&slexMulticoreSolverExample_B.x1_m,
    &(((XDot_slexMulticoreSolverExamp_T_Periodic_Thread2 *) task_M[1]->derivs)
      ->Model2_CSTATE));
  rtsiSetSolverOutputComputed(si, true);

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
  rtsiSetSolverOutputComputed(si, false);
}

/*   This function updates active task counters and model execution time. */
void AdvanceTaskCounters(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++slexMulticoreSolverExample_M->Timing.clockTick0)) {
    ++slexMulticoreSolverExample_M->Timing.clockTickH0;
  }

  slexMulticoreSolverExample_M->Timing.t[0] =
    slexMulticoreSolverExample_M->Timing.clockTick0 *
    slexMulticoreSolverExample_M->Timing.stepSize0 +
    slexMulticoreSolverExample_M->Timing.clockTickH0 *
    slexMulticoreSolverExample_M->Timing.stepSize0 * 4294967296.0;
}

/* Step for Task: Periodic_Thread1 */
void Periodic_Thread1_step(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_x1;
  if (rtmIsMajorTimeStep(task_M[0])) {
    /* set solver stop time */
    if (!(task_M[0]->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&task_M[0]->solverInfo, ((task_M[0]
        ->Timing.clockTickH0 + 1) * task_M[0]->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&task_M[0]->solverInfo, ((task_M[0]
        ->Timing.clockTick0 + 1) * task_M[0]->Timing.stepSize0 + task_M[0]
        ->Timing.clockTickH0 * task_M[0]->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(task_M[0])) {
    task_M[0]->Timing.t[0] = rtsiGetT(&task_M[0]->solverInfo);
  }

  {
    real_T alpha;

    /* TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Inport1' */
    if (rtmIsMajorTimeStep(task_M[0])) {
      slexMulticoreSolverExample_DW.fr_buf_2 =
        (slexMulticoreSolverExample_DW.fr_buf_2 + 1) % 4;
      slexMulticoreSolverExample_DW.tr_buf_2 = (real_T)task_M[0]->Timing.t[0] -
        task_M[0]->Timing.stepSize0;
    }

    alpha = (task_M[0]->Timing.t[0] - slexMulticoreSolverExample_DW.tr_buf_2) /
      task_M[0]->Timing.stepSize0;
    slexMulticoreSolverExample_B.x2 =
      (slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[slexMulticoreSolverExample_DW.fr_buf_2]
       - slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu
       [(slexMulticoreSolverExample_DW.fr_buf_2 == 0 ? 4 :
         slexMulticoreSolverExample_DW.fr_buf_2) - 1]) * alpha +
      slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[slexMulticoreSolverExample_DW.fr_buf_2];

    /* End of TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Inport1' */

    /* ModelReference: '<Root>/Model 1' */
    slexMulticoreSolverMdlref(&rtb_x1,
      &(slexMulticoreSolverExample_X.Model1_CSTATE),
      slexMulticoreSolverExample_P.Model1_K);

    /* TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Outport1' */
    if (rtmIsMajorTimeStep(task_M[0])) {
      slexMulticoreSolverExample_DW.fw_buf_1 =
        (slexMulticoreSolverExample_DW.fw_buf_1 + 1) % 4;
      slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[slexMulticoreSolverExample_DW.fw_buf_1]
        = rtb_x1;
    }

    /* End of TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Outport1' */
  }

  if (rtmIsMajorTimeStep(task_M[0])) {
    /* Update for ModelReference: '<Root>/Model 1' */
    slexMulticoreSolverMdlre_Update();
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(task_M[0])) {
    Periodic_Thread1_rt_ertODEUpdateContinuousStates(&task_M[0]->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++task_M[0]->Timing.clockTick0)) {
      ++task_M[0]->Timing.clockTickH0;
    }

    task_M[0]->Timing.t[0] = rtsiGetSolverStopTime(&task_M[0]->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    task_M[0]->Timing.clockTick1++;
    if (!task_M[0]->Timing.clockTick1) {
      task_M[0]->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Step for Task: Periodic_Thread2 */
void Periodic_Thread2_step(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_x2;
  if (rtmIsMajorTimeStep(task_M[1])) {
    /* set solver stop time */
    if (!(task_M[1]->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&task_M[1]->solverInfo, ((task_M[1]
        ->Timing.clockTickH0 + 1) * task_M[1]->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&task_M[1]->solverInfo, ((task_M[1]
        ->Timing.clockTick0 + 1) * task_M[1]->Timing.stepSize0 + task_M[1]
        ->Timing.clockTickH0 * task_M[1]->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(task_M[1])) {
    task_M[1]->Timing.t[0] = rtsiGetT(&task_M[1]->solverInfo);
  }

  {
    real_T alpha;

    /* TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Inport1' */
    if (rtmIsMajorTimeStep(task_M[1])) {
      slexMulticoreSolverExample_DW.fr_buf_1 =
        (slexMulticoreSolverExample_DW.fr_buf_1 + 1) % 4;
      slexMulticoreSolverExample_DW.tr_buf_1 = (real_T)task_M[1]->Timing.t[0] -
        task_M[1]->Timing.stepSize0;
    }

    alpha = (task_M[1]->Timing.t[0] - slexMulticoreSolverExample_DW.tr_buf_1) /
      task_M[1]->Timing.stepSize0;
    slexMulticoreSolverExample_B.x1_m =
      (slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[slexMulticoreSolverExample_DW.fr_buf_1]
       - slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu
       [(slexMulticoreSolverExample_DW.fr_buf_1 == 0 ? 4 :
         slexMulticoreSolverExample_DW.fr_buf_1) - 1]) * alpha +
      slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[slexMulticoreSolverExample_DW.fr_buf_1];

    /* End of TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Inport1' */

    /* ModelReference: '<Root>/Model 2' */
    slexMulticoreSolverMdlref(&rtb_x2,
      &(slexMulticoreSolverExample_X.Model2_CSTATE),
      (slexMulticoreSolverExample_P.Model2_K));

    /* TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Outport1' */
    if (rtmIsMajorTimeStep(task_M[1])) {
      slexMulticoreSolverExample_DW.fw_buf_2 =
        (slexMulticoreSolverExample_DW.fw_buf_2 + 1) % 4;
      slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[slexMulticoreSolverExample_DW.fw_buf_2]
        = rtb_x2;
    }

    /* End of TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Outport1' */
  }

  if (rtmIsMajorTimeStep(task_M[1])) {
    /* Update for ModelReference: '<Root>/Model 2' */
    slexMulticoreSolverMdlre_Update();
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(task_M[1])) {
    Periodic_Thread2_rt_ertODEUpdateContinuousStates(&task_M[1]->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++task_M[1]->Timing.clockTick0)) {
      ++task_M[1]->Timing.clockTickH0;
    }

    task_M[1]->Timing.t[0] = rtsiGetSolverStopTime(&task_M[1]->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    task_M[1]->Timing.clockTick1++;
    if (!task_M[1]->Timing.clockTick1) {
      task_M[1]->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

void slexMulticoreSolverExample_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Periodic_Thread1_step();
    break;

   case 1 :
    Periodic_Thread2_step();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void slexMulticoreSolverExample_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)slexMulticoreSolverExample_M, 0,
                sizeof(RT_MODEL_slexMulticoreSolverE_T));
  (slexMulticoreSolverExample_M)->Timing.TaskCounters.cLimit[0] = 1;
  (slexMulticoreSolverExample_M)->Timing.TaskCounters.cLimit[1] = 1;
  rtmSetTPtr(slexMulticoreSolverExample_M,
             &slexMulticoreSolverExample_M->Timing.tArray[0]);
  slexMulticoreSolverExample_M->Timing.stepSize0 = 0.1;

  /* block I/O */
  (void) memset(((void *) &slexMulticoreSolverExample_B), 0,
                sizeof(B_slexMulticoreSolverExample_T));

  /* states (dwork) */
  (void) memset((void *)&slexMulticoreSolverExample_DW, 0,
                sizeof(DW_slexMulticoreSolverExample_T));

  {
    /* user code (registration function declaration) */
    int_T tIdx;

    /* initialize continuous states */
    (void) memset((void *)&slexMulticoreSolverExample_X, 0,
                  sizeof(X_slexMulticoreSolverExample_T));
    for (tIdx = 0; tIdx < 2; tIdx++) {
      task_M[tIdx] = &task_M_[tIdx];

      /* initialize real-time model */
      (void) memset((void *) task_M[tIdx], 0,
                    sizeof(RT_MODEL_slexMulticoreSolverE_T));
      task_M[tIdx]->Timing.TaskCounters.cLimit[0] = 1;
      task_M[tIdx]->Timing.TaskCounters.cLimit[1] = 1;
    }

    for (tIdx = 0; tIdx < 2; tIdx++) {
      {
        /* Setup solver object */
        rtsiSetSimTimeStepPtr(&task_M[tIdx]->solverInfo, &task_M[tIdx]
                              ->Timing.simTimeStep);
        rtsiSetTPtr(&task_M[tIdx]->solverInfo, &rtmGetTPtr(task_M[tIdx]));
        rtsiSetStepSizePtr(&task_M[tIdx]->solverInfo, &task_M[tIdx]
                           ->Timing.stepSize0);
        rtsiSetdXPtr(&task_M[tIdx]->solverInfo, &task_M[tIdx]->derivs);
        rtsiSetContStatesPtr(&task_M[tIdx]->solverInfo, (real_T **) &task_M[tIdx]
                             ->contStates);
        rtsiSetNumContStatesPtr(&task_M[tIdx]->solverInfo, &task_M[tIdx]
          ->Sizes.numContStates);
        rtsiSetErrorStatusPtr(&task_M[tIdx]->solverInfo, (&rtmGetErrorStatus
          (slexMulticoreSolverExample_M)));
        rtsiSetRTModelPtr(&task_M[tIdx]->solverInfo, task_M[tIdx]);
      }

      rtsiSetSimTimeStep(&task_M[tIdx]->solverInfo, MAJOR_TIME_STEP);
      rtsiSetSolverOutputComputed(&task_M[tIdx]->solverInfo, false);
      task_M[tIdx]->intgData.y = task_M[tIdx]->odeY;
      task_M[tIdx]->intgData.f[0] = task_M[tIdx]->odeF[0];
      task_M[tIdx]->intgData.f[1] = task_M[tIdx]->odeF[1];
      task_M[tIdx]->intgData.f[2] = task_M[tIdx]->odeF[2];
      rtsiSetSolverData(&task_M[tIdx]->solverInfo, (void *)&task_M[tIdx]
                        ->intgData);
      rtsiSetSolverName(&task_M[tIdx]->solverInfo,"ode3");
      rtmSetTPtr(task_M[tIdx], &task_M[tIdx]->Timing.tArray[0]);
      task_M[tIdx]->Timing.stepSize0 = 0.1;
    }

    task_M[0]->contStates = ((X_slexMulticoreSolverExample_T *)((real_T *)
      &slexMulticoreSolverExample_X + 0));
    task_M[1]->contStates = ((X_slexMulticoreSolverExample_T *)((real_T *)
      &slexMulticoreSolverExample_X + 1));
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model 1' */
  slexMulticoreSolverM_initialize(rtmGetErrorStatusPointer
    (slexMulticoreSolverExample_M), rtmGetStopRequestedPtr
    (slexMulticoreSolverExample_M), &(task_M[0]->solverInfo),
    &(slexMulticoreSolverExample_DW.Model1_InstanceData.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model 2' */
  slexMulticoreSolverM_initialize(rtmGetErrorStatusPointer
    (slexMulticoreSolverExample_M), rtmGetStopRequestedPtr
    (slexMulticoreSolverExample_M), &(task_M[1]->solverInfo),
    &(slexMulticoreSolverExample_DW.Model2_InstanceData.rtm));

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Inport1' */
  slexMulticoreSolverExample_DW.fr_buf_2 = 1;

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Outport1' incorporates:
   *  TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Inport1'
   */
  slexMulticoreSolverExample_DW.fw_buf_1 = 2;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[0] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel2Inport1_IC;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[1] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel2Inport1_IC;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel1Outport1_bu[2] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel2Inport1_IC;

  /* SystemInitialize for ModelReference: '<Root>/Model 1' */
  slexMulticoreSolverMdlref_Init(&(slexMulticoreSolverExample_X.Model1_CSTATE),
    slexMulticoreSolverExample_P.Model1_x0);

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Inport1' */
  slexMulticoreSolverExample_DW.fr_buf_1 = 1;

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtModel 2Outport1' incorporates:
   *  TaskTransBlk: '<Root>/TmpTaskTransAtModel 1Inport1'
   */
  slexMulticoreSolverExample_DW.fw_buf_2 = 2;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[0] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel1Inport1_IC;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[1] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel1Inport1_IC;
  slexMulticoreSolverExample_DW.TmpTaskTransAtModel2Outport1_bu[2] =
    slexMulticoreSolverExample_P.TmpTaskTransAtModel1Inport1_IC;

  /* SystemInitialize for ModelReference: '<Root>/Model 2' */
  slexMulticoreSolverMdlref_Init(&(slexMulticoreSolverExample_X.Model2_CSTATE),
    slexMulticoreSolverExample_P.Model2_x0);
}

/* Model terminate function */
void slexMulticoreSolverExample_terminate(void)
{
  /* (no terminate code required) */
}
