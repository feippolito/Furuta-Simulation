# Furuta Pendulum

This primary goal of this project is to develop an inverted pendulum and control it in its upright position by aplying torque through a dc motor in a horizontal rotary arm.
This project presents various challenges as the system is very unstable and it's not controllable utilizing classical control theory. The space-state was the best aproach since the sistem has single input and mutiple outputs (SIMO), the control of the four states of the plant was also required for its stabilization in the upright position. The Linear–quadratic regulator (LQR) controller design resulted in the most stable option.

This repository contains:

1. Dynamic model of the furuta pendulum

2. Parameters from the mechanical pendulum

3. Controller design: Linear–quadratic regulator, pole-placement design, pendulum swing-up

4. Two different closed-loop systems simulations:
   - Full state availability.
   - State estimation with non linear unscented Kalman-filter (UKF).
   
5. Simulation visualization

6. UKF implementation in C/C++ language (not finished)  

The project as a whole also includes an [Hardware in the loop (HIL) simulation](https://github.com/feippolito/HIL-FurutaPendulum) and the [system identification and control on the LabVIEW enviroment](https://github.com/feippolito/FurutaPendulum-Control)
