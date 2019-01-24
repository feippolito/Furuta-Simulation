/* Include files */

#include "sharedTrackingLibrary_sfun.h"
#include "c1_sharedTrackingLibrary.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sharedTrackingLibrary_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[10] = { "MeasurementFcn", "pM",
  "nargin", "nargout", "x", "P", "yMeas", "R", "xNew", "PNew" };

/* Function Declarations */
static void initialize_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initialize_params_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void enable_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void disable_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void set_sim_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void sf_gateway_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void mdl_start_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static void initSimStructsc1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance);
static real_T c1_Furuta_Measurement_invoke
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, real_T c1_b_x[2]);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_PNew, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_xNew, const char_T *c1_identifier, real_T
  c1_y[2]);
static void c1_d_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_localLowerCholesky(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c1_A[4], real_T c1_b_A[4], int32_T *c1_info);
static void c1_check_forloop_overflow_error
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, boolean_T
   c1_overflow);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static c1_s9TzESsgAwpfTADJEKW7kTE c1_g_emlrt_marshallIn
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_h_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[18]);
static boolean_T c1_i_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_j_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_sharedTrackingLibrary, const
  char_T *c1_identifier);
static uint8_T c1_k_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static int32_T c1_b_localLowerCholesky(SFc1_sharedTrackingLibraryInstanceStruct *
  chartInstance, real_T c1_A[4]);
static void init_dsm_address_info(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_sharedTrackingLibrary(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_sharedTrackingLibrary = 0U;
}

static void initialize_params_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c1_m0 = NULL;
  static const char * c1_fieldNames[5] = { "FcnName", "HasAdditiveNoise",
    "Alpha", "Beta", "Kappa" };

  const mxArray *c1_mxField;
  c1_s9TzESsgAwpfTADJEKW7kTE c1_r0;
  c1_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c1_m0, 5, c1_fieldNames, "s9TzESsgAwpfTADJEKW7kTE");
  c1_mxField = sf_mex_getfield(c1_m0, "FcnName", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c1_mxField), c1_r0.FcnName, 1, 10, 0U, 1,
                      0U, 2, 1, 18);
  c1_mxField = sf_mex_getfield(c1_m0, "HasAdditiveNoise", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c1_mxField), &c1_r0.HasAdditiveNoise, 1,
                      11, 0U, 0, 0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Alpha", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c1_mxField), &c1_r0.Alpha, 1, 0, 0U, 0,
                      0U, 0);
  c1_mxField = sf_mex_getfield(c1_m0, "Beta", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c1_mxField), &c1_r0.Beta, 1, 0, 0U, 0, 0U,
                      0);
  c1_mxField = sf_mex_getfield(c1_m0, "Kappa", "pM", 0);
  sf_mex_import_named("pM", sf_mex_dup(c1_mxField), &c1_r0.Kappa, 1, 0, 0U, 0,
                      0U, 0);
  sf_mex_destroy(&c1_m0);
  chartInstance->c1_pM = c1_r0;
}

