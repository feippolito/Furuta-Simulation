/*
 * File: Furuta_Control_mbed.c
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

#include "Furuta_Control_mbed.h"
#define NumBitsPerChar                 8U

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

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
  rtb_Gain2 = rt_modd_snf(rtU.In1[2] + -3.1415926535897931, 6.2831853071795862) *
    57.295779513082323;

  /* If: '<Root>/If' */
  if ((rtb_Gain2 < 210.0) && (rtb_Gain2 > 150.0)) {
    /* Outputs for IfAction SubSystem: '<Root>/Feedback control' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/In1'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In1'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In2'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In3'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In4'
     */
    rtb_Gain2 = ((-0.77021189638050025 * rtU.In1[0] + -0.65535285630780027 *
                  rtU.In1[1]) + -17.797165150121913 * rtU.In1[2]) +
      -2.3448896114022046 * rtU.In1[3];

    /* Saturate: '<S1>/Saturation' incorporates:
     *  Gain: '<S1>/Gain'
     */
    if (rtb_Gain2 > 12.0) {
      rtb_Gain2 = 12.0;
    } else {
      if (rtb_Gain2 < -12.0) {
        rtb_Gain2 = -12.0;
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
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In3'
     */
    rtb_Gain2 = 0.4 * rtU.In1[2];

    /* Fcn: '<S3>/Fcn' */
    rtb_Gain2 *= rtb_Gain2;

    /* Abs: '<S3>/Abs' */
    rtb_Gain2 = fabs(rtb_Gain2);

    /* Product: '<S3>/Mut' incorporates:
     *  Inport: '<Root>/In1'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In3'
     *  SignalConversion: '<Root>/ConcatBufferAtVector Concatenate3In4'
     *  Trigonometry: '<S3>/Trigonometric Function'
     */
    u = cos(rtU.In1[2]) * rtU.In1[3];

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

    /* Product: '<S3>/Mut1' */
    rtb_Gain2 *= u;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Gain2 > 12.0) {
      rtb_Gain2 = 12.0;
    } else {
      if (rtb_Gain2 < -12.0) {
        rtb_Gain2 = -12.0;
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
  rtY.Out1 = (-rtb_Gain2 + 12.0) / 24.0;
}

/* Model initialize function */
void Furuta_Control_mbed_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
