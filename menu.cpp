#pragma once
#include "main.h"

class Menu
{
private:
	std::vector<std::string> menu;
	std::vector<std::string> buttonsWithoutArrow;
	std::vector<std::string> buttonsWithArrow;
	int button;
	Language lang;
	std::string backGroundColourCode;
	std::string textColourCode;
public:
	Menu() : button(0), lang(english), backGroundColourCode("0"), textColourCode("7")
	{
		SetConsoleOutputCP(1251);
	}

	Language chooseLanguage()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		menu.clear();

		menu.emplace_back("#########################################");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#          English | Українська         #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#                                       #");
		menu.emplace_back("#########################################");

		renderMenu();

		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x41))
			{
				menu[9] = "#          English<| Українська         #";
				lang = english;
				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			if (GetAsyncKeyState(0x44))
			{
				menu[9] = "#          English |>Українська         #";
				lang = ukrainian;
				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		return lang;
	}

	Language getLanguage() { return lang; }

	void setLanguage(Language l)
	{
		lang = l;
	}

	void setColourCode(char backGroundCode, char textCode)
	{
		backGroundColourCode = backGroundCode;
		textColourCode = textCode;

		std::string setColourCommand = "color " + backGroundColourCode + textColourCode;
		system(setColourCommand.c_str());
	}

	int showMainMenu()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		// main menu
		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#     __   _     _   __   _  _   __     #");
			menu.emplace_back(R"(#    | _| | |\  | | |  | | |//  |       #)");
			menu.emplace_back(R"(#    | |  | | \ | | |__| | | \  |--     #)");
			menu.emplace_back(R"(#   |__|  |_|  \|_| |  | |_|\_\ |__     #)");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#         made by Nazar Kleban          #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#           Play on normal map          #");
			menu.emplace_back("#            Play on other map          #");
			menu.emplace_back("#               Settings                #");
			menu.emplace_back("#                 Help                  #");
			menu.emplace_back("#                 Quit                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  ___   _    _  ==   ---    _  _   __  #");
			menu.emplace_back(R"(#     | |\\  //| || ||  /|| | |//  |  | #)");
			menu.emplace_back(R"(#  ===| ||\\//|| || || / || | | \  |__| #)");
			menu.emplace_back(R"(#  ___| ||    || || ||/  || |_|\_\ |  | #)");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#       зроблено Клебаном Назаром       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#        Зіграти на звичайній мапі      #");
			menu.emplace_back("#          Зіграти на іншій мапі        #");
			menu.emplace_back("#              Налаштування             #");
			menu.emplace_back("#                Допомога               #");
			menu.emplace_back("#                 Вийти                 #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[10]);
		buttonsWithoutArrow.push_back(menu[11]);
		buttonsWithoutArrow.push_back(menu[12]);
		buttonsWithoutArrow.push_back(menu[13]);
		buttonsWithoutArrow.push_back(menu[14]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#          >Play on normal map          #");
			buttonsWithArrow.emplace_back("#           >Play on other map          #");
			buttonsWithArrow.emplace_back("#              >Settings                #");
			buttonsWithArrow.emplace_back("#                >Help                  #");
			buttonsWithArrow.emplace_back("#                >Quit                  #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#       >Зіграти на звичайній мапі      #");
			buttonsWithArrow.emplace_back("#         >Зіграти на іншій мапі        #");
			buttonsWithArrow.emplace_back("#             >Налаштування             #");
			buttonsWithArrow.emplace_back("#               >Допомога               #");
			buttonsWithArrow.emplace_back("#                >Вийти                 #");
		}

		menu[10 + button] = buttonsWithArrow[button];
		renderMenu();

		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000)
			{
				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;

				std::this_thread::sleep_for(std::chrono::milliseconds(50));

				if (button < 0)
					button = 4;
				if (button > 4)
					button = 0;

				menu[10] = buttonsWithoutArrow[0];
				menu[11] = buttonsWithoutArrow[1];
				menu[12] = buttonsWithoutArrow[2];
				menu[13] = buttonsWithoutArrow[3];
				menu[14] = buttonsWithoutArrow[4];

				menu[10 + button] = buttonsWithArrow[button];

				renderMenu();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}

		switch (button)
		{
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			showSettings();
			break;
		case 3:
			showControlHelp();
			break;
		case 4:
			return -1;
		}

		return showMainMenu();
	}

	void showSettings()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		// Settings menu
		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                Settings               #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#         change background colour      #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#            change text colour         #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#              Change language          #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#             Back to main menu         #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#               Налаштування            #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#            Змінити колір фону         #"); // 6
			menu.emplace_back("#                                       #");
			menu.emplace_back("#           Змінити колір тексту        #"); // 8
			menu.emplace_back("#                                       #");
			menu.emplace_back("#               Змінити мову            #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#            Повернутись до меню        #"); // 12
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[6]);
		buttonsWithoutArrow.push_back(menu[8]);
		buttonsWithoutArrow.push_back(menu[10]);
		buttonsWithoutArrow.push_back(menu[12]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#        >change background colour      #");
			buttonsWithArrow.emplace_back("#           >change text colour         #");
			buttonsWithArrow.emplace_back("#             >Change language          #");
			buttonsWithArrow.emplace_back("#            >Back to main menu         #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#           >Змінити колір фону         #");
			buttonsWithArrow.emplace_back("#          >Змінити колір тексту        #");
			buttonsWithArrow.emplace_back("#              >Змінити мову            #");
			buttonsWithArrow.emplace_back("#           >Повернутись до меню        #");
		}

		menu[6 + button * 2] = buttonsWithArrow[button];
		renderMenu();
		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000)
			{
				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;


				if (button < 0)
					button = 3;
				if (button > 3)
					button = 0;


				menu[6] = buttonsWithoutArrow[0];
				menu[8] = buttonsWithoutArrow[1];
				menu[10] = buttonsWithoutArrow[2];
				menu[12] = buttonsWithoutArrow[3];

				menu[6 + button * 2] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		switch (button)
		{
		case 0:
			showBackGroundColourSettings();
			showSettings();
			break;
		case 1:
			showTextColourSettings();
			showSettings();
			break;
		case 2:
			chooseLanguage();
			break;
		case 3:
			break;
		default:
			std::cout << "Something went wrong..." << std::endl;
		}

	}

	void showBackGroundColourSettings()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		/*
		 * black
		 * Blue
		 * Green
		 * Agua
		 * Red
		 * Purple
		 * Yellow
		 * White
		 * Gray
		 * Light Blue
		 * Light green
		 * Light agua
		 * light red
		 * light purple
		 * light yellow
		 * bright white
		 *
		 *
		 */

		 // Settings - background colour. menu
		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#      Settings - background colour     #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#        Black          Gray            #"); // 6
			menu.emplace_back("#        Blue           Light blue      #");
			menu.emplace_back("#        Green          Light green     #");
			menu.emplace_back("#        Agua           Light agua      #");
			menu.emplace_back("#        Red            Light red       #");
			menu.emplace_back("#        Purple         Light purple    #");
			menu.emplace_back("#        Yellow         Light yellow    #");
			menu.emplace_back("#        White          Bright white    #"); // 13
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                 Back                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#       Налаштування - колір фону       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#    Чорний          Сірий              #"); // 6
			menu.emplace_back("#    Синій           Блакитний          #");
			menu.emplace_back("#    Зелений         Світло-зелений     #");
			menu.emplace_back("#    Водянистий      Світло-водянистий  #");
			menu.emplace_back("#    Червоний        Світло-червоний    #");
			menu.emplace_back("#    Фіолетовий      Світло-фіолетовий  #");
			menu.emplace_back("#    Жовтий          Світло-жовтий      #");
			menu.emplace_back("#    Білий           Світло-білий       #"); // 13
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                Назад                  #"); // 16
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[6]);
		buttonsWithoutArrow.push_back(menu[7]);
		buttonsWithoutArrow.push_back(menu[8]);
		buttonsWithoutArrow.push_back(menu[9]);
		buttonsWithoutArrow.push_back(menu[10]);
		buttonsWithoutArrow.push_back(menu[11]);
		buttonsWithoutArrow.push_back(menu[12]);
		buttonsWithoutArrow.push_back(menu[13]);
		buttonsWithoutArrow.push_back(menu[16]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#       >Black          Gray            #");
			buttonsWithArrow.emplace_back("#       >Blue           Light blue      #");
			buttonsWithArrow.emplace_back("#       >Green          Light green     #");
			buttonsWithArrow.emplace_back("#       >Agua           Light agua      #");
			buttonsWithArrow.emplace_back("#       >Red            Light red       #");
			buttonsWithArrow.emplace_back("#       >Purple         Light purple    #");
			buttonsWithArrow.emplace_back("#       >Yellow         Light yellow    #");
			buttonsWithArrow.emplace_back("#       >White          Bright white    #");
			buttonsWithArrow.emplace_back("#        Black         >Gray            #");
			buttonsWithArrow.emplace_back("#        Blue          >Light blue      #");
			buttonsWithArrow.emplace_back("#        Green         >Light green     #");
			buttonsWithArrow.emplace_back("#        Agua          >Light agua      #");
			buttonsWithArrow.emplace_back("#        Red           >Light red       #");
			buttonsWithArrow.emplace_back("#        Purple        >Light purple    #");
			buttonsWithArrow.emplace_back("#        Yellow        >Light yellow    #");
			buttonsWithArrow.emplace_back("#        White         >Bright white    #");
			buttonsWithArrow.emplace_back("#                >Back                  #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#   >Чорний          Сірий              #");
			buttonsWithArrow.emplace_back("#   >Синій           Блакитний          #");
			buttonsWithArrow.emplace_back("#   >Зелений         Світло-зелений     #");
			buttonsWithArrow.emplace_back("#   >Водянистий      Світло-водянистий  #");
			buttonsWithArrow.emplace_back("#   >Червоний        Світло-червоний    #");
			buttonsWithArrow.emplace_back("#   >Фіолетовий      Світло-фіолетовий  #");
			buttonsWithArrow.emplace_back("#   >Жовтий          Світло-жовтий      #");
			buttonsWithArrow.emplace_back("#   >Білий           Світло-білий       #");
			buttonsWithArrow.emplace_back("#    Чорний         >Сірий              #");
			buttonsWithArrow.emplace_back("#    Синій          >Блакитний          #");
			buttonsWithArrow.emplace_back("#    Зелений        >Світло-зелений     #");
			buttonsWithArrow.emplace_back("#    Водянистий     >Світло-водянистий  #");
			buttonsWithArrow.emplace_back("#    Червоний       >Світло-червоний    #");
			buttonsWithArrow.emplace_back("#    Фіолетовий     >Світло-фіолетовий  #");
			buttonsWithArrow.emplace_back("#    Жовтий         >Світло-жовтий      #");
			buttonsWithArrow.emplace_back("#    Білий          >Світло-білий       #");
			buttonsWithArrow.emplace_back("#               >Назад                  #");
		}

		std::string setColourCommand;
		menu[6 + button / 2] = buttonsWithArrow[button];
		renderMenu();

		while (!GetAsyncKeyState(VK_RETURN) || button < 16)
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000
				|| GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(VK_RETURN) && button != 16)
			{

				if (GetAsyncKeyState(VK_RETURN) && button < 16)
				{
					if (button < 10)
						backGroundColourCode = button + 48;
					else
						backGroundColourCode = button + 55;

					setColourCommand = "color " + backGroundColourCode + textColourCode;
					system(setColourCommand.c_str());
				}

				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				else if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;
				else if (GetAsyncKeyState(0x41) & 0x8000 && button != 16 && button > 7) // left
					button -= 8;
				else if (GetAsyncKeyState(0x44) & 0x8000 && button != 16 && button < 8) // right
					button += 8;

				if (button < 0)
					button = 16;
				if (button > 16)
					button = 0;


				menu[6] = buttonsWithoutArrow[0];
				menu[7] = buttonsWithoutArrow[1];
				menu[8] = buttonsWithoutArrow[2];
				menu[9] = buttonsWithoutArrow[3];
				menu[10] = buttonsWithoutArrow[4];
				menu[11] = buttonsWithoutArrow[5];
				menu[12] = buttonsWithoutArrow[6];
				menu[13] = buttonsWithoutArrow[7];
				menu[16] = buttonsWithoutArrow[8];

				if (button != 16)
					menu[6 + button % 8] = buttonsWithArrow[button];
				else
					menu[16] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}



		// записати вибір кольору в текстовий файл

		//showSettings();
	}

	void showTextColourSettings()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;


		// Settings - background colour. menu
		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#        Settings - Text colour         #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#        black          Gray            #"); // 6
			menu.emplace_back("#        Blue           Light Blue      #");
			menu.emplace_back("#        Green          Light green     #");
			menu.emplace_back("#        Agua           Light agua      #");
			menu.emplace_back("#        Red            light red       #");
			menu.emplace_back("#        Purple         light purple    #");
			menu.emplace_back("#        Yellow         light yellow    #");
			menu.emplace_back("#        White          bright white    #"); // 13
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                 Back                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#       Налаштування - колір тексту     #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#    Чорний          Сірий              #"); // 6
			menu.emplace_back("#    Синій           Блакитний          #");
			menu.emplace_back("#    Зелений         Світло-зелений     #");
			menu.emplace_back("#    Водянистий      Світло-водянистий  #");
			menu.emplace_back("#    Червоний        Світло-червоний    #");
			menu.emplace_back("#    Фіолетовий      Світло-фіолетовий  #");
			menu.emplace_back("#    Жовтий          Світло-жовтий      #");
			menu.emplace_back("#    Білий           Світло-білий       #"); // 13
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                Назад                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[6]);
		buttonsWithoutArrow.push_back(menu[7]);
		buttonsWithoutArrow.push_back(menu[8]);
		buttonsWithoutArrow.push_back(menu[9]);
		buttonsWithoutArrow.push_back(menu[10]);
		buttonsWithoutArrow.push_back(menu[11]);
		buttonsWithoutArrow.push_back(menu[12]);
		buttonsWithoutArrow.push_back(menu[13]);
		buttonsWithoutArrow.push_back(menu[16]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#       >black          Gray            #");
			buttonsWithArrow.emplace_back("#       >Blue           Light Blue      #");
			buttonsWithArrow.emplace_back("#       >Green          Light green     #");
			buttonsWithArrow.emplace_back("#       >Agua           Light agua      #");
			buttonsWithArrow.emplace_back("#       >Red            light red       #");
			buttonsWithArrow.emplace_back("#       >Purple         light purple    #");
			buttonsWithArrow.emplace_back("#       >Yellow         light yellow    #");
			buttonsWithArrow.emplace_back("#       >White          bright white    #");
			buttonsWithArrow.emplace_back("#        black         >Gray            #");
			buttonsWithArrow.emplace_back("#        Blue          >Light Blue      #");
			buttonsWithArrow.emplace_back("#        Green         >Light green     #");
			buttonsWithArrow.emplace_back("#        Agua          >Light agua      #");
			buttonsWithArrow.emplace_back("#        Red           >light red       #");
			buttonsWithArrow.emplace_back("#        Purple        >light purple    #");
			buttonsWithArrow.emplace_back("#        Yellow        >light yellow    #");
			buttonsWithArrow.emplace_back("#        White         >bright white    #");
			buttonsWithArrow.emplace_back("#                >Back                  #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#   >Чорний          Сірий              #");
			buttonsWithArrow.emplace_back("#   >Синій           Блакитний          #");
			buttonsWithArrow.emplace_back("#   >Зелений         Світло-зелений     #");
			buttonsWithArrow.emplace_back("#   >Водянистий      Світло-водянистий  #");
			buttonsWithArrow.emplace_back("#   >Червоний        Світло-червоний    #");
			buttonsWithArrow.emplace_back("#   >Фіолетовий      Світло-фіолетовий  #");
			buttonsWithArrow.emplace_back("#   >Жовтий          Світло-жовтий      #");
			buttonsWithArrow.emplace_back("#   >Білий           Світло-білий       #");
			buttonsWithArrow.emplace_back("#    Чорний         >Сірий              #");
			buttonsWithArrow.emplace_back("#    Синій          >Блакитний          #");
			buttonsWithArrow.emplace_back("#    Зелений        >Світло-зелений     #");
			buttonsWithArrow.emplace_back("#    Водянистий     >Світло-водянистий  #");
			buttonsWithArrow.emplace_back("#    Червоний       >Світло-червоний    #");
			buttonsWithArrow.emplace_back("#    Фіолетовий     >Світло-фіолетовий  #");
			buttonsWithArrow.emplace_back("#    Жовтий         >Світло-жовтий      #");
			buttonsWithArrow.emplace_back("#    Білий          >Світло-білий       #");
			buttonsWithArrow.emplace_back("#               >Назад                  #");
		}

		std::string setColourCommand;
		menu[6 + button] = buttonsWithArrow[button];
		renderMenu();
		while (!GetAsyncKeyState(VK_RETURN) || button != 16)
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000
				|| GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(VK_RETURN) && button != 16)
			{
				if (GetAsyncKeyState(VK_RETURN) && button < 16)
				{
					if (button < 10)
						textColourCode = button + 48;
					else
						textColourCode = button + 55;

					setColourCommand = "color " + backGroundColourCode + textColourCode;
					system(setColourCommand.c_str());
				}

				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				else if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;
				else if (GetAsyncKeyState(0x41) & 0x8000 && button != 16 && button > 7) // left
					button -= 8;
				else if (GetAsyncKeyState(0x44) & 0x8000 && button != 16 && button < 8) // right
					button += 8;

				if (button < 0)
					button = 16;
				if (button > 16)
					button = 0;


				menu[6] = buttonsWithoutArrow[0];
				menu[7] = buttonsWithoutArrow[1];
				menu[8] = buttonsWithoutArrow[2];
				menu[9] = buttonsWithoutArrow[3];
				menu[10] = buttonsWithoutArrow[4];
				menu[11] = buttonsWithoutArrow[5];
				menu[12] = buttonsWithoutArrow[6];
				menu[13] = buttonsWithoutArrow[7];
				menu[16] = buttonsWithoutArrow[8];

				if (button != 16)
					menu[6 + button % 8] = buttonsWithArrow[button];
				else
					menu[16] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}


		// записати кольори консолі в текстовий файл

		//showSettings();
	}

	void showControlHelp()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#             Help - control            #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Control of snake is done by W A S D  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Menu control is the same, except of  #");
			menu.emplace_back("#  adding Enter key to confrim action   #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                 Next                  #");
			menu.emplace_back("#                 Back                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#           Допомога - керування        #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Керування змійкою відбувається       #");
			menu.emplace_back("#  клавішами W A S D.                   #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Керування меню відбувається так само #");
			menu.emplace_back("#  але з добавлення клавіші Enter       #");
			menu.emplace_back("#  для підтвердження дій.               #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                Вперед                 #");// 15
			menu.emplace_back("#                Назад                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[15]);
		buttonsWithoutArrow.push_back(menu[16]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#                >Next                  #");
			buttonsWithArrow.emplace_back("#                >Back                  #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#               >Вперед                 #");
			buttonsWithArrow.emplace_back("#               >Назад                  #");
		}

		menu[15 + button] = buttonsWithArrow[button];
		renderMenu();
		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000)
			{
				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;

				if (button < 0)
					button = 1;
				if (button > 1)
					button = 0;


				menu[15] = buttonsWithoutArrow[0];
				menu[16] = buttonsWithoutArrow[1];


				menu[15 + button] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		switch (button)
		{
		case 0:
			showGameplayHelp();
			break;
		case 1:
			showMainMenu();
			break;
		default:
			std::cout << "Something went wrong.." << std::endl;
		}
	}

	void showGameplayHelp()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#            Help - gameplay            #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  The snake moves in direction         #");
			menu.emplace_back("#  chosen by player. If snake hits      #");
			menu.emplace_back("#  a wall or its body then the game     #");
			menu.emplace_back("#  is over and the snake goes into      #");
			menu.emplace_back("#  borshch. If snake stumbles upon      #");
			menu.emplace_back("#  a food '$' then the snake grows      #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  To win you need to score 304 points  #");
			menu.emplace_back("#  (in normal game)                     #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                >Back                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#           Допомога - ігролад          #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#=======================================#");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Змійка рухається в заданому гравцем  #");
			menu.emplace_back("#  напрямку. Якщо змійка вдариться в    #");
			menu.emplace_back("#  стіну або свою частину тіла, то      #");
			menu.emplace_back("#  грі кінець, а змійку відправляють в  #");
			menu.emplace_back("#  борщ. Якщо змійка натрапляє на їжу   #");
			menu.emplace_back("#  '$', то вона збільшується.           #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#  Щоб перемогти, змійка має набрати    #");
			menu.emplace_back("#  304 очки (в звичайній грі)           #");
			menu.emplace_back("#                                       #");// 15
			menu.emplace_back("#               >Назад                  #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		renderMenu();

		while (!GetAsyncKeyState(VK_RETURN))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}

		showMainMenu();
	}

	int chooseMap()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;


		if (lang == english)
		{
			menu.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#               Choose map              #"); // 2
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Map 1                #"); // 8
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Map 2                #"); // 10
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Map 3                #"); // 12
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Back                 #"); // 16
			menu.emplace_back("#                                       #");
			menu.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
		}
		else
		{
			menu.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#               Оберіть мапу            #"); // 2
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Мапа 1               #"); // 8
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Мапа 2               #"); // 10
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Мапа 3               #"); // 12
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Назад                #"); // 16
			menu.emplace_back("#                                       #");
			menu.emplace_back("# # # # # # # # # # # # # # # # # # # # #");
		}

		buttonsWithoutArrow.push_back(menu[8]);
		buttonsWithoutArrow.push_back(menu[10]);
		buttonsWithoutArrow.push_back(menu[12]);
		buttonsWithoutArrow.push_back(menu[16]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#                 >Map 1                #");
			buttonsWithArrow.emplace_back("#                 >Map 2                #");
			buttonsWithArrow.emplace_back("#                 >Map 3                #");
			buttonsWithArrow.emplace_back("#                 >Back                 #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#                 >Мапа 1               #");
			buttonsWithArrow.emplace_back("#                 >Мапа 2               #");
			buttonsWithArrow.emplace_back("#                 >Мапа 3               #");
			buttonsWithArrow.emplace_back("#                 >Назад                #");
		}

		menu[8] = buttonsWithArrow[button];
		renderMenu();
		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000)
			{
				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;

				if (button < 0)
					button = 3;
				if (button > 3)
					button = 0;


				menu[8] = buttonsWithoutArrow[0];
				menu[10] = buttonsWithoutArrow[1];
				menu[12] = buttonsWithoutArrow[2];
				menu[16] = buttonsWithoutArrow[3];


				if (button != 3)
					menu[8 + button * 2] = buttonsWithArrow[button];
				else
					menu[16] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		switch (button)
		{
		case 0:
			return 1;
		case 1:
			return 2;
		case 2:
			return 3;
		case 3:
			showMainMenu();
			break;
		default:
			std::cout << "Something went wrong.." << std::endl;
		}
		return 3;
	}

	bool playAgainOnTheMap()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		menu.clear();
		buttonsWithArrow.clear();
		buttonsWithoutArrow.clear();
		button = 0;

		if (lang == english)
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#         Play again on this map?       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Yes                  #"); // 8
			menu.emplace_back("#                                       #");
			menu.emplace_back("#              Back to menu             #"); // 10
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}
		else
		{
			menu.emplace_back("#########################################");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#        Зіграти знову на цій мапі?     #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                  Так                  #"); // 8
			menu.emplace_back("#                                       #");
			menu.emplace_back("#            Повернутись до меню        #"); // 10
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#                                       #");
			menu.emplace_back("#########################################");
		}

		buttonsWithoutArrow.push_back(menu[8]);
		buttonsWithoutArrow.push_back(menu[10]);

		if (lang == english)
		{
			buttonsWithArrow.emplace_back("#                 >Yes                  #");
			buttonsWithArrow.emplace_back("#             >Back to menu             #");
		}
		else
		{
			buttonsWithArrow.emplace_back("#                 >Так                  #");
			buttonsWithArrow.emplace_back("#           >Повернутись до меню        #");
		}


		menu[8] = buttonsWithArrow[button];
		renderMenu();
		while (!GetAsyncKeyState(VK_RETURN))
		{
			if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x53) & 0x8000)
			{
				if (GetAsyncKeyState(0x57) & 0x8000) // up
					button--;
				if (GetAsyncKeyState(0x53) & 0x8000) // down
					button++;

				if (button < 0)
					button = 1;
				if (button > 1)
					button = 0;


				menu[8] = buttonsWithoutArrow[0];
				menu[10] = buttonsWithoutArrow[1];


				menu[8 + button * 2] = buttonsWithArrow[button];

				renderMenu();
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		switch (button)
		{
		case 0:
			return true;
		case 1:
			return false;
		default:
			std::cout << "Something went wrong.." << std::endl;
		}

		return false;
	}

	void WonScene()
	{
		system("cls");
		if (lang == english)
		{
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
			std::cout << R"(#            >Press enter               #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#########################################)" << std::endl;
		}
		else
		{
			std::cout << R"(#########################################)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#            ====                       #)" << std::endl;
			std::cout << R"(#             ||   || //||              #)" << std::endl;
			std::cout << R"(#             ||   ||// ||              #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#    ___   __  _   __  __  __  == ___   #)" << std::endl;
			std::cout << R"(#   || || |__ |_| |__ ||\\//|| || |     #)" << std::endl;
			std::cout << R"(#   || || |__ |   |__ ||    || || |     #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#              Вітаю тебе!              #)" << std::endl;
			std::cout << R"(#            >Натисни Enter             #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#########################################)" << std::endl;
		}

		while (!GetAsyncKeyState(VK_RETURN))
		{
		}

	}

	void LostScene(const int& bestScore, const int& score)
	{
		system("cls");
		std::string temp;
		if (lang == english)
		{
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

			temp = "#       Your score is ";
		}
		else
		{
			std::cout << R"(#########################################)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#      _   ==         __                #)" << std::endl;
			std::cout << R"(#   ||//   ||  |  |  |    |   |  |      #)" << std::endl;
			std::cout << R"(#   ||\\   ||  |==|  |==  |   |  |_     #)" << std::endl;
			std::cout << R"(#   || \\  ||  |  |  |__  |___|  |_|    #)" << std::endl;
			std::cout << R"(#          __   _              \        #)" << std::endl;
			std::cout << R"(#         |    |_|  |  /|               #)" << std::endl;
			std::cout << R"(#         |    |    | / |               #)" << std::endl;
			std::cout << R"(#         |    |    |/  |               #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;
			std::cout << R"(#                                       #)" << std::endl;

			temp = "#       Твій рахунок ";
		}
		temp += std::to_string(score);
		while (temp.size() < 40)
			temp += ' ';
		temp += '#';
		std::cout << temp << std::endl;
		if (lang == english)
			temp = "#       Your best score is ";
		else
			temp = "#       Твій найкращий рахунок ";
		temp += std::to_string(bestScore);
		while (temp.size() < 40)
			temp += ' ';
		temp += '#';
		std::cout << temp << std::endl;

		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#                                       #)" << std::endl;

		if (lang == english)
			std::cout << R"(#             >Press enter              #)" << std::endl;
		else
			std::cout << R"(#            >Натисни Enter             #)" << std::endl;

		std::cout << R"(#                                       #)" << std::endl;
		std::cout << R"(#########################################)" << std::endl;

		while (!GetAsyncKeyState(VK_RETURN))
		{
		}
	}

	void renderMenu()
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		for (size_t i = 0; i < menu.size(); i++)
			std::cout << menu[i] << std::endl;
	}

	std::string getColourCode() { return std::string(backGroundColourCode + textColourCode); }
};