static void enable_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(3, 1), false);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", *chartInstance->c1_PNew, 0, 0U, 1U,
    0U, 2, 2, 2), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", *chartInstance->c1_xNew, 0, 0U, 1U,
    0U, 1, 2), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_sharedTrackingLibrary;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i0;
  real_T c1_dv1[2];
  int32_T c1_i1;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("PNew", c1_u, 0)),
                      "PNew", c1_dv0);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    (*chartInstance->c1_PNew)[c1_i0] = c1_dv0[c1_i0];
  }

  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("xNew", c1_u, 1)),
                        "xNew", c1_dv1);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    (*chartInstance->c1_xNew)[c1_i1] = c1_dv1[c1_i1];
  }

  chartInstance->c1_is_active_c1_sharedTrackingLibrary = c1_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c1_sharedTrackingLibrary", c1_u, 2)),
     "is_active_c1_sharedTrackingLibrary");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_sharedTrackingLibrary(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T c1_b_x[2];
  real_T c1_b_yMeas;
  real_T c1_b_P[4];
  real_T c1_b_R;
  uint32_T c1_debug_family_var_map[10];
  c1_s9TzESsgAwpfTADJEKW7kTE c1_b_pM;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 2.0;
  real_T c1_b_xNew[2];
  real_T c1_b_PNew[4];
  static c1_s9TzESsgAwpfTADJEKW7kTE c1_r1 = { { 'F', 'u', 'r', 'u', 't', 'a',
      '_', 'M', 'e', 'a', 's', 'u', 'r', 'e', 'm', 'e', 'n', 't' },/* FcnName */
    true,                              /* HasAdditiveNoise */
    1.0,                               /* Alpha */
    2.0,                               /* Beta */
    0.0                                /* Kappa */
  };

  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_z;
  real_T c1_zcov;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_X1[2];
  int32_T c1_i10;
  real_T c1_c_P[4];
  int32_T c1_p;
  real_T c1_sqrtP[4];
  const mxArray *c1_y = NULL;
  static char_T c1_cv0[59] = { 's', 'h', 'a', 'r', 'e', 'd', '_', 't', 'r', 'a',
    'c', 'k', 'i', 'n', 'g', ':', 'U', 'n', 's', 'c', 'e', 'n', 't', 'e', 'd',
    'K', 'a', 'l', 'm', 'a', 'n', 'F', 'i', 'l', 't', 'e', 'r', ':', 'S', 't',
    'a', 't', 'e', 'C', 'o', 'v', 'a', 'r', 'i', 'a', 'n', 'c', 'e', 'N', 'o',
    't', 'P', 'S', 'D' };

  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_X2[8];
  int32_T c1_kkC;
  int32_T c1_i17;
  int32_T c1_kk;
  real_T c1_b_kkC;
  int32_T c1_c_kkC;
  int32_T c1_d_kkC;
  int32_T c1_i18;
  real_T c1_b_kk;
  int32_T c1_i19;
  int32_T c1_c_kk;
  int32_T c1_i20;
  real_T c1_gain[2];
  int32_T c1_i21;
  real_T c1_b_X2[2];
  real_T c1_tempY;
  real_T c1_Y1;
  real_T c1_Ymean;
  int32_T c1_d_kk;
  real_T c1_Y2[4];
  real_T c1_e_kk;
  int32_T c1_f_kk;
  int32_T c1_i22;
  real_T c1_b_y;
  real_T c1_b[4];
  int32_T c1_k;
  real_T c1_Pyy;
  int32_T c1_g_kk;
  int32_T c1_i23;
  int32_T c1_h_kk;
  int32_T c1_i_kk;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_c_X2[2];
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_b_Pyy;
  real_T c1_zEstimated;
  real_T c1_zMeasured;
  real_T c1_c_Pyy;
  real_T c1_B;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_i30;
  real_T c1_b_b;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_e_y[2];
  real_T c1_c_b;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_d_b[2];
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_R, 3U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_yMeas, 2U, 1U, 0U,
                        chartInstance->c1_sfEvent, false);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_P)[c1_i2], 1U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_x)[c1_i3], 0U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *chartInstance->c1_yMeas;
  c1_b_hoistedGlobal = *chartInstance->c1_R;
  for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
    c1_b_x[c1_i4] = (*chartInstance->c1_x)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    c1_b_P[c1_i5] = (*chartInstance->c1_P)[c1_i5];
  }

  c1_b_yMeas = c1_hoistedGlobal;
  c1_b_R = c1_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(NULL, 0U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_pM, 1U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_x, 4U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_b_P, 5U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_yMeas, 6U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_R, 7U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_xNew, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_b_PNew, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  c1_b_pM = c1_r1;
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_b_xNew[c1_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    c1_b_PNew[c1_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_z = c1_b_yMeas;
  c1_zcov = c1_b_R;
  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_X1[c1_i8] = c1_b_x[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_c_P[c1_i9] = c1_b_P[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_sqrtP[c1_i10] = c1_c_P[c1_i10];
  }

  c1_p = c1_b_localLowerCholesky(chartInstance, c1_sqrtP);
  if (!((real_T)c1_p > 0.0)) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv0, 10, 0U, 1U, 0U, 2, 1, 59),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 1U, 14, c1_y));
  }

  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    c1_sqrtP[c1_i11] *= 1.4142135623730951;
  }

  c1_i12 = 0;
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
      c1_X2[c1_i15 + c1_i12] = c1_sqrtP[c1_i15 + c1_i12];
    }

    c1_i12 += 2;
  }

  c1_i14 = 0;
  for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
    for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
      c1_X2[(c1_i17 + c1_i14) + 4] = -c1_sqrtP[c1_i17 + c1_i14];
    }

    c1_i14 += 2;
  }

  for (c1_kkC = 0; c1_kkC < 4; c1_kkC++) {
    c1_b_kkC = 1.0 + (real_T)c1_kkC;
    c1_c_kkC = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_b_kkC), 1, 4) - 1;
    c1_d_kkC = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_b_kkC), 1, 4) - 1;
    for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
      c1_b_X2[c1_i19] = c1_X2[c1_i19 + (c1_c_kkC << 1)] + c1_X1[c1_i19];
    }

    for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
      c1_X2[c1_i21 + (c1_d_kkC << 1)] = c1_b_X2[c1_i21];
    }
  }

  for (c1_kk = 0; c1_kk < 4; c1_kk++) {
    c1_b_kk = 1.0 + (real_T)c1_kk;
    c1_c_kk = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_b_kk), 1, 4) - 1;
    for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
      c1_gain[c1_i20] = c1_X2[c1_i20 + (c1_c_kk << 1)];
    }

    CV_EML_FCN(0, 1);
    c1_tempY = c1_Furuta_Measurement_invoke(chartInstance, c1_gain);
    c1_Y2[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_b_kk), 1, 4) - 1] = c1_tempY;
  }

  for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
    c1_gain[c1_i18] = c1_X1[c1_i18];
  }

  CV_EML_FCN(0, 1);
  c1_tempY = c1_Furuta_Measurement_invoke(chartInstance, c1_gain);
  c1_Y1 = c1_tempY;
  c1_Ymean = c1_Y1 * 0.0;
  for (c1_d_kk = 0; c1_d_kk < 4; c1_d_kk++) {
    c1_e_kk = 1.0 + (real_T)c1_d_kk;
    c1_Ymean += c1_Y2[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_e_kk), 1, 4) - 1] * 0.25;
  }

  c1_Y1 -= c1_Ymean;
  for (c1_f_kk = 0; c1_f_kk < 4; c1_f_kk++) {
    c1_e_kk = 1.0 + (real_T)c1_f_kk;
    c1_Y2[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_e_kk), 1, 4) - 1] =
      c1_Y2[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_e_kk), 1, 4) - 1] - c1_Ymean;
  }

  for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
    c1_b[c1_i22] = c1_Y2[c1_i22];
  }

  c1_b_y = 0.0;
  for (c1_k = 0; c1_k + 1 < 5; c1_k++) {
    c1_b_y += c1_Y2[c1_k] * c1_b[c1_k];
  }

  c1_Pyy = 2.0 * (c1_Y1 * c1_Y1) + 0.25 * c1_b_y;
  for (c1_g_kk = 0; c1_g_kk < 4; c1_g_kk++) {
    c1_e_kk = 1.0 + (real_T)c1_g_kk;
    c1_h_kk = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_e_kk), 1, 4) - 1;
    c1_i_kk = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 187, 175, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 187U, 175U, c1_e_kk), 1, 4) - 1;
    for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
      c1_c_X2[c1_i25] = c1_X2[c1_i25 + (c1_h_kk << 1)] - c1_X1[c1_i25];
    }

    for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
      c1_X2[c1_i27 + (c1_i_kk << 1)] = c1_c_X2[c1_i27];
    }
  }

  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_b[c1_i23] = c1_Y2[c1_i23];
  }

  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_gain[c1_i24] = 0.0;
    c1_i28 = 0;
    for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
      c1_gain[c1_i24] += c1_X2[c1_i28 + c1_i24] * c1_b[c1_i29];
      c1_i28 += 2;
    }
  }

  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_gain[c1_i26] *= 0.25;
  }

  c1_b_Pyy = c1_Pyy + c1_zcov;
  c1_zEstimated = c1_Ymean;
  c1_zMeasured = c1_z;
  c1_c_Pyy = c1_b_Pyy;
  c1_B = c1_c_Pyy;
  c1_c_y = c1_B;
  c1_d_y = c1_c_y;
  for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
    c1_gain[c1_i30] /= c1_d_y;
  }

  c1_b_b = c1_zMeasured - c1_zEstimated;
  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    c1_e_y[c1_i31] = c1_gain[c1_i31] * c1_b_b;
  }

  for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
    c1_X1[c1_i32] += c1_e_y[c1_i32];
  }

  c1_c_b = c1_c_Pyy;
  for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
    c1_e_y[c1_i33] = c1_gain[c1_i33] * c1_c_b;
  }

  for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
    c1_d_b[c1_i34] = c1_gain[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
    c1_i37 = 0;
    for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
      c1_sqrtP[c1_i37 + c1_i35] = c1_e_y[c1_i35] * c1_d_b[c1_i38];
      c1_i37 += 2;
    }
  }

  for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
    c1_c_P[c1_i36] -= c1_sqrtP[c1_i36];
  }

  for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
    c1_b_xNew[c1_i39] = c1_X1[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 4; c1_i40++) {
    c1_b_PNew[c1_i40] = c1_c_P[c1_i40];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
    (*chartInstance->c1_xNew)[c1_i41] = c1_b_xNew[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    (*chartInstance->c1_PNew)[c1_i42] = c1_b_PNew[c1_i42];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_sharedTrackingLibraryMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_xNew)[c1_i43], 4U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }

  for (c1_i44 = 0; c1_i44 < 4; c1_i44++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c1_PNew)[c1_i44], 5U, 1U, 0U,
                          chartInstance->c1_sfEvent, false);
  }
}

