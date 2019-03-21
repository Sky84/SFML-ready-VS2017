#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<>
std::unordered_map<std::string_view, sf::Texture> Resources<sf::Texture>::ressources{};
template<>
std::unordered_map<std::string_view, sf::SoundBuffer> Resources<sf::SoundBuffer>::ressources{};
