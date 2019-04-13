reset
set size 1,1
set multiplot
set size 0.5,0.5
set origin 0,0.5
plot 'input_sig.dat' with lines lc rgb 'black'
set origin 0,0
plot 'output_rex.dat' with lines lc rgb 'green'
set origin 0.5,0
plot 'output_imx.dat' with lines lc rgb 'green'
set origin 0.5,0.5
plot 'output_idft.dat' with lines lc rgb 'red'
pause -1