static void mdl_start_c1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc1_sharedTrackingLibrary
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c1_Furuta_Measurement_invoke
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, real_T c1_b_x[2])
{
  real_T c1_y_dTheta;
  _ssFcnCallExecArgInfo c1_args[2];
  c1_args[0U].dataPtr = (void *)c1_b_x;
  c1_args[1U].dataPtr = (void *)&c1_y_dTheta;
  slcsInvokeSimulinkFunction(chartInstance->S, "Furuta_Measurement", &c1_args[0U]);
  return c1_y_dTheta;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i45;
  int32_T c1_i46;
  const mxArray *c1_y = NULL;
  int32_T c1_i47;
  real_T c1_u[4];
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_i45 = 0;
  for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
    for (c1_i47 = 0; c1_i47 < 2; c1_i47++) {
      c1_u[c1_i47 + c1_i45] = (*(real_T (*)[4])c1_inData)[c1_i47 + c1_i45];
    }

    c1_i45 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_PNew, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_PNew), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_PNew);
}

static void c1_b_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv2[4];
  int32_T c1_i48;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_y[c1_i48] = c1_dv2[c1_i48];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_PNew;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_b_PNew = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_PNew), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_PNew);
  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 2; c1_i51++) {
      (*(real_T (*)[4])c1_outData)[c1_i51 + c1_i49] = c1_y[c1_i51 + c1_i49];
    }

    c1_i49 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_i52;
  const mxArray *c1_y = NULL;
  real_T c1_u[2];
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  for (c1_i52 = 0; c1_i52 < 2; c1_i52++) {
    c1_u[c1_i52] = (*(real_T (*)[2])c1_inData)[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_xNew, const char_T *c1_identifier, real_T
  c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_xNew), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_xNew);
}

