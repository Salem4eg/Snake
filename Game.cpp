#include "GameField.cpp"
#include "menu.cpp"

class Game
{
private:

	GameField field;
	int score;
	Menu menu;
	int bestScore;
public:

	Game() :score(0)
	{
		std::srand(std::time(nullptr));

		//prevents resizing window
		HWND consoleWindow = GetConsoleWindow();
		SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

		RECT r;
		GetWindowRect(consoleWindow, &r);
		
		MoveWindow(consoleWindow, r.left, r.top, 380, 400, TRUE);



		//If txt file is not created, we create it.
		std::ofstream("settings.txt", std::fstream::out | std::fstream::app);

		std::string choosenLang = "ND";
		std::string colourCode = "07";

		std::ifstream readFile("settings.txt");
		if (!readFile.eof())
		{
			readFile >> bestScore;

			readFile >> colourCode;

			readFile >> choosenLang;
		}
		else
			bestScore = -1;

		if (choosenLang == "ND")
			menu.setLanguage(notDefined);
		else if (choosenLang == "EN")
			menu.setLanguage(english);
		else
			menu.setLanguage(ukrainian);


		menu.setColourCode(colourCode[0], colourCode[1]);

		readFile.close();

	}
	void Run()
	{
		bool repeatMap = false;
		int map = 0;

		if (menu.getLanguage() == notDefined)
			menu.chooseLanguage();


		while (true)
		{
			field.clearField(map);
			score = 0;

			if (!repeatMap)
			{
				// -1 - quit; 0 - normal game; 1 - maps;
				int variant = menu.showMainMenu();

				if (variant == -1)
				{
					saveParameters();
					return;
				}

				if (variant == 0)
					field.loadMap(0);
				else if (variant == 1)
				{
					map = menu.chooseMap();
					field.loadMap(map);
				}
			}


			field.renderField();


			int tick = 0;

			while (true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
				tick++;

				// place food every second or 1/4 second if score > 150
				if (tick % 4 == 0 || score > 150)
					field.addFood(score);

				field.movePlayer();

				if (field.isDead())
					break;

				if (field.eatFood())
					score++;

				field.renderField();
			}


			saveParameters();


			if (score >= field.getMaxScore())
				menu.WonScene();
			else
				menu.LostScene(bestScore, score);


			repeatMap = menu.playAgainOnTheMap();

		}

	}

	void saveParameters()
	{
		if (score > bestScore)
			bestScore = score;

		std::ofstream writeInFile("settings.txt");
		writeInFile << bestScore << "\n";
		writeInFile << menu.getColourCode() << "\n";
		if (menu.getLanguage() == english)
			writeInFile << "EN";
		else
			writeInFile << "UA";
	}

};