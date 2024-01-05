/*
 *
 * !!! WARNING !!!
 *
 * this code absolutely must be cleaned up!
 *
 * (this project is more than a year old.
 *  I don't write messed up code like this anymore)
 *
 */



#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

// hero //
char hero = '@';

// start location //
int x = 3;
int y = 2;

// moving a hero //
void up();
void down();
void left();
void right();

// maps //
void map_1();
void map_2();
void map_3();
void map_4();
void map_5();

void the_end();

void set_y(int set_y);

// colision //
string colision_map;
bool bad[3451];  // 119*29
int place = 241;

void check_colision();

// timer //
clock_t start;
double score;

// setting current cursor location //
void current();

// making cursor invincible //
void cursor_visibility(bool visible);

// specyfying windows width && height
void ConsoleCenterWindow(int consoleWidth, int consoleHeight);

int main()
{
	system("title the maze");
	
	ConsoleCenterWindow(1000, 580);
	
	cursor_visibility(false);
	
	start = clock();
	
	while(1)
	{	
		SetConsoleTextAttribute(console, 3);
		
									map_1();
		if (CursorPosition.Y >= 16) map_2();
		if (CursorPosition.X >= 34) map_3();
		if (CursorPosition.X >= 85) map_4();
		if (CursorPosition.X <= 85 && CursorPosition.X >= 34 && CursorPosition.Y <= 16) map_5();
		
		if (CursorPosition.X == 44 && CursorPosition.Y == 10) the_end();
		
		SetConsoleTextAttribute(console, 14);
		
		cout << hero;
		
		char moving = getch();

		switch(moving)
		{
			// a-w-s-d //
			case 'a': left();  break;
			case 'w': up();    break;
			case 's': down();  break;
			case 'd': right(); break;
			// arrrow keys //
			case 75:  left();  break;
			case 72:    up();  break;
			case 80:  down();  break;
			case 77: right();  break;
			
		}
		check_colision();
	}
}

// maps //

void map_1()
{
	CursorPosition.X = 0;
	CursorPosition.Y = 0;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "###################################" << endl
		 << "#     #     #                     #" << endl
		 << "#     #                           #" << endl
		 << "#     #                           #" << endl
		 << "#     #           #####     #     #" << endl
		 << "#     #     #     #         #     #" << endl
		 << "#     #     #     #         #     #" << endl
		 << "#     #     #     #         #     #" << endl
		 << "#     #     #     #     #####     #" << endl
		 << "#           #     #         #     #" << endl
		 << "#           #     #         #     #" << endl
		 << "#                 #         #     #" << endl
		 << "#     #           #####     #     #" << endl
		 << "#     #           #         #     #" << endl
		 << "#     #           #         #     #" << endl
		 << "#     #           #         #     #" << endl
		 << "###################     ###########" << endl;
		 
	current();
}

void map_2()
{
	CursorPosition.X = 0;
	CursorPosition.Y = 16;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "###################     ###########" << endl
		 << "#                 ##   ##         #" << endl
		 << "#   ######   #######   ##  #  ##  #" << endl
		 << "#   #                      #  ##  #" << endl
		 << "#   ################   #####  ##  #" << endl
		 << "#            #     #   #      ##  #" << endl
		 << "#   #  #######  #  #   #   #  ##  #" << endl
		 << "#   #        #  #  #   #   #  ##  #" << endl
		 << "#   #  #######  #  #   #   #####  #" << endl
		 << "#   #        #  #      #          #" << endl
		 << "#   #######  ######################" << endl
		 << "#         #                        " << endl
		 << "###################################" << endl;
		 
	current();	 
}

void map_3()
{
	CursorPosition.X = 34;
	CursorPosition.Y = 16;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "####################################################" << endl; set_y(17);
	cout << "#     #     #     ####              #        #     #" << endl; set_y(18);
	cout << "#  #     #     #  ####  #######  #  #  ####  ####  #" << endl; set_y(19);
	cout << "#  #############  ####  #     #  #        #  #  #  #" << endl; set_y(20);
	cout << "#  #           #     ####  #  #  #  #######     #  #" << endl; set_y(21);
	cout << "#  #  #######  #  #        #     #        ####     #" << endl; set_y(22);
	cout << "#  #     #  #  #  ######################  #  ####  #" << endl; set_y(23);
	cout << "#  ####  #  #  #              #        #  #  #     #" << endl; set_y(24);
	cout << "#     #  #  #  ################  ####  #  #  #  ####" << endl; set_y(25);
	cout << "#  #     #  #        #        #     #  #     #      " << endl; set_y(26);
	cout << "#  #######  #  ####  ####  #  ####  #  #############" << endl; set_y(27);
	cout << "            #  #           #        #              #" << endl; set_y(28);
	cout << "####################################################" << endl;
		 
	current();	 
}