static void c1_d_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i53;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
    c1_y[c1_i53] = c1_dv3[c1_i53];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_xNew;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i54;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_b_xNew = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_xNew), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_xNew);
  for (c1_i54 = 0; c1_i54 < 2; c1_i54++) {
    (*(real_T (*)[2])c1_outData)[c1_i54] = c1_y[c1_i54];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_s9TzESsgAwpfTADJEKW7kTE c1_u;
  const mxArray *c1_y = NULL;
  int32_T c1_i55;
  const mxArray *c1_b_y = NULL;
  char_T c1_b_u[18];
  boolean_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_s9TzESsgAwpfTADJEKW7kTE *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i55 = 0; c1_i55 < 18; c1_i55++) {
    c1_b_u[c1_i55] = c1_u.FcnName[c1_i55];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 18),
                false);
  sf_mex_addfield(c1_y, c1_b_y, "FcnName", "FcnName", 0);
  c1_c_u = c1_u.HasAdditiveNoise;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_c_y, "HasAdditiveNoise", "HasAdditiveNoise", 0);
  c1_d_u = c1_u.Alpha;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_d_y, "Alpha", "Alpha", 0);
  c1_e_u = c1_u.Beta;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_e_y, "Beta", "Beta", 0);
  c1_f_u = c1_u.Kappa;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_f_y, "Kappa", "Kappa", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  const mxArray *c1_y = NULL;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  (void)c1_inData;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_sharedTrackingLibrary_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static void c1_localLowerCholesky(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, real_T c1_A[4], real_T c1_b_A[4], int32_T *c1_info)
{
  int32_T c1_i56;
  for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
    c1_b_A[c1_i56] = c1_A[c1_i56];
  }

  *c1_info = c1_b_localLowerCholesky(chartInstance, c1_b_A);
}

