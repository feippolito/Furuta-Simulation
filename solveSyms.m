function y = solveSyms(a,b)

syms x y 
f=(x+y)
y =double(vpa(subs(f,{x y},[a b])))
y=double(vpa(f(a,b))