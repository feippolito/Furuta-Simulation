/*
 * Furuta_Control_mbed_data.c
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

#include "Furuta_Control_mbed.h"
#include "Furuta_Control_mbed_private.h"

/* Block parameters (auto storage) */
P_Furuta_Control_mbed_T Furuta_Control_mbed_P = {
  /*  Variable: K
   * Referenced by: '<S1>/Gain'
   */
  { -0.77021189638050025, -0.65535285630780027, -17.797165150121913,
    -2.3448896114022046 },
  12.0,                                /* Expression: 12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S3>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S4>/Constant'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S4>/2pi'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  12.0,                                /* Expression: 12
                                        * Referenced by: '<Root>/Constant'
                                        */
  24.0                                 /* Expression: 24
                                        * Referenced by: '<Root>/Constant1'
                                        */
};
