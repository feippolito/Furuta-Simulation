# FurutaPendulum-Simulation
Model and control for the inverted pendulum, also know as furuta pendulum.

This primary goal of this project is to develop an inverted pendulum and control it in its upright position by aplying torque through a dc motor in a horizontal rotary arm.
This project presents various challenges as the system is very unstable and it's not controllable utilizing classical control theory. The space-state was the best aproach since the sistem has single input and mutiple outputs (SIMO), the control of the four states of the plant was also required for its stabilization in the upright position. The LQR controller design resulted in the most stable option.

