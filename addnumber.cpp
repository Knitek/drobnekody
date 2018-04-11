#include <iostream>
#include <SFML/Graphics.hpp>

class config
{
 public:
    std::string inputpath;
    int liczba;
    std::string fontpath;
    int charaktersize;
}


int main()
{
  std::string path;
  std::cin>>path;
  int liczba;
  std::cin>>liczba;
  sf::Image imageBase;
  imageBase.loadFromFile(path);
  
  sf::Font font;
  font.loadFromFile("arial.ttf");
  // Create a text
  sf::Text text("#", font);
  text.setCharacterSize(60);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Red);
  text.setOutlineThickness
  
  for(int i=0;i<liczba;i++)
  {
      sf::RenderTexture renderTexture;
	  if(i<10)
	  {
		  text.setString("#0"+std::to_string(i));
	  }
	  else
	  {
		text.setString("#"+std::to_string(i));  
	  }
      renderTexture.draw(text);
	  sf::Image tmpImage = renderTexture.getTexture().ToImage();
	  sf::Image imake = imageBase;
	  copybase.copy(tmpImage,20,600);
	  copybase.saveToFile("miniature"+std::to_string(i))
  }
}
