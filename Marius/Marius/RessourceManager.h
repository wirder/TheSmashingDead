#pragma once
class RessourceManager {
public: 
	static RessourceManager& instance()
	{
		static RessourceManager *instance = new RessourceManager();
		return *instance;
	}
private:
	RessourceManager() {}
};