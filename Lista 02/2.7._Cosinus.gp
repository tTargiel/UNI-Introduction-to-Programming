# Ustawiam typ terminala (format wyjściowy)
set terminal pngcairo size 800,600 enhanced font 'Verdana,12'

# Ustawiam nazwę pliku wyjściowego
set output '2.7._Cosinus.png'

# Tworzę wykresy obu funkcji
plot "2.7._Cosinus.dat" using 1:2 with lines title "cos(x)", \
     "2.7._Cosinus.dat" using 1:3 with lines title "cos^2(x)"
