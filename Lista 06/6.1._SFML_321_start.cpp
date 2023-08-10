#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Tomasz Targiel
// Lista 6
// Zadanie 1

int main()
{
    int keyonoff = 1;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Nasze okno");
    sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) // Dopóki okno jest otwarte...
    {
        // W tym obiekcie klasy sf::Event
        // Będziemy mieli informacje co zrobił użytkownik
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Użytkownik kliknął zamknięcie okna
            if (event.type == sf::Event::Closed)
                window.close();

            // Użytkownik nacisnął klawisz
            if (event.type == sf::Event::KeyPressed)
                keyonoff = 1 - keyonoff;
        }

        // Czyszczenie (na czarno)
        window.clear(sf::Color::Black);

        // Rysuj koło w zależności od stanu zmiennej keyonoff
        if (keyonoff)
            window.draw(shape);

        window.display();
    }
    return 0;
}
