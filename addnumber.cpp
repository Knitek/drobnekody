#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  std::string path;
  std::cin>>path;
  int liczba;
  std::cin>>liczba;
  sf::Image image;
  image.loadFromFile(path);
  
  sf::Font font;
  font.loadFromFile("arial.ttf");
  // Create a text
  sf::Text text("#", font);
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Red);
  
  for(int i=0;i<liczba;i++)
  {
      sf::RenderTexture renderTexture;
	  if(i<10)
	  {
		  text.setString("#0"+std::to_string(i));
	  }
      text.
      renderTexture.draw(text);
	  sf::Image tmpImage = renderTexture.getTexture().ToImage();
	  sf::Image cpopybase = image;
	  copybase.copy(tmpImage,20,600);
	  
  }
  }
