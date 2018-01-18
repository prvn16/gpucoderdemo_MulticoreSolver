/*
 * Code generation for system model 'slexMulticoreSolverMdlref'
 * For more details, see corresponding source file slexMulticoreSolverMdlref.c
 *
 */

#ifndef RTW_HEADER_slexMulticoreSolverMdlref_h_
#define RTW_HEADER_slexMulticoreSolverMdlref_h_
#include <string.h>
#ifndef slexMulticoreSolverMdlref_COMMON_INCLUDES_
# define slexMulticoreSolverMdlref_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* slexMulticoreSolverMdlref_COMMON_INCLUDES_ */

#include "slexMulticoreSolverMdlref_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Continuous states for model 'slexMulticoreSolverMdlref' */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X_slexMulticoreSolverMdlref_n_T;

/* State derivatives for model 'slexMulticoreSolverMdlref' */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot_slexMulticoreSolverMdl_n_T;

/* State Disabled for model 'slexMulticoreSolverMdlref' */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis_slexMulticoreSolverMdl_n_T;

/* Real-time Model Data Structure */
struct tag_RTM_slexMulticoreSolverMd_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

typedef struct {
  RT_MODEL_slexMulticoreSolverM_T rtm;
} MdlrefDW_slexMulticoreSolverM_T;

/* Model reference registration function */
extern void slexMulticoreSolverM_initialize(const char_T **rt_errorStatus,
  boolean_T *rt_stopRequested, RTWSolverInfo *rt_solverInfo,
  RT_MODEL_slexMulticoreSolverM_T *const slexMulticoreSolverMdlref_M);
extern void slexMulticoreSolverMdlref_Init(X_slexMulticoreSolverMdlref_n_T
  *localX, real_T rtp_x0);
extern void slexMulticoreSolverMdlref_Reset(X_slexMulticoreSolverMdlref_n_T
  *localX, real_T rtp_x0);
extern void slexMulticoreSolverMdlref_Deriv(const real_T *rtu_x,
  XDot_slexMulticoreSolverMdl_n_T *localXdot);
extern void slexMulticoreSolverMdlre_Update(void);
extern void slexMulticoreSolverMdlref(real_T *rty_Kx,
  X_slexMulticoreSolverMdlref_n_T *localX, real_T rtp_K);

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
 * '<Root>' : 'slexMulticoreSolverMdlref'
 */
#endif                                 /* RTW_HEADER_slexMulticoreSolverMdlref_h_ */
