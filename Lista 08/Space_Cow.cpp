#include <cmath>    // sqrt
#include <iostream> // cout, endl
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <tuple>    // make_tuple
#include <unistd.h> // usleep

// Tomasz Targiel
// Lista 8
// Space Cow

using namespace std;

bool playTheGame = 0;
double timeOfPlay = 0;
float gravity = 0;
int W = 640, H = 960;
int cowPositionX = W / 2, cowPositionY = H / 2;
int heightLimit = 300;
int keyLeft = 0, keyRight = 0;
int platformDimensions = 128, platformSpacing = 64;
int points = 0;
int turningVariable = 0;

struct platformCoordinates
{
    int x, y;
} chosenPlatformCoordinates[20];

struct platformDesign
{
    int rectLeft, rectTop, rectWidth, rectHeight;
} chosenPlatformDesign[5];

struct starCoordinates
{
    int x, y;
};
starCoordinates chosenStarCoordinates[5];

void eventsSFML(sf::RenderWindow &window)
{
    // W tym obiekcie klasy sf::Event pozyskuje informacje o tym co zrobił użytkownik
    sf::Event event;

    while (window.pollEvent(event))
    {
        // Jeżeli użytkownik kliknie zamknięcie okna lub wciśnie klawisz Escape
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            terminate();
        }
    }

    // Sprawdzam stan klawiszy
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        keyLeft = 1;
    else
        keyLeft = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        keyRight = 1;
    else
        keyRight = 0;
}

void cowAnimation(sf::Sprite &cow, sf::IntRect &cowRect, int cowShiftX, int x, int y)
{

    cowRect.left = x;
    cowRect.top = y;
    if (gravity < -1)
    {
        cowRect.left = cowShiftX * 1;
        cow.setTextureRect(cowRect);
    }
    else if (gravity > -1 && gravity < 1)
    {
        cowRect.left = cowShiftX * 2 + 24;
        cow.setTextureRect(cowRect);
    }
    else
    {
        cowRect.left = cowShiftX * 3 + 24;
        cow.setTextureRect(cowRect);
    }
}

void generateStartingPlatformPositions()
{
    static int height = H - 192;
    chosenPlatformCoordinates[0].x = W / 2;
    chosenPlatformCoordinates[0].y = height;
    for (int i = 1; i < H / 192; i++)
    {
        height -= 192;
        chosenPlatformCoordinates[i].x = rand() % W;
        chosenPlatformCoordinates[i].y = height;
        // cout << chosenPlatformCoordinates[i].x << " " << chosenPlatformCoordinates[i].y << endl;
    }
    chosenStarCoordinates[0].x = rand() % W;
    chosenStarCoordinates[0].y = rand() % H;
}

void platformMovement()
{
    for (int i = 0; i < H / 192; i++)
    { // Sprawdzam, czy krowa jest na platformie

        // Lewa krawędź platformy  // Prawa krawędź platformy  // Sprawdzanie wysokości  // Przenikanie przez platformy na odpowiedniej wysokości  // Tylko jeśli krowa spada
        if (((cowPositionX + 112) > chosenPlatformCoordinates[i].x) && (cowPositionX < (chosenPlatformCoordinates[i].x + 192)) && ((cowPositionY + 128) > chosenPlatformCoordinates[i].y) && ((cowPositionY + 128) < (chosenPlatformCoordinates[i].y + 32)) && (gravity > 0))
        {
            gravity = -16;
        }
        // cout << cowPositionX << endl;
    }
    if (cowPositionY > 330)
    {
        // gravity = 0;
    }
    else
    {
        // if (cowPositionY < heightLimit)
        for (int i = 0; i < H / 192; i++)
        {
            cowPositionY = heightLimit;
            // Przesuwam platformy zgodnie z grawitacją
            chosenPlatformCoordinates[i].y = chosenPlatformCoordinates[i].y - gravity;
            // Usuwam dolne platformy i losuje kolejne
            if (chosenPlatformCoordinates[i].y > H)
            {
                chosenPlatformCoordinates[i].y = -192;
                if (chosenPlatformCoordinates[i].y - chosenPlatformCoordinates[i - 1].y < 192)
                    chosenPlatformCoordinates[i].y -= -192;

                chosenPlatformCoordinates[i].x = rand() % W;
            }
        }
    }
}