static void c1_check_forloop_overflow_error
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  const mxArray *c1_y = NULL;
  static char_T c1_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c1_b_y = NULL;
  static char_T c1_cv2[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  if (!c1_overflow) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_cv1, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_cv2, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c1_y, 14, c1_b_y));
  }
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i57;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i57, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i57;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static c1_s9TzESsgAwpfTADJEKW7kTE c1_g_emlrt_marshallIn
  (SFc1_sharedTrackingLibraryInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_s9TzESsgAwpfTADJEKW7kTE c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[5] = { "FcnName", "HasAdditiveNoise",
    "Alpha", "Beta", "Kappa" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_u, 5, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "FcnName";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "FcnName", "FcnName", 0)), &c1_thisId, c1_y.FcnName);
  c1_thisId.fIdentifier = "HasAdditiveNoise";
  c1_y.HasAdditiveNoise = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_u, "HasAdditiveNoise", "HasAdditiveNoise", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "Alpha";
  c1_y.Alpha = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Alpha", "Alpha", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Beta";
  c1_y.Beta = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Beta", "Beta", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Kappa";
  c1_y.Kappa = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Kappa", "Kappa", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  char_T c1_y[18])
{
  char_T c1_cv3[18];
  int32_T c1_i58;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                18);
  for (c1_i58 = 0; c1_i58 < 18; c1_i58++) {
    c1_y[c1_i58] = c1_cv3[c1_i58];
  }

  sf_mex_destroy(&c1_u);
}

