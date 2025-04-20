#ifndef PAINT_DASH_TEXTURE_MANAGER_H
#define PAINT_DASH_TEXTURE_MANAGER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace PaintDash
{
	namespace managers
	{
		class TextureManager;
	}
}

class PaintDash::managers::TextureManager
{
	public:
		TextureManager();
		~TextureManager();
		void addTexture(const std::string key, const std::string filename);
		sf::Texture& getTextureByKey(const std::string key) const;
	private:
		std::unordered_map<std::string, sf::Texture*> textures;
};

#endif