# Ustawiam typ terminala (format wyjściowy)
set terminal pngcairo size 800,600 enhanced font 'Verdana,12'

# Ustawiam nazwę pliku wyjściowego
set output '4.2._Ksiegowy.png'

# Tworzę wykres
plot "4.2._Ksiegowy.dat" using 1:2 with lines
