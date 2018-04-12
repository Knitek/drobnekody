#include <iostream>
#include <SFML/Graphics.hpp>

class Config
{
 public:
    	std::string inputpath;
  	std::string fontpath;
	
  	int charaktersize;
	int liczba;
	Config();
	Config(std::string configpath);
	void loadConfig(std::string path);
};
Config::Config(std::string configpath)
{
	loadConfig(configpath);
}
void Config::loadConfig(std::string path);
{
	fstream file;
	file.open(path,std::ios::in);
	file>>inputpath;
	file>>fontpath;
	file>>liczba;
	file>>charaktersize;
	file.close();
}

int main()
{
  Config config("config.cfg");
  sf::Image imageBase;
  imageBase.loadFromFile(config.inputpath);

  sf::Font font;
  font.loadFromFile(config.fontpath);
  // Create a text
  sf::Text text("#", font);
  text.setCharacterSize(150);
  text.setStyle(sf::Text::Bold);
  text.setColor(sf::Color::Red);
  text.setOutlineThickness(2.0f);
  text.setOutlineColor(sf::Color::White);
  for(int i=0;i<liczba;i++)
  {
      sf::RenderTexture renderTexture;
      renderTexture.create(1280,720);
	  if(i<10)
	  {
		  text.setString("#0"+std::to_string(i));
	  }
	  else
	  {
		text.setString("#"+std::to_string(i));
	  }

	
        renderTexture.draw(text);
        sf::Image tmp = renderTexture.getTexture().copyToImage();
        tmp.flipVertically();
        sf::Image img;
        img = imageBase;
        img.copy(tmp,20,550,sf::IntRect(0,0,1280,720),true);
        img.saveToFile("miniature"+std::to_string(i)+".png");
  }
  return 0;
}

