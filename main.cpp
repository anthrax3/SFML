#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
#include <iostream>
#include <cmath>
#include "TileLoader.h"
#include "StaticTiledMap.h"
using namespace std;

#define FPS 60
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

Vector2f getCenter(){
    return Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
}
Vector2f getObjCenter(Transformable obj){
    return Vector2f(obj.getScale().x/2, obj.getScale().y/2);
}
int main(){
    bool paused = false;
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Thing", sf::Style::Default, sf::ContextSettings(0,0,4));

    //Font and text for pause screen
     Font pauseFont;
     if (!pauseFont.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")){
         return 1;
     }
     Text pauseText("PAUSED", pauseFont, 24);
     pauseText.setOrigin(getObjCenter(pauseText));
     pauseText.setColor(Color::White);
     pauseText.setPosition(getCenter());

    //Square to move around
     int posCounter = 1;
     IntRect pos1 = sf::IntRect(0, 0, 50, 50);
     IntRect pos2 = sf::IntRect(50, 0, 50, 50);
     IntRect pos3 = sf::IntRect(100, 0, 50, 50);
     IntRect pos4 = sf::IntRect(150, 0, 50, 50);
     IntRect pos5 = sf::IntRect(0, 50, 50, 50);
     IntRect pos6 = sf::IntRect(0, 50, 50, 50);
     IntRect pos7 = sf::IntRect(0, 50, 50, 50);
     IntRect pos8 = sf::IntRect(0, 50, 50, 50);
     IntRect pos9 = sf::IntRect(0, 100, 50, 50);
     IntRect pos10 = sf::IntRect(0, 100, 50, 50);
     Texture rectangleTexture;
     if (!rectangleTexture.loadFromFile("gradient.png"))
     {
        return -1;
     }
     rectangleTexture.setSmooth(true);
     Sprite rectangle(rectangleTexture);
     rectangle.setPosition(400,300);
     rectangle.setOrigin(Vector2f(25, 25));
     float speed = 5;

    //Limit framerate to 60fps
     window.setFramerateLimit(FPS);
    //Game Loop
    while (window.isOpen()){
        //Events
        Event event;
        while (window.pollEvent(event)){
            //Exit event
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed){
                if (Keyboard::isKeyPressed(Keyboard::Escape)){
                    if (!paused)
                        paused = true;
                    else if (paused)
                        paused = false;
                }
                if (Keyboard::isKeyPressed(Keyboard::PageUp)) {
                    speed++;
                }
                if (Keyboard::isKeyPressed(Keyboard::PageDown)) {
                    speed--;
                }
            }
        }
        //Controls
        if (!paused){
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                rectangle.move(0, -speed);
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                rectangle.move(-speed, 0);
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                rectangle.move(0, speed);
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                rectangle.move(speed, 0);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                rectangle.rotate(speed);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                rectangle.rotate(-speed);
            }
            switch(posCounter) {
                case 1:
                    rectangle.setTextureRect(pos2);
                    posCounter++;
                    break;
                case 2:
                    rectangle.setTextureRect(pos3);
                    posCounter++;
                    break;
                case 3:
                    rectangle.setTextureRect(pos4);
                    posCounter++;
                    break;
                case 4:
                    rectangle.setTextureRect(pos5);
                    posCounter++;
                    break;
                case 5:
                    rectangle.setTextureRect(pos6);
                    posCounter++;
                    break;
                case 6:
                    rectangle.setTextureRect(pos7);
                    posCounter++;
                    break;
                case 7:
                    rectangle.setTextureRect(pos8);
                    posCounter++;
                    break;
                case 8:
                    rectangle.setTextureRect(pos9);
                    posCounter++;
                    break;
                case 9:
                    rectangle.setTextureRect(pos10);
                    posCounter++;
                    break;
                case 10:
                    rectangle.setTextureRect(pos1);
                    posCounter = 1;
                    break;
            }

        }
        window.clear();
        window.draw(rectangle);
        if (paused){
            window.draw(pauseText);
        }
        window.display();
    }
    return 0;
}
