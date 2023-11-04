#pragma once
class GFXSettings {
public:
	//Variables & Resources
	std::string title;
	sf::VideoMode resolution;
	bool fullScreen;
	unsigned int frameRateLimit;
	bool verdicalSync;
	sf::ContextSettings contextSettings;
	std::vector<sf::VideoMode> videoModes;

	//Constructors & Destructors
	GFXSettings();

	//Public methods
	void saveToFile(const std::filesystem::path path);
	void loadFromFile(const std::filesystem::path path);

};

class StateData {
public:
	//Variables & Resources
	std::unique_ptr<std::stack<State*>> states;
	std::unique_ptr<std::map<std::string, int>> supportedKeys;
	sf::Font font;
	GFXSettings gfxSettings;

	//Constructors & Destructors
	StateData();
	~StateData();
};





