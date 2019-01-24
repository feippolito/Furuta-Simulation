clf
sim('Furuta_Control_all_states.slx')
plot(simout)
hold on
plot(osc151(:,1),osc151(:,2))
