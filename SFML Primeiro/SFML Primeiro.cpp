#include "rect.hpp"

int main()
{
	// Create the main window
	int windowWidth = 1600;
	int windowHeight = 920;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
	window.setFramerateLimit(60);

	// Create a list of rectangles (Rect)
	std::vector<Rect> rects;

	// Create 10 Rect objects and add them to the list with randon velocities
	int numberOfRects = 500;
	float minVelocity = -1.5;
	float maxVelocity = 1.5;
	float minSize = 30;

	for (int i = 0; i < numberOfRects; i++)
	{
		sf::Vector2f position = sf::Vector2f((float)rand() / RAND_MAX * (windowWidth - minSize) + minSize, (float)rand() / RAND_MAX * (windowHeight - minSize) + minSize);
		sf::Vector2f size = sf::Vector2f(minSize, minSize);
		sf::Color color = sf::Color(255, 255, 255, int(255/4)); // 50% opacity white color
		// Generate random float velocities
		float xVelocity = (float)rand() / RAND_MAX * (maxVelocity - minVelocity) + minVelocity;
		float yVelocity = (float)rand() / RAND_MAX * (maxVelocity - minVelocity) + minVelocity;
		Rect rect = Rect(position, size, color, xVelocity, yVelocity);
		rects.push_back(rect);
		printf("Rect %d created with xVelocity = %f and yVelocity = %f\n", i, xVelocity, yVelocity);
	}
	printf("Created %d rects\n", numberOfRects);
	// Game loop


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) 
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			// Space to reset the simulation
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					for (int i = 0; i < rects.size(); i++)
					{
						sf::Vector2f position = sf::Vector2f((float)rand() / RAND_MAX * (windowWidth - minSize) + minSize, (float)rand() / RAND_MAX * (windowHeight - minSize) + minSize);
						sf::Vector2f size = sf::Vector2f(minSize, minSize);
						sf::Color color = sf::Color(255, 255, 255, int(255 / 4)); // 50% opacity white color
						// Generate random float velocities
						float xVelocity = (float)rand() / RAND_MAX * (maxVelocity - minVelocity) + minVelocity;
						float yVelocity = (float)rand() / RAND_MAX * (maxVelocity - minVelocity) + minVelocity;
						Rect rect = Rect(position, size, color, xVelocity, yVelocity);
						rects[i] = rect;
					}
				}
			}

		}
		//Update
		for (int i = 0; i < rects.size(); i++)
		{
			rects[i].update();
		}


		// Check for collisions with the window
		for (int i = 0; i < rects.size(); i++)
		{
			if (rects[i].getShape().getPosition().x < 0 || rects[i].getShape().getPosition().x + rects[i].getShape().getSize().x > windowWidth)
			{
				rects[i].setXVelocity(-rects[i].getXVelocity());
			}
			if (rects[i].getShape().getPosition().y < 0 || rects[i].getShape().getPosition().y + rects[i].getShape().getSize().y > windowHeight)
			{
				rects[i].setYVelocity(-rects[i].getYVelocity());
			}
		}


		//Rendering
		window.clear();

		for (int i = 0; i < rects.size(); i++)
		{
			rects[i].draw(window);
		}


		window.display();

	}

    return 0;
}