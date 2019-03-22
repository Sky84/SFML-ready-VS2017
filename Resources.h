#pragma once
#include <unordered_map>
#include <string_view>
#include <string>

using namespace std::string_literals;

template<typename T>
class Resources
{
public:
		Resources() = delete;
		static T const& getRessources(std::string_view const& chemin) {
			auto resultat = ressources.find(chemin);
			if (resultat == std::end(ressources)) {
				if (!ressources[chemin].loadFromFile(chemin.data())) {
					throw "Error : "s + chemin.data();
				}
				return ressources[chemin];
			}
			return resultat->second;
		};
	private:
		static std::unordered_map<std::string_view, T> ressources;
};
