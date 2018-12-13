#ifndef TextPrinter_h
#define TextPrinter_h
#include <SDL.h>
#include <string>
#include <map>

class TextPrinter
{
public:
	~TextPrinter() {}
	static TextPrinter* Instance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new TextPrinter();
		}
		return pInstance;
	}

	bool Load(std::string fileName, std::string id);
	void Init();
	void Draw(std::string id, int x, int y, int width, int height, float scale);
	void Draw(std::string id, int x, int y, int width, int height, float scale, double angle);
	void ClearFromCharMap(std::string id);

private:
	TextPrinter() {}
	static TextPrinter* pInstance;

	std::map<std::string, SDL_Texture*> charMap;
};

#endif