static boolean_T c1_i_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_pM;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_s9TzESsgAwpfTADJEKW7kTE c1_y;
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)chartInstanceVoid;
  c1_b_pM = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_pM), &c1_thisId);
  sf_mex_destroy(&c1_b_pM);
  *(c1_s9TzESsgAwpfTADJEKW7kTE *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_sharedTrackingLibrary, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_sharedTrackingLibrary), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_sharedTrackingLibrary);
  return c1_y;
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static int32_T c1_b_localLowerCholesky(SFc1_sharedTrackingLibraryInstanceStruct *
  chartInstance, real_T c1_A[4])
{
  int32_T c1_info;
  int32_T c1_b_info;
  int32_T c1_j;
  int32_T c1_a;
  int32_T c1_c_info;
  int32_T c1_jm1;
  int32_T c1_b_a;
  int32_T c1_c_a;
  int32_T c1_c;
  int32_T c1_a1;
  int32_T c1_d_a;
  boolean_T c1_p;
  int32_T c1_b;
  int32_T c1_jj;
  int32_T c1_jmax;
  int32_T c1_n;
  int32_T c1_ix0;
  int32_T c1_b_b;
  int32_T c1_iy0;
  int32_T c1_c_b;
  int32_T c1_b_n;
  boolean_T c1_overflow;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_c_n;
  int32_T c1_kkC;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_d_n;
  int32_T c1_e_a;
  int32_T c1_d_ix0;
  int32_T c1_i59;
  int32_T c1_d_iy0;
  int32_T c1_d_b;
  real_T c1_d;
  int32_T c1_e_b;
  boolean_T c1_b_overflow;
  int32_T c1_ix;
  int32_T c1_iy;
  real_T c1_ajj;
  int32_T c1_f_b;
  int32_T c1_kkR;
  int32_T c1_g_b;
  boolean_T c1_c_overflow;
  int32_T c1_h_b;
  int32_T c1_k;
  int32_T c1_nmj;
  int32_T c1_f_a;
  int32_T c1_jp1;
  int32_T c1_g_a;
  int32_T c1_h_a;
  int32_T c1_jp1j;
  int32_T c1_i_b;
  int32_T c1_i_a;
  int32_T c1_j_b;
  boolean_T c1_d_overflow;
  int32_T c1_m;
  int32_T c1_e_n;
  int32_T c1_ia0;
  int32_T c1_e_ix0;
  int32_T c1_e_iy0;
  int32_T c1_b_m;
  int32_T c1_f_n;
  int32_T c1_k_b;
  real_T c1_alpha1;
  int32_T c1_l_b;
  int32_T c1_b_ia0;
  boolean_T c1_e_overflow;
  int32_T c1_f_ix0;
  real_T c1_beta1;
  int32_T c1_f_iy0;
  real_T c1_y;
  char_T c1_TRANSA;
  real_T c1_z;
  int32_T c1_var;
  int32_T c1_g_n;
  ptrdiff_t c1_m_t;
  real_T c1_j_a;
  int32_T c1_b_var;
  int32_T c1_g_ix0;
  ptrdiff_t c1_n_t;
  int32_T c1_h_n;
  ptrdiff_t c1_lda_t;
  real_T c1_k_a;
  ptrdiff_t c1_incx_t;
  int32_T c1_h_ix0;
  ptrdiff_t c1_incy_t;
  int32_T c1_l_a;
  int32_T c1_b_c;
  int32_T c1_m_b;
  int32_T c1_c_c;
  int32_T c1_m_a;
  int32_T c1_n_b;
  int32_T c1_i60;
  int32_T c1_n_a;
  int32_T c1_o_b;
  int32_T c1_o_a;
  int32_T c1_p_b;
  boolean_T c1_f_overflow;
  int32_T c1_b_k;
  boolean_T exitg1;
  c1_b_info = 0;
  c1_j = 1;
  exitg1 = false;
  while ((!exitg1) && (c1_j < 3)) {
    c1_a = c1_j - 1;
    c1_jm1 = c1_a;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a << 1;
    c1_d_a = c1_j;
    c1_b = c1_c;
    c1_jj = (c1_d_a + c1_b) - 1;
    c1_n = c1_jm1;
    c1_ix0 = c1_j;
    c1_iy0 = c1_j;
    c1_b_n = c1_n;
    c1_b_ix0 = c1_ix0;
    c1_b_iy0 = c1_iy0;
    c1_c_n = c1_b_n;
    c1_c_ix0 = c1_b_ix0;
    c1_c_iy0 = c1_b_iy0;
    c1_d_n = c1_c_n;
    c1_d_ix0 = c1_c_ix0;
    c1_d_iy0 = c1_c_iy0;
    c1_d = 0.0;
    if (c1_d_n < 1) {
    } else {
      c1_ix = c1_d_ix0;
      c1_iy = c1_d_iy0;
      c1_f_b = c1_d_n;
      c1_g_b = c1_f_b;
      c1_c_overflow = ((!(1 > c1_g_b)) && (c1_g_b > 2147483646));
      if (c1_c_overflow) {
        c1_check_forloop_overflow_error(chartInstance, c1_c_overflow);
      }

      for (c1_k = 1; c1_k <= c1_d_n; c1_k++) {
        c1_d += c1_A[c1_ix - 1] * c1_A[c1_iy - 1];
        c1_h_a = c1_ix + 2;
        c1_ix = c1_h_a;
        c1_i_a = c1_iy + 2;
        c1_iy = c1_i_a;
      }
    }

    c1_ajj = c1_A[c1_jj] - c1_d;
    if (c1_ajj > 0.0) {
      c1_ajj = muDoubleScalarSqrt(c1_ajj);
      c1_A[c1_jj] = c1_ajj;
      if (c1_j < 2) {
        c1_h_b = c1_j;
        c1_nmj = 2 - c1_h_b;
        c1_f_a = c1_j + 1;
        c1_jp1 = c1_f_a;
        c1_g_a = c1_jj + 2;
        c1_jp1j = c1_g_a;
        c1_i_b = c1_jm1;
        c1_j_b = c1_i_b;
        c1_d_overflow = ((!(1 > c1_j_b)) && (c1_j_b > 2147483646));
        if (c1_d_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_d_overflow);
        }

        c1_m = c1_nmj;
        c1_e_n = c1_jm1;
        c1_ia0 = c1_jp1;
        c1_e_ix0 = c1_j;
        c1_e_iy0 = c1_jp1j;
        if ((c1_m < 1) || (c1_e_n < 1)) {
        } else {
          c1_b_m = c1_m;
          c1_f_n = c1_e_n;
          c1_alpha1 = -1.0;
          c1_b_ia0 = c1_ia0 - 1;
          c1_f_ix0 = c1_e_ix0 - 1;
          c1_beta1 = 1.0;
          c1_f_iy0 = c1_e_iy0 - 1;
          c1_TRANSA = 'N';
          c1_var = c1_b_m;
          c1_m_t = (ptrdiff_t)c1_var;
          c1_b_var = c1_f_n;
          c1_n_t = (ptrdiff_t)c1_b_var;
          c1_lda_t = (ptrdiff_t)2;
          c1_incx_t = (ptrdiff_t)2;
          c1_incy_t = (ptrdiff_t)1;
          dgemv(&c1_TRANSA, &c1_m_t, &c1_n_t, &c1_alpha1, &c1_A[c1_b_ia0],
                &c1_lda_t, &c1_A[c1_f_ix0], &c1_incx_t, &c1_beta1,
                &c1_A[c1_f_iy0], &c1_incy_t);
        }

        c1_k_b = c1_jm1;
        c1_l_b = c1_k_b;
        c1_e_overflow = ((!(1 > c1_l_b)) && (c1_l_b > 2147483646));
        if (c1_e_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_e_overflow);
        }

        c1_y = c1_ajj;
        c1_z = 1.0 / c1_y;
        c1_g_n = c1_nmj;
        c1_j_a = c1_z;
        c1_g_ix0 = c1_jp1j;
        c1_h_n = c1_g_n;
        c1_k_a = c1_j_a;
        c1_h_ix0 = c1_g_ix0;
        c1_l_a = c1_h_n - 1;
        c1_b_c = c1_l_a;
        c1_m_b = c1_b_c;
        c1_c_c = c1_m_b;
        c1_m_a = c1_h_ix0;
        c1_n_b = c1_c_c;
        c1_i60 = c1_m_a + c1_n_b;
        c1_n_a = c1_h_ix0;
        c1_o_b = c1_i60;
        c1_o_a = c1_n_a;
        c1_p_b = c1_o_b;
        c1_f_overflow = ((!(c1_o_a > c1_p_b)) && (c1_p_b > 2147483646));
        if (c1_f_overflow) {
          c1_check_forloop_overflow_error(chartInstance, c1_f_overflow);
        }

        for (c1_b_k = c1_h_ix0 - 1; c1_b_k + 1 <= c1_i60; c1_b_k++) {
          c1_A[c1_b_k] *= c1_k_a;
        }
      }

      c1_j++;
    } else {
      c1_A[c1_jj] = c1_ajj;
      c1_b_info = c1_j;
      exitg1 = true;
    }
  }

  c1_c_info = c1_b_info;
  c1_info = c1_c_info;
  c1_c_a = c1_c_info;
  c1_a1 = c1_c_a;
  c1_p = (c1_a1 == 0);
  if (c1_p) {
    c1_jmax = 2;
  } else {
    c1_jmax = c1_c_info - 1;
  }

  c1_b_b = c1_jmax;
  c1_c_b = c1_b_b;
  c1_overflow = ((!(2 > c1_c_b)) && (c1_c_b > 2147483646));
  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, c1_overflow);
  }

  for (c1_kkC = 2; c1_kkC <= c1_jmax; c1_kkC++) {
    c1_e_a = c1_kkC - 1;
    c1_i59 = c1_e_a;
    c1_d_b = c1_i59;
    c1_e_b = c1_d_b;
    c1_b_overflow = ((!(1 > c1_e_b)) && (c1_e_b > 2147483646));
    if (c1_b_overflow) {
      c1_check_forloop_overflow_error(chartInstance, c1_b_overflow);
    }

    for (c1_kkR = 1; c1_kkR <= c1_i59; c1_kkR++) {
      c1_A[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
             chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)sf_integer_check
             (chartInstance->S, 1U, 0U, 0U, (real_T)c1_kkR), 1, 2) +
            ((sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
               chartInstance->S, 1U, 0, 0, MAX_uint32_T, (int32_T)
               sf_integer_check(chartInstance->S, 1U, 0U, 0U, (real_T)c1_kkC), 1,
               2) - 1) << 1)) - 1] = 0.0;
    }
  }

  return c1_info;
}

