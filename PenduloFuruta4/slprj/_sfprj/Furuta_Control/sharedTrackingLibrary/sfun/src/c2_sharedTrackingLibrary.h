#ifndef __c2_sharedTrackingLibrary_h__
#define __c2_sharedTrackingLibrary_h__

/* Type Definitions */
#ifndef struct_tag_sa7zVHjml4KNIUODgeuHwWG
#define struct_tag_sa7zVHjml4KNIUODgeuHwWG

struct tag_sa7zVHjml4KNIUODgeuHwWG
{
  char_T FcnName[23];
  boolean_T IsSimulinkFcn;
  real_T NumberOfExtraArgumentInports;
  boolean_T HasAdditiveNoise;
  real_T Alpha;
  real_T Beta;
  real_T Kappa;
};

#endif                                 /*struct_tag_sa7zVHjml4KNIUODgeuHwWG*/

#ifndef typedef_c2_sa7zVHjml4KNIUODgeuHwWG
#define typedef_c2_sa7zVHjml4KNIUODgeuHwWG

typedef struct tag_sa7zVHjml4KNIUODgeuHwWG c2_sa7zVHjml4KNIUODgeuHwWG;

#endif                                 /*typedef_c2_sa7zVHjml4KNIUODgeuHwWG*/

#ifndef typedef_SFc2_sharedTrackingLibraryInstanceStruct
#define typedef_SFc2_sharedTrackingLibraryInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_sharedTrackingLibrary;
  c2_sa7zVHjml4KNIUODgeuHwWG c2_pS;
  void *c2_fEmlrtCtx;
  real_T (*c2_x)[2];
  real_T (*c2_xNew)[2];
  real_T (*c2_P)[4];
  real_T (*c2_Q)[4];
  real_T *c2_uState;
  boolean_T *c2_unused;
  real_T (*c2_b_P)[4];
} SFc2_sharedTrackingLibraryInstanceStruct;

#endif                                 /*typedef_SFc2_sharedTrackingLibraryInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_sharedTrackingLibrary_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_sharedTrackingLibrary_get_check_sum(mxArray *plhs[]);
extern void c2_sharedTrackingLibrary_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
