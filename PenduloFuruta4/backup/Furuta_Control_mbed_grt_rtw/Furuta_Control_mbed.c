/*
 * Furuta_Control_mbed.c
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

/* External inputs (root inport signals with auto storage) */
ExtU_Furuta_Control_mbed_T Furuta_Control_mbed_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Furuta_Control_mbed_T Furuta_Control_mbed_Y;

/* Real-time model */
RT_MODEL_Furuta_Control_mbed_T Furuta_Control_mbed_M_;
RT_MODEL_Furuta_Control_mbed_T *const Furuta_Control_mbed_M =
  &Furuta_Control_mbed_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Model step function */
void Furuta_Control_mbed_step(void)
{
  real_T rtb_Gain2;
  real_T u;

  /* Gain: '<S2>/Gain2' incorporates:
   *  Constant: '<S4>/2pi'
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/In1'
   *  Math: '<S4>/Math Function'
   *  Sum: '<S4>/Add'
   */
  rtb_Gain2 = rt_modd_snf(Furuta_Control_mbed_U.In1 +
    Furuta_Control_mbed_P.Constant_Value, Furuta_Control_mbed_P.upi_Value) *
    Furuta_Control_mbed_P.Gain2_Gain;

  /* If: '<Root>/If' */
  if ((rtb_Gain2 < 210.0) && (rtb_Gain2 > 150.0)) {
    /* Outputs for IfAction SubSystem: '<Root>/Feedback control' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/In1'
     */
    rtb_Gain2 = ((Furuta_Control_mbed_P.K[0] * Furuta_Control_mbed_U.In1 +
                  Furuta_Control_mbed_P.K[1] * Furuta_Control_mbed_U.In1) +
                 Furuta_Control_mbed_P.K[2] * Furuta_Control_mbed_U.In1) +
      Furuta_Control_mbed_P.K[3] * Furuta_Control_mbed_U.In1;

    /* Saturate: '<S1>/Saturation' incorporates:
     *  Gain: '<S1>/Gain'
     */
    if (rtb_Gain2 > Furuta_Control_mbed_P.Saturation_UpperSat) {
      rtb_Gain2 = Furuta_Control_mbed_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain2 < Furuta_Control_mbed_P.Saturation_LowerSat) {
        rtb_Gain2 = Furuta_Control_mbed_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/Saturation' */
    /* End of Outputs for SubSystem: '<Root>/Feedback control' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Swing Up' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Gain: '<S3>/Gain' incorporates:
     *  Inport: '<Root>/In1'
     */
    rtb_Gain2 = Furuta_Control_mbed_P.Gain_Gain * Furuta_Control_mbed_U.In1;

    /* Fcn: '<S3>/Fcn' */
    rtb_Gain2 *= rtb_Gain2;

    /* Abs: '<S3>/Abs' */
    rtb_Gain2 = fabs(rtb_Gain2);

    /* Product: '<S3>/Mut' incorporates:
     *  Inport: '<Root>/In1'
     *  Trigonometry: '<S3>/Trigonometric Function'
     */
    u = cos(Furuta_Control_mbed_U.In1) * Furuta_Control_mbed_U.In1;

    /* Signum: '<S3>/Sign' */
    if (u < 0.0) {
      u = -1.0;
    } else if (u > 0.0) {
      u = 1.0;
    } else {
      if (u == 0.0) {
        u = 0.0;
      }
    }

    /* End of Signum: '<S3>/Sign' */

    /* Gain: '<S3>/Gain1' incorporates:
     *  Product: '<S3>/Mut1'
     */
    rtb_Gain2 = u * rtb_Gain2 * Furuta_Control_mbed_P.Gain1_Gain;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Gain2 > Furuta_Control_mbed_P.Saturation_UpperSat_c) {
      rtb_Gain2 = Furuta_Control_mbed_P.Saturation_UpperSat_c;
    } else {
      if (rtb_Gain2 < Furuta_Control_mbed_P.Saturation_LowerSat_b) {
        rtb_Gain2 = Furuta_Control_mbed_P.Saturation_LowerSat_b;
      }
    }

    /* End of Saturate: '<S3>/Saturation' */
    /* End of Outputs for SubSystem: '<Root>/Swing Up' */
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Gain: '<Root>/Gain'
   *  Product: '<Root>/Divide'
   *  Sum: '<Root>/Sum'
   */
  Furuta_Control_mbed_Y.Out1 = (Furuta_Control_mbed_P.Gain_Gain_a * rtb_Gain2 +
    Furuta_Control_mbed_P.Constant_Value_d) /
    Furuta_Control_mbed_P.Constant1_Value;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Furuta_Control_mbed_M->rtwLogInfo,
                      (&Furuta_Control_mbed_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Furuta_Control_mbed_M)!=-1) &&
        !((rtmGetTFinal(Furuta_Control_mbed_M)-
           Furuta_Control_mbed_M->Timing.taskTime0) >
          Furuta_Control_mbed_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Furuta_Control_mbed_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Furuta_Control_mbed_M->Timing.clockTick0)) {
    ++Furuta_Control_mbed_M->Timing.clockTickH0;
  }

  Furuta_Control_mbed_M->Timing.taskTime0 =
    Furuta_Control_mbed_M->Timing.clockTick0 *
    Furuta_Control_mbed_M->Timing.stepSize0 +
    Furuta_Control_mbed_M->Timing.clockTickH0 *
    Furuta_Control_mbed_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Furuta_Control_mbed_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Furuta_Control_mbed_M, 0,
                sizeof(RT_MODEL_Furuta_Control_mbed_T));
  rtmSetTFinal(Furuta_Control_mbed_M, 3.0);
  Furuta_Control_mbed_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Furuta_Control_mbed_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Furuta_Control_mbed_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Furuta_Control_mbed_M->rtwLogInfo, (NULL));
    rtliSetLogT(Furuta_Control_mbed_M->rtwLogInfo, "tout");
    rtliSetLogX(Furuta_Control_mbed_M->rtwLogInfo, "");
    rtliSetLogXFinal(Furuta_Control_mbed_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Furuta_Control_mbed_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Furuta_Control_mbed_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Furuta_Control_mbed_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Furuta_Control_mbed_M->rtwLogInfo, 1);
    rtliSetLogY(Furuta_Control_mbed_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Furuta_Control_mbed_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Furuta_Control_mbed_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  Furuta_Control_mbed_U.In1 = 0.0;

  /* external outputs */
  Furuta_Control_mbed_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Furuta_Control_mbed_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Furuta_Control_mbed_M), Furuta_Control_mbed_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Furuta_Control_mbed_M)));
}

/* Model terminate function */
void Furuta_Control_mbed_terminate(void)
{
  /* (no terminate code required) */
}
