#include "main.h"
#include "snake.cpp"

class GameField
{
private:
	std::vector<std::string> field;
	Snake player;
	int amountOfFood;
	int maxScore;
public:
	GameField() : player(1, 2), amountOfFood(), maxScore(304)
	{

		field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("#                                       #");
		field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
	}


	bool eatFood()
	{
		coord head = player.getHead();
		if (field[head.x][head.y] == '$')
		{
			player.addPart();
			amountOfFood--;
			return true;
		}
		return false;
	}

	//Place food in first random free cell
	void addFood(const int& currentScore)
	{
		if (amountOfFood + currentScore >= maxScore || amountOfFood > 7)
			return;

		int x, y;

		do
		{
			x = rand() % (field.size() - 2) + 1;
			y = (rand() % (field[0].size() - 3) + 2) / 2 * 2;
		} while (field[x][y] == '0' || field[x][y] == '@' || field[x][y] == '#');
		 

		field[x][y] = '$';
		amountOfFood++;

	}

	void movePlayer()
	{
		player.handleInput();

		//Take a last part of the body before it moves to another place, so we can clear it.
		const coord lastPart = player.getLast();
		clearCell(lastPart);

		player.moveBody();
	}

	void clearCell(const coord& last) { field[last.x][last.y] = ' '; }

	int getMaxScore() { return maxScore; }

	//check if head hitted boundaries or its body
	bool isDead()
	{
		coord head = player.getHead();

		if (field[head.x][head.y] == '#' || field[head.x][head.y] == '0')
			return true;

		return false;
	}

	void loadMap(int map)
	{
		field.clear();

		switch (map)
		{
		case 0:
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			break;

		case 1:
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			field.emplace_back("#                         #             #");
			field.emplace_back("#               #######   #             #");
			field.emplace_back("#                             #   #     #");
			field.emplace_back("###########                   #   #     #");
			field.emplace_back("#                             #   #     #");
			field.emplace_back("#   #######                   #   #######");
			field.emplace_back("#         #####               #         #");
			field.emplace_back("#######   #                   #######   #");
			field.emplace_back("#         #                       ###   #");
			field.emplace_back("#   ###########               #   ###   #");
			field.emplace_back("#         #                   #   ###   #");
			field.emplace_back("#######   #                   #   ###   #");
			field.emplace_back("#         #####               #   ###   #");
			field.emplace_back("#   #######                             #");
			field.emplace_back("#                                       #");
			field.emplace_back("#               ###########             #");
			field.emplace_back("#                                       #");
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			break;

		case 2:
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			field.emplace_back("#                                       #");
			field.emplace_back("#           #     #     #     #     #   #");
			field.emplace_back("#           #     #     #     #     #   #");
			field.emplace_back("#           #######     #     #     #   #");
			field.emplace_back("#           #                 #     #   #");
			field.emplace_back("#           #           #     #     #   #");
			field.emplace_back("#           #     #     #     #     #   #");
			field.emplace_back("#           #     #     #     #     #   #");
			field.emplace_back("#           #############     #     #   #");
			field.emplace_back("#                             #     #   #");
			field.emplace_back("#           #############     #     #   #");
			field.emplace_back("#           #                 #     #   #");
			field.emplace_back("#           #   #########     #     #   #");
			field.emplace_back("#           #           #     #     #   #");
			field.emplace_back("#           #########   #     #     #   #");
			field.emplace_back("#           #           #     #     #   #");
			field.emplace_back("#                                       #");
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			break;

		case 3:
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			field.emplace_back("#             #####       #       #     #");
			field.emplace_back("#       ###       #       #       #     #");
			field.emplace_back("#####     ###     #       #       #     #");
			field.emplace_back("#######     #     #       #       #     #");
			field.emplace_back("#           ###   #       #       #     #");
			field.emplace_back("#   ###########                         #");
			field.emplace_back("#                                       #");
			field.emplace_back("#                                       #");
			field.emplace_back("#   ###########    ######################");
			field.emplace_back("#             #                         #");
			field.emplace_back("###########   #    #                    #");
			field.emplace_back("#             #    #                    #");
			field.emplace_back("#   ###########    #                    #");
			field.emplace_back("#             #    #                    #");
			field.emplace_back("###########   #    #                    #");
			field.emplace_back("#             #    #                    #");
			field.emplace_back("#                                       #");
			field.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			break;

		default:
			break;
		}

		maxScore = -1;

		for (size_t i = 1; i < field.size(); i++)
		{
			for (size_t j = 2; j < field[0].size(); j += 2)
			{
				if (field[i][j] == ' ')
					maxScore++;
			}
		}

	}

	void clearField(int map)
	{
		player.clear();
		amountOfFood = 0;
		field.clear();
		loadMap(map);
	}

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
			std::cout << field[i] << std::endl;
		}
	}
};