void starMovement()
{

    if (cowPositionY > 330)
    {
        // gravity = 0;
    }
    else
    {
        // if (cowPositionY < heightLimit)
        cowPositionY = heightLimit;
        // Przesuwam gwiazdki - punkty zgodnie z grawitacją
        chosenStarCoordinates[0].y = chosenStarCoordinates[0].y - gravity;
        // Usuwam dolne gwiazdki i losuje kolejne
        if (chosenStarCoordinates[0].y > H)
        {
            chosenStarCoordinates[0].y = 0;
            chosenStarCoordinates[0].x = rand() % W;
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "Tomasz Targiel - Space Cow");

    srand(time(0)); // Pozyskuje seed do randomizacji

    sf::Clock clock;

    sf::Font font;
    font.loadFromFile("space_mission.otf");

    int cowShiftX = 256 + 32, cowShiftY = 24;
    sf::Texture cowTexture;
    cowTexture.loadFromFile("cow.png");
    sf::IntRect cowRect(0, cowShiftY, 256 + 16, 224 + 16);
    sf::Sprite cow(cowTexture, cowRect);
    cow.scale(0.5, 0.5);

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");
    sf::RectangleShape shapeBackground(sf::Vector2f(W, H));
    shapeBackground.setTexture(&backgroundTexture);

    sf::Texture buttonTexture;
    buttonTexture.loadFromFile("button.png");
    sf::RectangleShape shapeButton(sf::Vector2f(512, 128));
    shapeButton.setTexture(&buttonTexture);

    sf::Texture starTexture;
    starTexture.loadFromFile("star.png");
    sf::Sprite star(starTexture);
    star.scale(0.2, 0.2);

    window.setFramerateLimit(60); // Ustawiam FPS na 60

    generateStartingPlatformPositions();

    tie(chosenPlatformDesign[0].rectLeft, chosenPlatformDesign[0].rectTop, chosenPlatformDesign[0].rectWidth, chosenPlatformDesign[0].rectHeight) = make_tuple(platformSpacing, platformSpacing, platformDimensions, platformDimensions);
    tie(chosenPlatformDesign[1].rectLeft, chosenPlatformDesign[1].rectTop, chosenPlatformDesign[1].rectWidth, chosenPlatformDesign[1].rectHeight) = make_tuple(platformSpacing, platformSpacing * 2 + platformDimensions, platformDimensions * 2, platformDimensions);
    tie(chosenPlatformDesign[2].rectLeft, chosenPlatformDesign[2].rectTop, chosenPlatformDesign[2].rectWidth, chosenPlatformDesign[2].rectHeight) = make_tuple(platformSpacing, platformSpacing * 3 + platformDimensions * 2, platformDimensions * 3, platformDimensions);
    tie(chosenPlatformDesign[3].rectLeft, chosenPlatformDesign[3].rectTop, chosenPlatformDesign[3].rectWidth, chosenPlatformDesign[3].rectHeight) = make_tuple(platformSpacing, platformSpacing * 4 + platformDimensions * 3, platformDimensions * 4, platformDimensions);
    tie(chosenPlatformDesign[4].rectLeft, chosenPlatformDesign[4].rectTop, chosenPlatformDesign[4].rectWidth, chosenPlatformDesign[4].rectHeight) = make_tuple(platformSpacing, platformSpacing * 5 + platformDimensions * 4, platformDimensions * 4, platformDimensions);

    int currentRandom = 4;
    // int currentRandom = rand() % 5;
    sf::Texture platformsTexture;
    platformsTexture.loadFromFile("platforms.png");
    sf::IntRect platformRect(chosenPlatformDesign[currentRandom].rectLeft, chosenPlatformDesign[currentRandom].rectTop, chosenPlatformDesign[currentRandom].rectWidth, chosenPlatformDesign[currentRandom].rectHeight);
    sf::Sprite platform(platformsTexture, platformRect);
    platform.scale(0.5, 0.5);

    sf::Music music;
    if (!music.openFromFile("space_motion_beat.ogg"))
        return -1; // error
    music.play();

    while (window.isOpen()) // Dopóki okno jest otwarte...
    {
        while (playTheGame == 0)
        {
            eventsSFML(window);
            window.clear();
            window.draw(shapeBackground);
            window.draw(shapeButton);
            shapeButton.setPosition(W / 2 - 256, H / 2);
            sf::Text play;
            play.setFont(font);
            play.setString("Press ENTER");
            play.setCharacterSize(64);
            play.setPosition(W / 2 - 192, H / 2 + 24);
            sf::Text gameTitle;
            gameTitle.setFont(font);
            gameTitle.setString("Space Cow");
            gameTitle.setCharacterSize(112 * 0.8);
            gameTitle.setPosition(W / 2 - 216, H * 0.2);
            sf::Text rules;
            rules.setFont(font);
            rules.setString("To win, you must collect\n\tat least 5 points");
            rules.setCharacterSize(64 * 0.7);
            rules.setPosition(W / 2 - 256 - 12, H * 0.35);
            window.draw(gameTitle);
            window.draw(rules);
            window.draw(play);
            window.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                playTheGame = 1;
                timeOfPlay = 0;
            }
            else
                usleep(1000);
        }

        eventsSFML(window);

        // Definiuje poruszanie sie krowy na strzalkach klawiatury
        if (keyRight == 1)
        {
            cowPositionX += 3;
            turningVariable = 0;
        }
        if (keyLeft == 1)
        {
            cowPositionX -= 3;
            turningVariable = -1;
        }
        cow.setPosition(cowPositionX, cowPositionY);

        if (turningVariable == 0)
        {
            cowAnimation(cow, cowRect, cowShiftX, 32, 32);
        }
        else
        {
            cowAnimation(cow, cowRect, cowShiftX, 32, 288);
        }
        gravity += 0.2;
        cowPositionY += gravity;

        platformMovement();
        starMovement();

        if (cowPositionX >= W - 96)
        {
            cowPositionX = W - 96;
            cow.setPosition(cowPositionX, cowPositionY);
        }
        else if (cowPositionX <= -32)
        {
            cowPositionX = -32;
            cow.setPosition(cowPositionX, cowPositionY);
        }

        window.draw(shapeBackground);
        window.draw(cow);

        for (int i = 0; i < H / 192; i++)
        {
            platform.setPosition(chosenPlatformCoordinates[i].x, chosenPlatformCoordinates[i].y);
            window.draw(platform);
        }

        star.setPosition(chosenStarCoordinates[0].x, chosenStarCoordinates[0].y);
        window.draw(star);

        sf::FloatRect cowFloatRect = cow.getGlobalBounds();
        sf::FloatRect starFloatRect = star.getGlobalBounds();

        float x = (cow.getPosition().x + (cowFloatRect.width / 2)) - (star.getPosition().x + (starFloatRect.width / 2));
        float y = (cow.getPosition().y + (cowFloatRect.height / 2)) - (star.getPosition().y + (starFloatRect.height / 2));
        float distance = sqrt((x * x) + (y * y));

        if (distance <= (cowFloatRect.width / 3) + (starFloatRect.width / 3))
        {
            points += 1;

            chosenStarCoordinates[0].x = W + 100;
            distance = 100000;
        }

        sf::Text timeNotification;
        timeNotification.setFont(font);
        timeNotification.setString("TIME:");
        timeNotification.setCharacterSize(32 * 0.8);
        timeNotification.setPosition(W * 0.03, H * 0.01);
        sf::Text timeCount;
        timeCount.setFont(font);
        timeCount.setString(to_string(timeOfPlay));
        timeCount.setCharacterSize(32 * 0.8);
        timeCount.setPosition(W * 0.03, H * 0.04);
        sf::Text pointsNotification;
        pointsNotification.setFont(font);
        pointsNotification.setString("POINTS:");
        pointsNotification.setCharacterSize(32 * 0.8);
        pointsNotification.setPosition(W * 0.03, H * 0.10);
        sf::Text pointsCount;
        pointsCount.setFont(font);
        pointsCount.setString(to_string(points));
        pointsCount.setCharacterSize(32 * 0.8);
        pointsCount.setPosition(W * 0.03, H * 0.13);
        window.draw(timeNotification);
        window.draw(timeCount);
        window.draw(pointsNotification);
        window.draw(pointsCount);
        window.display();
        timeOfPlay += 0.01667;

        if (timeOfPlay >= 30 || cowPositionY >= H)
        {
            gravity = 0;
            window.clear();
            window.draw(shapeBackground);
            window.draw(shapeButton);
            shapeButton.setPosition(W / 2 - 256, H / 2);
            sf::Text quit;
            quit.setFont(font);
            quit.setString("Quit with ESC");
            quit.setCharacterSize(64 * 0.8);
            quit.setPosition(W / 2 - 168 + 8, H / 2 + 28);
            if (points >= 5)
            {
                sf::Text pointsNotification;
                pointsNotification.setFont(font);
                pointsNotification.setString("You won!!!");
                pointsNotification.setCharacterSize(112 * 0.8);
                pointsNotification.setPosition(W / 2 - 216 + 8, H * 0.2);
                sf::Text pointsCount;
                pointsCount.setFont(font);
                pointsCount.setString("You collected " + to_string(points) + " points");
                pointsCount.setCharacterSize(64 * 0.8);
                pointsCount.setPosition(W / 2 - 256 - 24, H * 0.35);
                window.draw(pointsNotification);
                window.draw(pointsCount);
                window.draw(quit);
                window.display();
            }
            else
            {
                sf::Text pointsNotification;
                pointsNotification.setFont(font);
                pointsNotification.setString("You lost...");
                pointsNotification.setCharacterSize(112 * 0.8);
                pointsNotification.setPosition(W / 2 - 208 + 16, H * 0.2);
                sf::Text pointsCount;
                pointsCount.setFont(font);
                pointsCount.setString("You collected only " + to_string(points) + " points");
                pointsCount.setCharacterSize(64 * 0.7);
                pointsCount.setPosition(W / 2 - 264 - 32, H * 0.35);
                window.draw(pointsNotification);
                window.draw(pointsCount);
                window.draw(quit);
                window.display();
            }
            usleep(100000);
        }
    }

    return 0;
}
