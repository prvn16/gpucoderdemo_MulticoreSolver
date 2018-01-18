/*
 * slexMulticoreSolverExample.h
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

#ifndef RTW_HEADER_slexMulticoreSolverExample_h_
#define RTW_HEADER_slexMulticoreSolverExample_h_
#include <string.h>
#include <stddef.h>
#ifndef slexMulticoreSolverExample_COMMON_INCLUDES_
# define slexMulticoreSolverExample_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* slexMulticoreSolverExample_COMMON_INCLUDES_ */

#include "slexMulticoreSolverExample_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "slexMulticoreSolverMdlref.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T x2;                           /* '<Root>/Model 2' */
  real_T x1;                           /* '<Root>/Model 1' */
  real_T x1_m;                         /* '<Root>/Model 1' */
  real_T x2_l;                         /* '<Root>/Model 2' */
} B_slexMulticoreSolverExample_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T tr_buf_2;                     /* synthesized block */
  real_T TmpTaskTransAtModel1Outport1_bu[4];/* synthesized block */
  real_T tr_buf_1;                     /* synthesized block */
  real_T TmpTaskTransAtModel2Outport1_bu[4];/* synthesized block */
  int_T fr_buf_2;                      /* synthesized block */
  int_T fw_buf_1;                      /* synthesized block */
  int_T fr_buf_1;                      /* synthesized block */
  int_T fw_buf_2;                      /* synthesized block */
  MdlrefDW_slexMulticoreSolverM_T Model1_InstanceData;/* '<Root>/Model 1' */
  MdlrefDW_slexMulticoreSolverM_T Model2_InstanceData;/* '<Root>/Model 2' */
} DW_slexMulticoreSolverExample_T;

/* Continuous states (auto storage) */
typedef struct {
  X_slexMulticoreSolverMdlref_n_T Model1_CSTATE;/* '<Root>/Model 1' */
  X_slexMulticoreSolverMdlref_n_T Model2_CSTATE;/* '<Root>/Model 2' */
} X_slexMulticoreSolverExample_T;

/* State derivatives for Periodic_Thread1 */
typedef struct {
  XDot_slexMulticoreSolverMdl_n_T Model1_CSTATE;/* '<Root>/Model 1' */
} XDot_slexMulticoreSolverExamp_T_Periodic_Thread1;

/* State derivatives for Periodic_Thread2 */
typedef struct {
  XDot_slexMulticoreSolverMdl_n_T Model2_CSTATE;/* '<Root>/Model 2' */
} XDot_slexMulticoreSolverExamp_T_Periodic_Thread2;

/* State disabled  */
typedef struct {
  XDis_slexMulticoreSolverMdl_n_T Model1_CSTATE;/* '<Root>/Model 1' */
  XDis_slexMulticoreSolverMdl_n_T Model2_CSTATE;/* '<Root>/Model 2' */
} XDis_slexMulticoreSolverExamp_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_slexMulticoreSolverExample_T_ {
  real_T TmpTaskTransAtModel2Inport1_IC;/* Expression: 1
                                         * Referenced by: synthesized block
                                         */
  real_T Model2_K;                     /* Expression: -1
                                        * Referenced by: '<Root>/Model 2'
                                        */
  real_T Model2_x0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Model 2'
                                        */
  real_T TmpTaskTransAtModel1Inport1_IC;/* Expression: 0
                                         * Referenced by: synthesized block
                                         */
  real_T Model1_K;                     /* Expression: 1
                                        * Referenced by: '<Root>/Model 1'
                                        */
  real_T Model1_x0;                    /* Expression: 1
                                        * Referenced by: '<Root>/Model 1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_slexMulticoreSolverEx_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_slexMulticoreSolverExample_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint32_T TID[2];
      uint32_T cLimit[2];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_slexMulticoreSolverExample_T slexMulticoreSolverExample_P;

/* Block signals (auto storage) */
extern B_slexMulticoreSolverExample_T slexMulticoreSolverExample_B;

/* Block states (auto storage) */
extern DW_slexMulticoreSolverExample_T slexMulticoreSolverExample_DW;
extern void slexMulticoreSolverExample_step(int_T tid);
extern void AdvanceTaskCounters(void);

/* Model entry point functions */
extern void slexMulticoreSolverExample_initialize(void);
extern void slexMulticoreSolverExample_terminate(void);

/* Real-time Model object */
extern RT_MODEL_slexMulticoreSolverE_T *const slexMulticoreSolverExample_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'slexMulticoreSolverExample'
 */
#endif                                 /* RTW_HEADER_slexMulticoreSolverExample_h_ */