static void init_dsm_address_info(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_sharedTrackingLibraryInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_x = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_xNew = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_P = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_PNew = (real_T (*)[4])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_yMeas = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_R = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_sharedTrackingLibrary_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1008891740U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1468494482U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1248096103U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3343978051U);
}

mxArray* sf_c1_sharedTrackingLibrary_get_post_codegen_info(void);
mxArray *sf_c1_sharedTrackingLibrary_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("whko95dcsmhKSMPnX4Eq");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_sharedTrackingLibrary_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_sharedTrackingLibrary_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c1_sharedTrackingLibrary_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("client_server");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("Furuta_Measurement");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_sharedTrackingLibrary_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_sharedTrackingLibrary_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString(
      "7fivH50FYHWyWErllND42E");
    mwSize exp_dims[2] = { 1, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);

    {
      mxArray* mxFcnName = mxCreateString("Furuta_Measurement");
      mxSetCell(mxExportedFunctionsUsedByThisChart, 0, mxFcnName);
    }

    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_sharedTrackingLibrary(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"PNew\",},{M[1],M[5],T\"xNew\",},{M[8],M[0],T\"is_active_c1_sharedTrackingLibrary\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_sharedTrackingLibrary_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc1_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _sharedTrackingLibraryMachineNumber_,
           1,
           1,
           1,
           0,
           7,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_sharedTrackingLibraryMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_sharedTrackingLibraryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _sharedTrackingLibraryMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"P");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yMeas");
          _SFD_SET_DATA_PROPS(3,1,1,0,"R");
          _SFD_SET_DATA_PROPS(4,2,0,1,"xNew");
          _SFD_SET_DATA_PROPS(5,2,0,1,"PNew");
          _SFD_SET_DATA_PROPS(6,10,0,0,"pM");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,567);
        _SFD_CV_INIT_EML_FCN(0,1,"",338,-1,361);
        _SFD_CV_INIT_EML_FCN(0,2,"",527,-1,556);
        _SFD_CV_INIT_EML_IF(0,1,0,160,182,364,562);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2U;
          dimVector[1]= 2U;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _sharedTrackingLibraryMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_sharedTrackingLibraryInstanceStruct *chartInstance =
      (SFc1_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c1_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c1_xNew);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c1_P);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c1_PNew);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c1_yMeas);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c1_R);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)&chartInstance->c1_pM);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sGhunIkBZhnZxXRtLsxRHlH";
}

