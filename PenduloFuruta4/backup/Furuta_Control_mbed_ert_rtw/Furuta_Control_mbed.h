/*
 * File: Furuta_Control_mbed.h
 *
 * Code generated for Simulink model 'Furuta_Control_mbed'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Wed Oct 31 16:03:04 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Furuta_Control_mbed_h_
#define RTW_HEADER_Furuta_Control_mbed_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef Furuta_Control_mbed_COMMON_INCLUDES_
# define Furuta_Control_mbed_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Furuta_Control_mbed_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1[4];                       /* '<Root>/In1' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Furuta_Control_mbed_initialize(void);
extern void Furuta_Control_mbed_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Gain1' : Eliminated nontunable gain of 1
 */

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
