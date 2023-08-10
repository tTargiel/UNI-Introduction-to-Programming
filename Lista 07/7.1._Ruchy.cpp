#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Tomasz Targiel
// Lista 7
// Zadanie 1

int main()
{
    int keyonoff = 1;

    // W podpunkcie 1) linijkę: sf::CircleShape shape(400.f); zmieniłem na: sf::CircleShape shape(200.f);

    // W podpunkcie 2) zdefiniowałem poniższe stałe
    const int width = 800;
    const int height = 800;
    // const int radius = 200;
    // const int startWidth = width / 2 - radius;
    // const int startHeight = height / 2 - radius;

    // W podpunkcie 3) zdefiniowałem poniższe zmienne typu float jako pozycje początkowe koła
    // float x = 120;
    // float y = 240;

    // W podpunkcie 5) zdefiniowałem poniższe zmienne typu float jako prędkości
    // float vx = 0.05;
    // float vy = 0.05;
    int dt = 5;

    // Podpunkt 7)
    int N = 4;
    float x[N] = {100, 300, 400, 500};
    float y[N] = {0, 100, 200, 400};
    float vx[N] = {0.04, 0.03, 0.02, 0.01};
    float vy[N] = {0.01, 0.03, 0.05, 0.07};

    // Deklaruję zmienną grawitacyjną z podpunktu 8)
    float g = 0.00001;

    // Podpunkt 9) dodaję od siebie tablice promieni kuli oraz wprowadzam zmienną color
    int radius[N] = {40, 50, 60, 80};
    float color = 0;

    // Zgodnie z poleceniem podpunktu 7) deklaruję oraz wypełniam tablicę o nazwie shapes
    sf::CircleShape shapes[N];
    for (int i = 0; i < N; i++)
    {
        sf::CircleShape shape(radius[i]);
        shapes[i] = shape;
    }

    // Poniższe dwie linijki uwzględniają stałe zdefiniowane w podpunkcie 2)
    sf::RenderWindow window(sf::VideoMode(width, height), "Nasze okno");
    // sf::CircleShape shape(radius);

    // Poniższe linijki kodu były używane w podpunkcie 2)
    // shape.setPosition(startWidth, startHeight);
    // shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) // Dopóki okno jest otwarte...
    {
        // Tu użyłem zmiennych z podpunktu 3)
        // shape.setPosition(x, y);

        // Zgodnie z podpunktem 5) zmieniam prędkość kuli
        // x += vx * dt;
        // y += vy * dt;

        // Na podstawie podpunktu 6) zaimplementowałem odbijanie kulki od brzegów okna
        // if (x + 2 * radius >= width || x <= 0)
        // {
        //     vx *= (-1);
        // }
        // else if (y + 2 * radius >= height || y <= 0)
        // {
        //     vy *= (-1);
        // }

        // W poniższej pętli widać zmiany poczynione w podpunktach 7) do 9)
        for (int i = 0; i < N; i++)
        {
            // Warunek upewniający się, że kulki nie wylecą poza okno programu
            if (x[i] + 2 * radius[i] >= width || x[i] < 0)
            {
                vx[i] *= (-1);
            }
            else if (y[i] + 2 * radius[i] >= height || y[i] < 0)
            {
                vy[i] *= (-1);
            }
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            vy[i] += g * dt; // Wprowadzam grawitację

            // Zależnie od położenia koloruję kulki na niebiesko lub czerwono, kolory zmieniają się w sposób płynny
            color = sqrt(x[i] * x[i] + y[i] * y[i]) * 0.255;
            shapes[i].setFillColor(sf::Color(color, (-1) * color, (-1) * color));
        }

        // W tym obiekcie klasy sf::Event
        // Będziemy mieli informacje co zrobił użytkownik
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Użytkownik kliknął zamknięcie okna
            if (event.type == sf::Event::Closed)
                window.close();
            // Poniższy warunek else if jest spełnieniem podpunktu 4)
            else if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

            // Użytkownik nacisnął klawisz
            if (event.type == sf::Event::KeyPressed)
                keyonoff = 1 - keyonoff;
        }

        // Czyszczenie (na czarno)
        window.clear(sf::Color::Black);

        // Rysuj koło w zależności od stanu zmiennej keyonoff
        if (keyonoff)
            // window.draw(shape);
            for (int i = 0; i < N; i++)
            {
                window.draw(shapes[i]);
                shapes[i].setPosition(x[i], y[i]);
            }

        window.display();
    }
    return 0;
}
