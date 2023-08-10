# Ustawiam typ terminala (format wyjściowy)
set terminal pngcairo size 1600,900 enhanced font 'Verdana,12'

# Ustawiam nazwę pliku wyjściowego
set output '4.5._Fibonacci.png'

# Tworzę wykres
plot "4.5._Fibonacci.dat" using 1:2 with lines, \
     "4.5._Fibonacci.dat" using 1:2:(sprintf("%d", $2)) with labels offset 0,1 notitle