void map_4()
{
	CursorPosition.X = 85;
	CursorPosition.Y = 0;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "##################################" << endl; set_y(1);
	cout << "#               #                #" << endl; set_y(2);
	cout << "#### #########  ###############  #" << endl; set_y(3);
	cout << "   # #       #  #        #       #" << endl; set_y(4);
	cout << "#  ########  #  #  ####  #  ######" << endl; set_y(5);
	cout << "#       #    #     #     #       #" << endl; set_y(6);
	cout << "####### # #  #######  #########  #" << endl; set_y(7);
	cout << "#     #   #        #          #  #" << endl; set_y(8);
	cout << "#  ############### #######  ###  #" << endl; set_y(9);
	cout << "#                # #     #       #" << endl; set_y(10);
	cout << "###############  # #  #  ######  #" << endl; set_y(11);
	cout << "#                # #  #       #  #" << endl; set_y(12);
	cout << "#  ## # ####  #  # #  #########  #" << endl; set_y(13);
	cout << "#   # # #     #  #            #  #" << endl; set_y(14);
	cout << "##  # # #  #  #  ###  ######  #  #" << endl; set_y(15);
	cout << "#   # # #  #  #    #       #     #" << endl; set_y(16);
	cout << "#  ## ###  ##############  #######" << endl; set_y(17);
	cout << "#   # #                 #        #" << endl; set_y(18);
	cout << "##  ###  #####  ######  #######  #" << endl; set_y(19);
	cout << "#            #       #        #  #" << endl; set_y(20);
	cout << "#  #  #####  # ####  ##########  #" << endl; set_y(21);
	cout << "#  #  #      # #  #           #  #" << endl; set_y(22);
	cout << "#  #  #####  ###  ##########  #  #" << endl; set_y(23);
	cout << "#  #           #  #           #  #" << endl; set_y(24);
	cout << "####  ##########  #  ##########  #" << endl; set_y(25);
	cout << "               #              #  #" << endl; set_y(26);
	cout << "#####  #########  #############  #" << endl; set_y(27);
	cout << "#                                #" << endl; set_y(28);
	cout << "##################################" << endl;
		 
	current();
}

void map_5()
{
	CursorPosition.X = 34;
	CursorPosition.Y = 0;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "####################################################" << endl; set_y(1);
	cout << "#       #     #    #   #             #   #   #     #" << endl; set_y(2);
	cout << "#### ## # ### # ## # # # ######### # # #   #   # # #" << endl; set_y(3);
	cout << "#     #   #   #  # # # # #  #    # ### ######### #  " << endl; set_y(4);
	cout << "# ######### #### #   #   #    #        #         # #" << endl; set_y(5);
	cout << "#  #      # #  # # ##################  ########### #" << endl; set_y(6);
	cout << "## #  ##### #    # #                #    # #     # #" << endl; set_y(7);
	cout << "#  #  #   # #  ### # ##### ######## #  # # # ### # #" << endl; set_y(8);
	cout << "# ## ## ### #      # #   # #      # #  ### # # # # #" << endl; set_y(9);
	cout << "# #     #   #  ##### # # # # ###### #    # # # #   #" << endl; set_y(10);
	cout << "# # ##### O #  #     # #   # #      ###  # # # ### #" << endl; set_y(11);
	cout << "# #     #   #  # ##### ##### # ######    # # #     #" << endl; set_y(12);
	cout << "# ##### ######## #   #     # # #    # #### # ##### #" << endl; set_y(13);
	cout << "#     #          # # ##### # #   ##              # #" << endl; set_y(14);
	cout << "##### ############ # #   # # ##################### #" << endl; set_y(15);
	cout << "#                  #   #   #                       #" << endl; set_y(16);
	cout << "####################################################" << endl;
	
	CursorPosition.X = 44;
	CursorPosition.Y = 10;
	SetConsoleCursorPosition(console, CursorPosition);
	
	SetConsoleTextAttribute(console, 12);
	
	cout << 'O';
	
	current();	 
}

void the_end()
{
	score = (clock() - start) / (double) CLOCKS_PER_SEC;
	
	hero = ' ';
		
	system("CLS");
	
	// zapis zdobytego wyniku do pliku
	fstream file("scores.txt", ios::app);
	
	if (file.good() != true) score = 999.999;
	
	file << score << endl;
	
	file.close();
	
	// odczyt wszystkich wynikow z pliku
	fstream get_score("scores.txt", ios::in);
	char line[100];
	double all_scores[1000];
	int i=0;
	
	while(get_score.getline(line, 100))
	{
		all_scores[i] = atof(line);
		++i;
	}
	
	get_score.close();
	
	// odczyt najlepszego wyniku
	double best_score = all_scores[0];
	
	for (int j=1; j<i; j++) if (all_scores[j] < best_score) best_score = all_scores[j];
	
	// zapis otrzymanego i najlepszego wyniku w konsoli
	CursorPosition.X = 50;
	CursorPosition.Y = 10;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "Your score: " << score << 's';
	
	CursorPosition.X = 46;
	CursorPosition.Y = 12;
	SetConsoleCursorPosition(console, CursorPosition);
	
	cout << "The best score: " << best_score << 's';
	
	while(1) hero = getch();
}

