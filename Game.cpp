#include "snake.cpp"
class Game
{
private:
	std::vector<std::string> field;
	Snake player;
	int amountOfFood;
	int score;
public:

	Game() : amountOfFood(0), score(0), player(1, 2)
	{
		srand(time(nullptr));

		field.push_back("# # # # # # # # # # # # # # # # # # # # #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("#                                       #");
		field.push_back("# # # # # # # # # # # # # # # # # # # # #");

	}
	void Run()
	{

		std::cout << R"(#########################################)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#     __   _     _   __   _   _   __    #)" << std::endl;
		std::cout << R"(#    | _| | |\  | | |  | | |/ /  |      #)" << std::endl;
		std::cout << R"(#    | |  | | \ | | |__| | |  \  |--    #)" << std::endl;
		std::cout << R"(#   |__|  |_|  \|_| |  | |_|\__\ |__    #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#              by Nazar K.              #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#        Press any key to start         #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#########################################)" << std::endl;

		_getch();

		renderField();

		//waiting for S or D
		while (!GetAsyncKeyState(0x44) && !GetAsyncKeyState(0x53))
		{
		}

		int tick = 0;

		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			tick++;

			player.handleInput();

			/*We place food if its amount less than 7 and it has free space(304 is amount of cells in field).
			And we place food with difference 1 second if score less than 150*/
			if (amountOfFood < 7 && amountOfFood + score < 304 && (tick % 4 == 0 || score > 150))
			{
				addFood();
			}

			//Take a last part of the body before it moves to another place, so we can clear it.
			const coord lastPart = player.getLast();
			clearCell(lastPart);

			player.moveBody();

			
			if (isDead())
				break;

			eatFood();

			renderField();
		}

		int bestScore = 0;
		//If txt file is not created, we create it.
		std::ofstream("bestscore.txt", std::fstream::out | std::fstream::app);

		std::fstream readBestScore("bestscore.txt");
		readBestScore >> bestScore;

		readBestScore.close();


		if (score > bestScore)
		{
			bestScore = score;
			std::ofstream writeBestScore("bestscore.txt");
			writeBestScore << bestScore;
		}


		if (score >= 304)
			WonScene();
		else
			LostScene(bestScore);

	}

	bool eatFood()
	{
		coord head = player.getHead();
		if (field[head.x][head.y] == '$')
		{
			player.addPart();
			amountOfFood--;
			score++;
			return true;
		}
		return false;
	}

	void WonScene()
	{
		system("cls");

		std::cout << R"(#########################################)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#          _  _   __    _  _            #)" << std::endl;
		std::cout << R"(#          \\//  |  |  | || |           #)" << std::endl;
		std::cout << R"(#           ||   |__|  |____|           #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#      _   __   _   __    _     _       #)" << std::endl;
		std::cout << R"(#      \\_//\\_//  |  |  | |\\ | |      #)" << std::endl;
		std::cout << R"(#       \\/  \\/   |__|  |_| \\|_|      #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#              Congrats!                #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#########################################)" << std::endl;
	}

	void LostScene(const int& bestScore)
	{
		system("cls");

		std::cout << R"(#########################################)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#          __   _   _    _   __         #)" << std::endl;
		std::cout << R"(#         | _  |_| | \  / | |__         #)" << std::endl;
		std::cout << R"(#         |_ | | | |  \/  | |__         #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#          __  _   _  __   _            #)" << std::endl;
		std::cout << R"(#         |  | \\ // |__  |_|           #)" << std::endl;
		std::cout << R"(#         |__|  \_/  |__  | \           #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;

		std::string temp = "#       Your score is ";
		temp += std::to_string(score);
		while (temp.size() < 40)
			temp += ' ';
		temp += '#';
		std::cout << temp << std::endl;

		temp = "#       Your best score is ";
		temp += std::to_string(bestScore);
		while (temp.size() < 40)
			temp += ' ';
		temp += '#';
		std::cout << temp << std::endl;

		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#########################################)" << std::endl;


	}

	//check if head hitted boundaries or its body
	bool isDead()
	{
		coord head = player.getHead();

		if (head.x == 0 || head.x == field.size() - 1 || head.y == 0 || head.y == field[0].size() - 1
			|| field[head.x][head.y] == '0')
			return true;

		return false;
	}

	void clearCell(const coord& last) { field[last.x][last.y] = ' '; }


	//Render whole frame by setting console cursor at the beginning and redrawing everything
	void renderField()
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		coord head = player.getHead();
		coord firstIndex = player.getFirstIndex();

		//Changing prev. head cell from '@' to '0'
		if (firstIndex.x != -1)
			field[firstIndex.x][firstIndex.y] = '0';

		field[head.x][head.y] = '@';


		for (int i = 0; i < field.size(); i++)
		{
			if (i == 4)
				std::cout << field[i] << " Your score: " << score << std::endl;
			else if (i == 5)
				std::cout << field[i] << " Press W,A,S,D to move" << std::endl;
			else
				std::cout << field[i] << std::endl;
		}
	}

	//Place food in first random free cell
	void addFood()
	{
		amountOfFood++;

		int x = rand() % (field.size() - 2) + 1;
		int y = (rand() % (field[0].size() - 3) + 2) / 2 * 2;

		while (field[x][y] == '0' || field[x][y] == '@')
		{
			x = rand() % (field.size() - 2) + 1;
			int y = (rand() % (field[0].size() - 3) + 2) / 2 * 2;
		}

		field[x][y] = '$';

	}
};