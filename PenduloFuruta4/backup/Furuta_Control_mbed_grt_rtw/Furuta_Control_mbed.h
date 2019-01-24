/*
 * Furuta_Control_mbed.h
 *
 * Code generation for model "Furuta_Control_mbed".
 *
 * Model version              : 1.22
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Oct 17 19:32:09 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Furuta_Control_mbed_h_
#define RTW_HEADER_Furuta_Control_mbed_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Furuta_Control_mbed_COMMON_INCLUDES_
# define Furuta_Control_mbed_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Furuta_Control_mbed_COMMON_INCLUDES_ */

#include "Furuta_Control_mbed_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_Furuta_Control_mbed_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_Furuta_Control_mbed_T;

/* Parameters (auto storage) */
struct P_Furuta_Control_mbed_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.4
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 12
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -12
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: -pi
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T upi_Value;                    /* Expression: 2*pi
                                        * Referenced by: '<S4>/2pi'
                                        */
  real_T Gain2_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: 12
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 24
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Furuta_Control_mbed_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Furuta_Control_mbed_T Furuta_Control_mbed_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Furuta_Control_mbed_T Furuta_Control_mbed_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Furuta_Control_mbed_T Furuta_Control_mbed_Y;

/* Model entry point functions */
extern void Furuta_Control_mbed_initialize(void);
extern void Furuta_Control_mbed_step(void);
extern void Furuta_Control_mbed_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Furuta_Control_mbed_T *const Furuta_Control_mbed_M;

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
 * '<Root>' : 'Furuta_Control_mbed'
 * '<S1>'   : 'Furuta_Control_mbed/Feedback control'
 * '<S2>'   : 'Furuta_Control_mbed/Rad2Grad1'
 * '<S3>'   : 'Furuta_Control_mbed/Swing Up'
 * '<S4>'   : 'Furuta_Control_mbed/Rad2Grad1/0-2pi'
 */
#endif                                 /* RTW_HEADER_Furuta_Control_mbed_h_ */
