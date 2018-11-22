//
//  main.cpp
//  Pigon
//
//  Created by Squeege on 11/13/18.
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Constants.h"
int main( )
{
    // creates the window
    sf::RenderWindow window(sf::VideoMode(1280,1080), "Pigon" );
    window.setFramerateLimit(60);
    // prints dimensions of the window
    std::printf("The Window Size is: %i %i", window.getSize().x,window.getSize().y);
    std::cout << "\nSpace: Restart Drawing\n\nUp Arrow: Increase Framerate(Max: 60)\n\nDown Arrow: Decrease Framerate";
    // creates the points which we need inorder to write the lines
    sf::CircleShape decagon(400.f, 10);
    decagon.move(window.getSize().x / 2, window.getSize().y / 2);
    
    int i = 1;
    int framerate = 60;
    
    // code running in the window
    while(window.isOpen())
    {
        // handle all events
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        // Restarts Drawing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            i = 0;
            window.clear();
        }
        // Slows Framerate
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(framerate > 1)
            {
                --framerate;
                window.setFramerateLimit(framerate);
            }
            
        }
        // Speeds up framerate, change the if statement to desired frame cap
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            
            if(framerate < 60)
            {
                ++framerate;
                window.setFramerateLimit(framerate);
            }
        }
        // Uncomment to see framerate speeds
        //std::printf("\n Framerate: %i", framerate);
        // draws lines
        if(i < 1000)
        {
            sf::Vertex a(decagon.getPoint(getDigit(i)), colors[getDigit(i)]);
            sf::Vertex b(decagon.getPoint(getDigit(i+1)), colors[getDigit(i+1)]);
            
            b.position.x += rand()%randomWidth - randomWidth / 2;
            b.position.y += rand()%randomHeight - randomHeight / 2;
            
            const sf::Vertex line[2] = {a, b};
            window.draw(line, 2, sf::Lines);
            i++;
        }
        // displays frames
        window.display();
    }
    return 0;
}