static void sf_opaque_initialize_c1_sharedTrackingLibrary(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_sharedTrackingLibrary
    ((SFc1_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
  initialize_c1_sharedTrackingLibrary((SFc1_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_sharedTrackingLibrary(void *chartInstanceVar)
{
  enable_c1_sharedTrackingLibrary((SFc1_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_sharedTrackingLibrary(void *chartInstanceVar)
{
  disable_c1_sharedTrackingLibrary((SFc1_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_sharedTrackingLibrary(void *chartInstanceVar)
{
  sf_gateway_c1_sharedTrackingLibrary((SFc1_sharedTrackingLibraryInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_sharedTrackingLibrary(SimStruct*
  S)
{
  return get_sim_state_c1_sharedTrackingLibrary
    ((SFc1_sharedTrackingLibraryInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_sharedTrackingLibrary(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_sharedTrackingLibrary
    ((SFc1_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_sharedTrackingLibrary(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_sharedTrackingLibraryInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sharedTrackingLibrary_optimization_info();
    }

    finalize_c1_sharedTrackingLibrary((SFc1_sharedTrackingLibraryInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_sharedTrackingLibrary
    ((SFc1_sharedTrackingLibraryInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_sharedTrackingLibrary(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_sharedTrackingLibrary
      ((SFc1_sharedTrackingLibraryInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_sharedTrackingLibrary(SimStruct *S)
{
  /* Actual parameters from chart:
     pM
   */
  const char_T *rtParamNames[] = { "pM" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sharedTrackingLibrary_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4100279431U));
  ssSetChecksum1(S,(560536081U));
  ssSetChecksum2(S,(3851061273U));
  ssSetChecksum3(S,(3439417675U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_sharedTrackingLibrary(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_sharedTrackingLibrary(SimStruct *S)
{
  SFc1_sharedTrackingLibraryInstanceStruct *chartInstance;
  chartInstance = (SFc1_sharedTrackingLibraryInstanceStruct *)utMalloc(sizeof
    (SFc1_sharedTrackingLibraryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_sharedTrackingLibraryInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_sharedTrackingLibrary;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_sharedTrackingLibrary(chartInstance);
}

void c1_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_sharedTrackingLibrary(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_sharedTrackingLibrary(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_sharedTrackingLibrary_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
