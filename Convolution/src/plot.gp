set size 1,1
set multiplot
set size 0.5, 0.5
set origin 0,0.5
plot 'input_sig.dat' with lines lc rgb 'black'
set origin 0.5,0.5
plot 'impulse_rsp.dat' with lines lc rgb 'red'
set origin 0,0
plot 'output_sig.dat' with lines lc rgb 'blue'
pause -1