// moving a hero //
// when hero is moving in any direction he is also moving
// on an invisible colision_map which is detecting collision
void up()
{
	y--;
	
	place -= 119;
	
	// collision
	// +199 is an index under actual "position" on a colision_map
	if (bad[place] == true) { y++; place += 119; }
	
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void down()
{
	y++;
	
	place += 119;
	
	// collision
	// -199 is an index above actual "position" on a colision_map
	if (bad[place] == true) { y--; place -= 119; }
	
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void left()
{
	x--;
	
	place -= 1;
	
	// collision
	if (bad[place] == true) { x++; place += 1; }
	
	CursorPosition.X = x;
	SetConsoleCursorPosition(console, CursorPosition);
}

void right()
{
	x++;
	
	place += 1;
	
	// collision
	if (bad[place] == true) { x--; place -= 1; }
	
	CursorPosition.X = x;
	SetConsoleCursorPosition(console, CursorPosition);
}


void current()
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void set_y(int set_y)
{
	CursorPosition.Y = set_y;
	SetConsoleCursorPosition(console, CursorPosition);
}

// ustawianie kursora jako niewidoczny
void cursor_visibility(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void check_colision()
{
	colision_map = "#######################################################################################################################"
	   	   		   "#     #     #                     #       #     #    #   #             #   #   #     #               #                #"
		    	   "#     #                           #### ## # ### # ## # # # ######### # # #   #   # # #### #########  ###############  #"
		   		   "#     #                           #     #   #   #  # # # # #  #    # ### ######### #    # #       #  #        #       #"
		   		   "#     #           #####     #     # ######### #### #   #   #    #        #         # #  ########  #  #  ####  #  ######"
		   		   "#     #     #     #         #     #  #      # #  # # ##################  ########### #       #    #     #     #       #"
		   		   "#     #     #     #         #     ## #  ##### #    # #                #    # #     # ####### # #  #######  #########  #"
		   		   "#     #     #     #         #     #  #  #   # #  ### # ##### ######## #  # # # ### # #     #   #        #          #  #"
		   		   "#     #     #     #     #####     # ## ## ### #      # #   # #      # #  ### # # # # #  ############### #######  ###  #"
		   		   "#           #     #         #     # #     #   #  ##### # # # # ###### #    # # # #   #                # #     #       #"
		   		   "#           #     #         #     # # ##### O #  #     # #   # #      ###  # # # ### ###############  # #  #  ######  #"
		   		   "#                 #         #     # #     #   #  # ##### ##### # ######    # # #     #                # #  #       #  #"
		   		   "#     #           #####     #     # ##### ######## #   #     # # #    # #### # ##### #  ## # ####  #  # #  #########  #"
		   		   "#     #           #         #     #     #          # # ##### # #   ##              # #   # # #     #  #            #  #"
		   		   "#     #           #         #     ##### ############ # #   # # ##################### ##  # # #  #  #  ###  ######  #  #"
		   		   "#     #           #         #     #                  #   #   #                       #   # # #  #  #    #       #     #"
		   		   "###################     ##############################################################  ## ###  ##############  #######"
		   		   "#                 ##   ##         #     #     #     ####              #        #     #   # #                 #        #"
		   		   "#   ######   #######   ##  #  ##  #  #     #     #  ####  #######  #  #  ####  ####  ##  ###  #####  ######  #######  #"
		   		   "#   #                      #  ##  #  #############  ####  #     #  #        #  #  #  #            #       #        #  #"
		   		   "#   ################   #####  ##  #  #           #     ####  #  #  #  #######     #  #  #  #####  # ####  ##########  #"
		   		   "#            #     #   #      ##  #  #  #######  #  #        #     #        ####     #  #  #      # #  #           #  #"
		   		   "#   #  #######  #  #   #   #  ##  #  #     #  #  #  ######################  #  ####  #  #  #####  ###  ##########  #  #"
		   		   "#   #        #  #  #   #   #  ##  #  ####  #  #  #              #        #  #  #     #  #           #  #           #  #"
		   		   "#   #  #######  #  #   #   #####  #     #  #  #  ################  ####  #  #  #  #######  ##########  #  ##########  #"
		   		   "#   #        #  #      #          #  #     #  #        #        #     #  #     #                    #              #  #"
		   		   "#   #######  ######################  #######  #  ####  ####  #  ####  #  #################  #########  #############  #"
		   		   "#         #                                   #  #           #        #              #                                #"
		   		   "#######################################################################################################################";
	
	bad[colision_map.length()];
	for(int i=0; i<colision_map.size(); i++)
	{
		bad[i] = false;
		if (colision_map[i] == '#') bad[i] = true;
	}
}

void ConsoleCenterWindow(int consoleWidth, int consoleHeight)
{
    HWND consoleWindow = GetConsoleWindow();

    RECT consoleRect;
    GetWindowRect(consoleWindow, &consoleRect);

    int consoleWindowWidth = consoleRect.right - consoleRect.left;
    int consoleWindowHeight = consoleRect.bottom - consoleRect.top;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowLeft = (screenWidth - consoleWidth) / 2;
    int windowTop = (screenHeight - consoleHeight) / 2;

    MoveWindow(consoleWindow, windowLeft, windowTop, consoleWidth, consoleHeight, TRUE);
}
