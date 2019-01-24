

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <ukfCfg.h>
#include <ukfCfg1.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 2
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void ukf_sfun_cfg0_Outputs_wrapper(const real_T *meas,
			const real_T *Init,
			real_T *states,
			real_T *y_mean,
			real_T *kalman)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
static tUKF ukfIo[2];
int i;
int j;
float64 * const py_cfg0 = ukfIo[0].input.y.val;

if(0 != Init[0])
{
//UKF initialization: CFG0
(void)ukf_init(&ukfIo[0], &UkfMatrixCfg0);	
}
//UKF:CFG0 apply/load system measurements
ukfIo[0].input.y.val[0] = meas[0];
ukfIo[0].input.y.val[1] = meas[1];
//loop if any signal in prev. moment is required

//calculate UKF states and outputs
(void)ukf_step(&ukfIo[0]);

//K_kalman_gain_4x2
for(i=0;i<4;i++)
{
    for(j=0;j<2;j++)
    {
        //attention: different way to access 2D array elements.
        //from left(Simulink array kalman) and right(C code array K_kalman_gain)
        kalman[4*j+i] = UkfMatrixCfg0.K_kalman_gain.val[2*i+j];
    }
}
/*    nr*c+r                                   nc*r+c
kalman[4*0+0] = UkfMatrixCfg0.K_kalman_gain.val[2*0+0];//a11
kalman[4*1+0] = UkfMatrixCfg0.K_kalman_gain.val[2*0+1];//a12
kalman[4*0+1] = UkfMatrixCfg0.K_kalman_gain.val[2*1+0];//a21
kalman[4*1+1] = UkfMatrixCfg0.K_kalman_gain.val[2*1+1];//a22

kalman[4*0+2] = UkfMatrixCfg0.K_kalman_gain.val[2*2+0];//a11
kalman[4*1+2] = UkfMatrixCfg0.K_kalman_gain.val[2*2+1];//a12
kalman[4*0+3] = UkfMatrixCfg0.K_kalman_gain.val[2*3+0];//a21
kalman[4*1+3] = UkfMatrixCfg0.K_kalman_gain.val[2*3+1];//a22

attention: different way to access 2D array elements.
from left(Simulink array kalman) and right(C code array K_kalman_gain )
*/

//write system states as output to Simulink
states[0]=ukfIo[0].update.x.val[0];
states[1]=ukfIo[0].update.x.val[1];
states[2]=ukfIo[0].update.x.val[2];
states[3]=ukfIo[0].update.x.val[3];

//write predicted y_mean as output to Simulink
y_mean[0] = ukfIo[0].predict.y_m.val[0];
y_mean[1] = ukfIo[0].predict.y_m.val[1];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
