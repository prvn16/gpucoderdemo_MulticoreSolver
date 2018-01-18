/*
 * Code generation for system model 'slexMulticoreSolverMdlref'
 *
 * Model                      : slexMulticoreSolverMdlref
 * Model version              : 1.4
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jan 17 08:51:53 2018
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "slexMulticoreSolverMdlref.h"
#include "slexMulticoreSolverMdlref_private.h"

/* System initialize for referenced model: 'slexMulticoreSolverMdlref' */
void slexMulticoreSolverMdlref_Init(X_slexMulticoreSolverMdlref_n_T *localX,
  real_T rtp_x0)
{
  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  localX->Integrator_CSTATE = rtp_x0;
}

/* System reset for referenced model: 'slexMulticoreSolverMdlref' */
void slexMulticoreSolverMdlref_Reset(X_slexMulticoreSolverMdlref_n_T *localX,
  real_T rtp_x0)
{
  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  localX->Integrator_CSTATE = rtp_x0;
}

/* Outputs for referenced model: 'slexMulticoreSolverMdlref' */
void slexMulticoreSolverMdlref(real_T *rty_Kx, X_slexMulticoreSolverMdlref_n_T
  *localX, real_T rtp_K)
{
  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  *rty_Kx = rtp_K * localX->Integrator_CSTATE;
}

/* Update for referenced model: 'slexMulticoreSolverMdlref' */
void slexMulticoreSolverMdlre_Update(void)
{
}

/* Derivatives for referenced model: 'slexMulticoreSolverMdlref' */
void slexMulticoreSolverMdlref_Deriv(const real_T *rtu_x,
  XDot_slexMulticoreSolverMdl_n_T *localXdot)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  localXdot->Integrator_CSTATE = *rtu_x;
}

/* Model initialize function */
void slexMulticoreSolverM_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo,
  RT_MODEL_slexMulticoreSolverM_T *const slexMulticoreSolverMdlref_M)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)slexMulticoreSolverMdlref_M, 0,
                sizeof(RT_MODEL_slexMulticoreSolverM_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(slexMulticoreSolverMdlref_M, rt_errorStatus);

  /* initialize stop requested flag */
  rtmSetStopRequestedPtr(slexMulticoreSolverMdlref_M, rt_stopRequested);

  /* initialize RTWSolverInfo */
  slexMulticoreSolverMdlref_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(slexMulticoreSolverMdlref_M, rtsiGetSimTimeStepPtr
    (slexMulticoreSolverMdlref_M->solverInfo));
  slexMulticoreSolverMdlref_M->Timing.stepSize0 = (rtsiGetStepSize
    (slexMulticoreSolverMdlref_M->solverInfo));
}
