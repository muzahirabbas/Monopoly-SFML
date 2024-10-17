#include <basic.h>
static int players = 2;
static int ply[4];
static int plx[4];
Text txtP[4];
class boardGraph :public baseGame{
public:
	Texture tx[29];
	Sprite spr[29];
	Image im[29];
	boardGraph(){
		im[0].loadFromFile("resources/go.png");
		im[1].loadFromFile("resources/grey1.png");
		im[2].loadFromFile("resources/chest1.png");
		im[3].loadFromFile("resources/grey2.png");
		im[4].loadFromFile("resources/grey3.png");
		im[5].loadFromFile("resources/tax1.png");
		im[6].loadFromFile("resources/railroad1.png");
		im[7].loadFromFile("resources/park.png");
		im[8].loadFromFile("resources/E1.png");
		im[9].loadFromFile("resources/gold1.png");
		im[10].loadFromFile("resources/tax2.png");
		im[11].loadFromFile("resources/gold2.png");
		im[12].loadFromFile("resources/chest2.png");
		im[13].loadFromFile("resources/gold3.png");
		im[14].loadFromFile("resources/jail1.png");
		im[15].loadFromFile("resources/chance1.png");
		im[16].loadFromFile("resources/red1.png");
		im[17].loadFromFile("resources/railroad2.png");
		im[18].loadFromFile("resources/E2.png");
		im[19].loadFromFile("resources/red2.png");
		im[20].loadFromFile("resources/red3.png");
		im[21].loadFromFile("resources/jail2.png");
		im[22].loadFromFile("resources/yellow1.png");
		im[23].loadFromFile("resources/chance2.png");
		im[24].loadFromFile("resources/tax3.png");
		im[25].loadFromFile("resources/chest3.png");
		im[26].loadFromFile("resources/yellow2.png");
		im[27].loadFromFile("resources/yellow3.png");
		im[28].loadFromFile("resources/main.png");

		for (int i = 0, j = 0; i < 29; i++)
		{
			tx[i].loadFromImage(im[i]);
			spr[i].setTexture(tx[i]);
			if (i == 0 || i == 7 || i == 14 || i == 21)
				spr[i].setScale((2 * (midx / 8)) / tx[i].getSize().x, (midy / 2.3) / tx[i].getSize().x);
			else if ((i>0 && i < 7) || (i>14 && i < 21))
				spr[i].setScale((midx / 7) / tx[i].getSize().x, (midy / 4.5) / tx[i].getSize().x);
			else if ((i>7 && i < 14) || (i>21 && i < 28))
				spr[i].setScale((midx / 4) / tx[i].getSize().x, (midy / 3) / tx[i].getSize().x);
			else if (i == 28)
				spr[i].setScale((midx / 1.17) / tx[i].getSize().x, (midy + midy / 4.5) / tx[i].getSize().x);
		}
		spr[1].setPosition(4 * (midx / 16), 0);
		spr[20].setPosition(4 * (midx / 16), 7.5 * (midy / 4.8));
		spr[2].setPosition(5.5 * (midx / 14), 0);
		spr[19].setPosition(5.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[3].setPosition(7.5 * (midx / 14), 0);
		spr[18].setPosition(7.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[4].setPosition(9.5 * (midx / 14), 0);
		spr[17].setPosition(9.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[5].setPosition(11.5 * (midx / 14), 0);
		spr[6].setPosition(13.5 * (midx / 14), 0);
		spr[16].setPosition(11.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[15].setPosition(13.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[7].setPosition(15.5 * (midx / 14), 0);
		spr[14].setPosition(15.5 * (midx / 14), 7.5 * (midy / 4.8));
		spr[27].setPosition(0, 1.5 * (midy / 4.8));
		spr[26].setPosition(0, 2.5 * (midy / 4.8));
		spr[25].setPosition(0, 3.5 * (midy / 4.8));
		spr[24].setPosition(0, 4.5 * (midy / 4.8));
		spr[23].setPosition(0, 5.5 * (midy / 4.8));
		spr[22].setPosition(0, 6.5 * (midy / 4.8));
		spr[21].setPosition(0, 7.5 * (midy / 4.8));
		spr[8].setPosition(15.5 * (midx / 14), 1.5 * (midy / 4.8));
		spr[9].setPosition(15.5 * (midx / 14), 2.5 * (midy / 4.8));
		spr[10].setPosition(15.5 * (midx / 14), 3.5 * (midy / 4.8));
		spr[11].setPosition(15.5 * (midx / 14), 4.5 * (midy / 4.8));
		spr[12].setPosition(15.5 * (midx / 14), 5.5 * (midy / 4.8));
		spr[13].setPosition(15.5 * (midx / 14), 6.5 * (midy / 4.8));
		spr[28].setPosition(4 * (midx / 16), 1.5 * (midy / 4.8));
	}
	void draw(){
		for (int i = 0; i < 29; i++)
			window.draw(spr[i]);
	}
};
class diceRoll :public baseGame{
protected:
	Text dice[2];
	int diceface;
	int diceface2;
	Image dice1;
	Texture dice1T;
	Sprite dice1S;
	Image dice2;
	Texture dice2T;
	Sprite dice2S;
public:
	diceRoll(){
		diceface = 1;
		diceface2 = 1;
	}
	int roll(){
		dice1.loadFromFile("resources/dice.png");
		dice1T.loadFromImage(dice1);
		dice1S.setTexture(dice1T);
		dice2.loadFromFile("resources/diceW.png");
		dice2T.loadFromImage(dice2);
		dice2S.setTexture(dice2T);
		dice1S.setScale(2 * (midx / dice1T.getSize().x), 2 * (midy / dice1T.getSize().y));
		dice2S.setScale(2 * (midx / dice2T.getSize().x), 2 * (midy / dice2T.getSize().y));
		dice2S.setPosition(midx + midx / 4, midy);
		dice[0].setFont(font1);
		dice[0].setCharacterSize(70);
		dice[0].setColor(Color::Blue);
		dice[0].setPosition(midx + (midx / 2), midy - (midy / 2));
		dice[1].setCharacterSize(70);
		dice[1].setFont(font1);
		dice[1].setColor(Color::Blue);
		dice[1].setPosition(midx - (midx / 2), midy + (midy / 2));
		for (;;)
		{
			dice[0].setString(toString(diceface));
			dice[1].setString(toString(diceface2));
			(diceface2 == 5) ? dice2S.setTextureRect(IntRect(460, 540, 460, 460)) : (diceface2 == 4) ? dice2S.setTextureRect(IntRect(0, 540, 460, 460)) : (diceface2 == 6) ? dice2S.setTextureRect(IntRect(960, 540, 460, 460)) : (diceface2 == 3) ? dice2S.setTextureRect(IntRect(960, 0, 460, 460)) : (diceface2 == 2) ? dice2S.setTextureRect(IntRect(460, 0, 460, 460)) : dice2S.setTextureRect(IntRect(0, 0, 460, 460));
			(diceface == 5) ? dice1S.setTextureRect(IntRect(230, 220, 220, 220)) : (diceface == 4) ? dice1S.setTextureRect(IntRect(0, 220, 220, 220)) : (diceface == 6) ? dice1S.setTextureRect(IntRect(450, 220, 220, 220)) : (diceface == 3) ? dice1S.setTextureRect(IntRect(450, 0, 220, 220)) : (diceface == 2) ? dice1S.setTextureRect(IntRect(230, 0, 220, 220)) : dice1S.setTextureRect(IntRect(0, 0, 220, 220));
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				window.clear();
				window.draw(dice1S);
				window.draw(dice[0]);
				window.draw(dice2S);
				window.draw(dice[1]);
				window.display();
				Sleep(400);
				return diceface + diceface2;
			}
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.clear();
			window.setView(full);
			window.draw(dice1S);
			window.draw(dice[0]);
			window.draw(dice2S);
			window.draw(dice[1]);
			Sleep(50);
			diceface = rand() % 6 + 1;
			diceface2 = rand() % 6 + 1;
			window.display();
		}
	}
};
diceRoll dice;
boardGraph boardG;
baseGame::baseGame(){
	srand(time(NULL));
	font1.loadFromFile("resources/c.ttf");
	font2.loadFromFile("resources/Days.otf");
	txtP[0].setColor(Color::White);
	txtP[0].setCharacterSize(20);
	txtP[0].setFont(font2);
	txtP[0].setPosition(midx + (midx / 2.3), 0);
	txtP[1].setColor(Color::White);
	txtP[1].setCharacterSize(20);
	txtP[1].setFont(font2);
	txtP[1].setPosition(midx + (midx / 2.3), midy / 2);
	txtP[2].setColor(Color::White);
	txtP[2].setCharacterSize(20);
	txtP[2].setFont(font2);
	txtP[2].setPosition(midx + (midx / 2.3), midy);
	txtP[3].setColor(Color::White);
	txtP[3].setCharacterSize(20);
	txtP[3].setFont(font2);
	pass.setColor(Color::White);
	pass.setCharacterSize(40);
	pass.setFont(font2);
	pass.setPosition(midx - (midx / 1.5), midy);
	pass.setString("You just reached the end of the board\n200 balance is granted as reward");
	txtP[3].setPosition(midx + (midx / 2.3), midy + (midy / 2));
	plx[0] = 2;
	plx[1] = 2 + (midx / 18);
	plx[2] = 2;
	plx[3] = 2 + (midx / 18);
	ply[0] = 2;
	ply[1] = 2;
	ply[2] = 2 + (midy / 13);
	ply[3] = 2 + (midy / 13);
	ix0019 = midx / 4;
	ix = midx / 7;
	iy1427 = (2 + midy / 3.1);
	iy = midy / 4.5;
	turn = 0;
}
class mainMenu:public baseGame{
protected:
	int place;
	Image img;
	Sprite s;
	Texture t;
	int level;
	Text txt[13];
	Music bgm;
public:
	mainMenu(){
		level = 1;
		place = 80;
		img.loadFromFile("resources/m.jpg");
		t.loadFromImage(img);
		s.setTexture(t);
		s.setScale(float(winx / float(t.getSize().x)), float(winy / float(t.getSize().y)));
		bgm.openFromFile("resources/mainBGM.ogg");
		bgm.setLoop(true);
		bgm.play();
}
void startMenuGraph(){
	txt[0].setStyle(Text::Bold | Text::Italic);
	txt[0].setFont(font1);
	txt[0].setString("Press Enter to start...");
	txt[0].setCharacterSize(60);
	txt[0].setColor(ColorN(4));
	txt[0].setPosition((midx)-midx / 2, midy - 30.0);
	txt[1].setStyle(Text::Bold | Text::Italic);
	txt[1].setFont(font2);
	txt[1].setString("Start Game");
	txt[1].setCharacterSize(30);
	txt[1].setColor(Color::Red);
	txt[1].setPosition((midx)-midx / 2, midy + (midy / 2) - 80);
	txt[2].setStyle(Text::Bold | Text::Italic);
	txt[2].setFont(font2);
	txt[2].setString("How to play?");
	txt[2].setCharacterSize(30);
	txt[2].setColor(Color::Red);
	txt[2].setPosition((midx)-midx / 2, midy + (midy / 2) - 40);
	txt[3].setStyle(Text::Bold | Text::Italic);
	txt[3].setFont(font1);
	txt[3].setString("Monopoly++");
	txt[3].setCharacterSize(60);
	txt[3].setColor(Color::Red);
	txt[3].setPosition((midx)-midx / 2, midy - 30);
	txt[4].setStyle(Text::Bold | Text::Italic);
	txt[4].setFont(font2);
	txt[4].setString("Credits");
	txt[4].setCharacterSize(30);
	txt[4].setColor(Color::Red);
	txt[4].setPosition((midx)-midx / 2, midy + (midy / 2));
	txt[5].setStyle(Text::Bold | Text::Italic);
	txt[5].setFont(font2);
	txt[5].setCharacterSize(30);
	txt[5].setColor(Color::Red);
	txt[5].setPosition((midx)-midx / 2, midy + (midy / 2));
	txt[6].setStyle(Text::Bold | Text::Italic);
	txt[6].setFont(font2);
	txt[6].setString("Number of players?? <- ->\nPress Enter to start the game ");
	txt[6].setCharacterSize(30);
	txt[6].setColor(Color::Red);
	txt[6].setPosition((midx)-midx / 2, midy + (midy / 2) - 80);
	txt[7].setStyle(Text::Bold | Text::Italic);
	txt[7].setFont(font2);
	txt[7].setString("Monopoly game\nMade by \nSyed Muzahir Abbas \nNabeel Hussain Syed\nSEECs -BSCS-5A");
	txt[7].setCharacterSize(30);
	txt[7].setColor(Color::Red);
	txt[7].setPosition((midx)-midx / 2, midy + (midy / 2) - 80);
	txt[8].setStyle(Text::Bold | Text::Italic);
	txt[8].setFont(font2);
	txt[8].setString("For game info\nPlease visit : en.wikipedia.org/monopoly");
	txt[8].setCharacterSize(30);
	txt[8].setColor(Color::Red);
	txt[8].setPosition((midx)-midx / 2, midy + (midy / 2) - 80);
	txt[9].setStyle(Text::Bold | Text::Italic);
	txt[9].setFont(font2);
	txt[9].setString(">>");
	txt[9].setCharacterSize(30);
	txt[9].setColor(Color::Red);
	txt[10].setStyle(Text::Bold | Text::Italic);
	txt[10].setFont(font1);
	txt[10].setString("Exit Game??");
	txt[10].setCharacterSize(60);
	txt[10].setColor(Color::Red);
	txt[10].setPosition((midx)-midx / 2, midy - 30);
	txt[11].setStyle(Text::Bold | Text::Italic);
	txt[11].setFont(font2);
	txt[11].setString("Enter (Yes)                  Escape (No)");
	txt[11].setCharacterSize(30);
	txt[11].setColor(Color::Red);
	txt[11].setPosition((midx)-midx / 2, midy + (midy / 2));
	txt[12].setStyle(Text::Bold | Text::Italic);
	txt[12].setFont(font2);
	txt[12].setString("Return(Next | Escape(Back/Exit))");
	txt[12].setCharacterSize(15);
	txt[12].setColor(Color::Red);
	txt[12].setPosition(0, 0);
		for (; level < 8;)
		{
			txt[5].setString(toString(players));
			txt[9].setPosition((midx)-midx / 2 - (80), midy + (midy / 2) - place);
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				window.clear();
				window.draw(s);
				window.setView(full);
				window.draw(txt[12]);
				if (level == 0)
				{
					window.draw(txt[11]);
					window.draw(txt[10]);
					if (level == 0 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape){
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							level = 2;
						}
					}
					if (level == 0 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Return){
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							bgm.stop();
							exit(0);
						}
					}
				}
				else if (level == 1)
				{
					window.draw(txt[0]);
					if (level == 1 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Return){
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							level++;
						}
					}
				}
				else if (level == 2)
				{
					window.draw(txt[1]);
					window.draw(txt[2]);
					window.draw(txt[3]);
					window.draw(txt[4]);
					window.draw(txt[9]);
					if (level == 2 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							level -= 2;
						}
					}
					if (level == 2 && (Keyboard::isKeyPressed(Keyboard::Down)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						if (place == 0)
							place = 80;
						else
							place -= 40;

					}
					else if (level == 2 && (Keyboard::isKeyPressed(Keyboard::Up)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						if (place == 80)
							place == 0;
						else
							place += 40;
					}
					if (place == 80 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Return)
						{
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							level++;
						}
					}
					if (place == 40 && (Keyboard::isKeyPressed(Keyboard::Return)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						level += 2;
					}
					else if (place == 0 && (Keyboard::isKeyPressed(Keyboard::Return)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						level += 3;
					}
				}
				else if (level == 3)
				{
					window.draw(txt[5]);
					window.draw(txt[3]);
					window.draw(txt[6]);
					if (level == 3 && event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Return){
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							level += 5;
							bgm.stop();
							break;
						}
					}
					if (level == 3 && (Keyboard::isKeyPressed(Keyboard::Right)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						if (players == 4)
							players = 2;
						else
							players++;
					}
					else if (level == 3 && (Keyboard::isKeyPressed(Keyboard::Left)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						if (players == 2)
							players = 4;
						else
							players--;
					}
					else if (level == 3 && (Keyboard::isKeyPressed(Keyboard::Escape)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						level--;
					}
				}
				else if (level == 4)
				{
					window.draw(txt[8]);
					window.draw(txt[3]);
					if (level == 4 && (Keyboard::isKeyPressed(Keyboard::Escape)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						level -= 2;
					}
				}
				else if (level == 5)
				{
					window.draw(txt[7]);
					window.draw(txt[3]);
					if (level == 5 && (Keyboard::isKeyPressed(Keyboard::Escape)))
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						level -= 3;
					}
				}
				window.display();
			}

		}
	}
};
class playerC :public baseGame{
public:
	int playerNum;
	Color playerColor;
	int playerBalance;
	int jailOutCards;
	Image playerI;
	Texture playerT;
	Sprite playerB;
	int plrPlace;
	playerC(){
		playerNum = 0;
		playerBalance = 2000;
	}
	string selectT(int x){
		std::ostringstream oss;
		if (x == 1)
		{
			oss << "resources/p1.png";
			return oss.str();
		}
		else if (x == 2)
		{
			oss << "resources/p2.png";
			return oss.str();
		}
		else if (x == 3)
		{
			oss << "resources/p3.png";
			return oss.str();
		}
		else if (x == 4)
		{
			oss << "resources/p4.png";
			return oss.str();
		}
	}
	void setSprite(int y){
		playerI.loadFromFile(selectT(y));
		playerT.loadFromImage(playerI);
		playerB.setTexture(playerT);
		playerB.setScale((midx/18) / playerT.getSize().x, (midy/13) / playerT.getSize().y);
	}
};
class places{
public:
	int owner;
	int cost;
	int num;
	string name;
};
class jail{
public:
	int num;
	int tax;
};
class railroads :public virtual places{
public:
	int tax;
};
class cards{
public:
	int num;
};
class commChest :public virtual cards{
public:
};
class chance :public virtual cards{
public:
};
class uti :public virtual places{
public:
	int tax;
};
class streets :public virtual places{
public:
	char color;
	int houses;
	int tax;
};
class tax{
public:
	int num;
	int amount;
};
class board:public baseGame{
public:
	jail jj;
	streets strt[12];
	commChest cCh[3];
	uti U[2];
	railroads rRoad[2];
	tax t[3];
	chance chc[2];
	Text msg[10];
	board(){
		U[0].cost = 150;
		U[0].name = "Electric company";
		U[0].owner = 5;
		U[0].tax = 40;
		U[1].cost = 180;
		U[1].name = "Steel Mill";
		U[1].owner = 5;
		U[1].tax = 40;
		rRoad[0].cost = 150;
		rRoad[0].name = "RailRoad 1";
		rRoad[0].owner = 5;
		rRoad[0].tax = 40;
		rRoad[1].cost = 180;
		rRoad[1].name = "RailRoad 2";
		rRoad[1].owner = 5;
		rRoad[1].tax = 40;
		strt[0].cost = 210;
		strt[0].houses = 0;
		strt[0].owner = 5;
		strt[0].tax = 50;
		strt[0].name = "Centaurus";
		strt[1].cost = 200;
		strt[1].houses = 0;
		strt[1].owner = 5;
		strt[1].tax = 30;
		strt[1].name = "Academy Road";
		strt[2].cost = 200;
		strt[2].num = 0;
		strt[2].owner = 5;
		strt[2].tax = 40;
		strt[2].name = "Wilson Road";
		strt[3].cost = 110;
		strt[3].num = 0;
		strt[3].owner = 5;
		strt[3].tax = 40;
		strt[3].name = "Monal";
		strt[4].cost = 130;
		strt[4].num = 0;
		strt[4].owner = 5;
		strt[4].tax = 35;
		strt[4].name = "Margalla Road";
		strt[5].cost = 100;
		strt[5].num = 0;
		strt[5].owner = 5;
		strt[5].tax = 30;
		strt[5].name = "Satellite Town";
		strt[6].cost = 100;
		strt[6].num = 0;
		strt[6].owner = 5;
		strt[6].tax = 40;
		strt[6].name = "Jinnah Park";
		strt[7].cost = 110;
		strt[7].num = 0;
		strt[7].owner = 5;
		strt[7].tax = 25;
		strt[7].name = "Gulshan Town";
		strt[8].cost = 80;
		strt[8].num = 0;
		strt[8].owner = 5;
		strt[8].tax = 30;
		strt[8].name = "Murree Street";
		strt[9].cost = 120;
		strt[9].num = 0;
		strt[9].owner = 5;
		strt[9].tax = 50;
		strt[9].name = "Behria Town";
		strt[10].cost = 100;
		strt[10].num = 0;
		strt[10].owner = 5;
		strt[10].tax = 40;
		strt[10].name = "Quaid's Street";
		strt[11].cost = 100;
		strt[11].num = 0;
		strt[11].owner = 5;
		strt[11].tax = 20;
		strt[11].name = "Elm's street";
		jj.tax = 100;
		t[0].amount =200 ;
		t[1].amount =100 ;
		t[2].amount =100 ;
		msg[0].setFont(font2);
		msg[0].setCharacterSize(40);
		msg[0].setColor(Color::White);
		msg[0].setPosition(midx-(midx/2),midy);
		msg[0].setString("Do you want to built Houses or a town? (Y/N)");
		msg[1].setFont(font2);
		msg[1].setCharacterSize(40);
		msg[1].setColor(Color::White);
		msg[1].setPosition(midx - (midx / 2), midy-(midy/2));
		msg[1].setString("How many Houses?\n1 house cost(200) earning(+200)\n2 houses cost(400) earning(+400)\n3 houses cost(600) earning(+600)\n4 houses(town) cost(800) earning(2000) ");
		msg[2].setFont(font2);
		msg[2].setCharacterSize(40);
		msg[2].setColor(Color::White);
		msg[2].setPosition(midx - (midx / 2), midy-(midy/2));
		msg[2].setString("You are on someone else's land\nThe ammount of tax is deduced from your account \nand is paid to the owner");
		msg[3].setFont(font2);
		msg[3].setCharacterSize(40);
		msg[3].setColor(Color::White);
		msg[3].setPosition(midx - (midx / 2), midy);
		msg[3].setString("Want to buy the place?(Y/N)");
		msg[4].setFont(font2);
		msg[4].setCharacterSize(40);
		msg[4].setColor(Color::White);
		msg[4].setPosition(midx - (midx / 2), midy/4);
		msg[5].setFont(font2);
		msg[5].setCharacterSize(40);
		msg[5].setColor(Color::White);
		msg[5].setPosition(midx - (midx / 2), midy/4);
		msg[6].setFont(font2);
		msg[6].setCharacterSize(40);
		msg[6].setColor(Color::White);
		msg[6].setPosition(midx - (midx / 2), midy);
		msg[6].setString("Not enough money!\n in your account");
	}
	void doFunc(int & own,playerC plr[])
	{
		int p=own+1;
		int own2;
		int stopper;
			if (plr[own].plrPlace==1)
			{
				stopper = 0;
				if (strt[0].owner >= 1 && strt[0].owner <= 4)
				{
					if (strt[0].owner == p)
					{
						if ((strt[0].owner == strt[1].owner == strt[2].owner == p) && (strt[0].houses<4))
						{
							for (;stopper!=1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[0].houses == 3)
												{
													strt[0].houses++;
													plr[own].playerBalance -= 200;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[0].houses++;
													plr[own].playerBalance -= 200;
													strt[0].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[0].houses == 2)
												{
													strt[0].houses += 2;
													plr[own].playerBalance -= 400;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 3)
												{
													strt[0].houses++;
													plr[own].playerBalance -= 200;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[0].houses += 2;
													plr[own].playerBalance -= 400;
													strt[0].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[0].houses == 1)
												{
													strt[0].houses += 3;
													plr[own].playerBalance -= 600;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 2)
												{
													strt[0].houses += 2;
													plr[own].playerBalance -= 400;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 3)
												{
													strt[0].houses += 1;
													plr[own].playerBalance -= 200;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[0].houses += 3;
													plr[own].playerBalance -= 600;
													strt[0].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[0].owner == 0)
												{
													strt[0].houses += 4;
													plr[own].playerBalance -= 800;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 1)
												{
													strt[0].houses += 3;
													plr[own].playerBalance -= 600;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 2)
												{
													strt[0].houses += 2;
													plr[own].playerBalance -= 400;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[0].houses == 3)
												{
													strt[0].houses += 1;
													plr[own].playerBalance -= 200;
													strt[0].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : "+toString(strt[0].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[0].tax;
						own2 = strt[0].owner-1;
						plr[own2].playerBalance += strt[0].tax;
						if (plr[own].playerBalance<=0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :"+toString(strt[0].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[0].cost)
							{
								plr[own].playerBalance -= strt[0].cost;
								strt[0].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 2)
			{
				C.setCharacterSize(40);
				C.setFont(font2);
				C.setColor(Color::White);
				C.setPosition(midx - (midx / 1.2), midy - (midy / 1.2));
				C2.setCharacterSize(40);
				C2.setFont(font2);
				C2.setColor(Color::White);
				C2.setPosition(midx - (midx / 1.2), 0);
				C2.setString("Community Chest");
				int randomN;
				randomN = rand() % 6 + 1;
				if (randomN == 1)
				{
					C.setString("Move 10 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 10; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 2)
				{
					C.setString("Move 5 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 5; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 3)
				{
					C.setString("Get 500");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance += 500;
				}
				else if (randomN == 4)
				{
					C.setString("Roll dice");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					int intj;
					intj = dice.roll();
					for (int i = 0; i < intj; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 5)
				{
					C.setString("You got 1 jail out card");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].jailOutCards++;
				}
				else if (randomN == 6)
				{
					C.setString("give 200 to bank as tax");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance -= 200;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}

			}
			else if (plr[own].plrPlace == 3)
			{
				stopper = 0;
				if (strt[1].owner >= 1 && strt[1].owner <= 4)
				{
					if (strt[1].owner == p)
					{
						if ((strt[0].owner == strt[1].owner == strt[2].owner == p) && (strt[1].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[1].houses == 3)
												{
													strt[1].houses++;
													plr[own].playerBalance -= 200;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[1].houses++;
													plr[own].playerBalance -= 200;
													strt[1].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[1].houses == 2)
												{
													strt[1].houses += 2;
													plr[own].playerBalance -= 400;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 3)
												{
													strt[1].houses++;
													plr[own].playerBalance -= 200;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[1].houses += 2;
													plr[own].playerBalance -= 400;
													strt[1].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[1].houses == 1)
												{
													strt[1].houses += 3;
													plr[own].playerBalance -= 600;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 2)
												{
													strt[1].houses += 2;
													plr[own].playerBalance -= 400;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 3)
												{
													strt[1].houses += 1;
													plr[own].playerBalance -= 200;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[1].houses += 3;
													plr[own].playerBalance -= 600;
													strt[1].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[1].owner == 0)
												{
													strt[1].houses += 4;
													plr[own].playerBalance -= 800;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 1)
												{
													strt[1].houses += 3;
													plr[own].playerBalance -= 600;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 2)
												{
													strt[1].houses += 2;
													plr[own].playerBalance -= 400;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[1].houses == 3)
												{
													strt[1].houses += 1;
													plr[own].playerBalance -= 200;
													strt[1].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[1].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[1].tax;
						own2 = strt[1].owner - 1;
						plr[own2].playerBalance += strt[1].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[1].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[1].cost)
							{
								plr[own].playerBalance -= strt[1].cost;
								strt[1].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
		else if (plr[own].plrPlace == 4)
		{
			stopper = 0;
			if (strt[2].owner >= 1 && strt[2].owner <= 4)
			{
				if (strt[2].owner == p)
				{
					if ((strt[0].owner == strt[1].owner == strt[2].owner == p) && (strt[2].houses<4))
					{
						for (; stopper != 1;)
						{
							window.clear();
							window.setView(full);
							window.draw(msg[0]);
							window.display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
							{
								for (;;)
								{
									window.clear();
									window.setView(full);
									window.draw(msg[1]);
									window.display();
									if (Keyboard::isKeyPressed(Keyboard::Num1))
									{
										if (plr[own].playerBalance > 200)
										{
											if (strt[2].houses == 3)
											{
												strt[2].houses++;
												plr[own].playerBalance -= 200;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[2].houses++;
												plr[own].playerBalance -= 200;
												strt[2].tax += 200;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num2))
									{
										if (plr[own].playerBalance>400)
										{
											if (strt[2].houses == 2)
											{
												strt[2].houses += 2;
												plr[own].playerBalance -= 400;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 3)
											{
												strt[2].houses++;
												plr[own].playerBalance -= 200;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[2].houses += 2;
												plr[own].playerBalance -= 400;
												strt[2].tax += 400;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num3))
									{
										if (plr[own].playerBalance > 600)
										{
											if (strt[2].houses == 1)
											{
												strt[2].houses += 3;
												plr[own].playerBalance -= 600;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 2)
											{
												strt[2].houses += 2;
												plr[own].playerBalance -= 400;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 3)
											{
												strt[2].houses += 1;
												plr[own].playerBalance -= 200;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[2].houses += 3;
												plr[own].playerBalance -= 600;
												strt[2].tax += 600;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num4))
									{
										if (plr[own].playerBalance > 800)
										{
											if (strt[2].owner == 0)
											{
												strt[2].houses += 4;
												plr[own].playerBalance -= 800;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 1)
											{
												strt[2].houses += 3;
												plr[own].playerBalance -= 600;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 2)
											{
												strt[2].houses += 2;
												plr[own].playerBalance -= 400;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[2].houses == 3)
											{
												strt[2].houses += 1;
												plr[own].playerBalance -= 200;
												strt[2].tax = 2000;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
								}
							}
							else if (Keyboard::isKeyPressed(Keyboard::N))
							{
								break;
							}
						}
					}
				}
				else
				{
					msg[4].setString("Tax is : " + toString(strt[2].tax));
					window.clear();
					window.setView(full);
					window.draw(msg[2]);
					window.draw(msg[4]);
					window.display();
					plr[own].playerBalance -= strt[2].tax;
					own2 = strt[2].owner - 1;
					plr[own2].playerBalance += strt[2].tax;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}
			}
			else
			{
				for (;;)
				{
					msg[5].setString("cost is :" + toString(strt[2].cost));
					window.clear();
					window.setView(full);
					window.draw(msg[3]);
					window.draw(msg[5]);
					window.display();
					if (Keyboard::isKeyPressed(Keyboard::Y))
					{
						if (plr[own].playerBalance > strt[2].cost)
						{
							plr[own].playerBalance -= strt[2].cost;
							strt[2].owner = p;
							break;
						}
						else
						{
							window.clear();
							window.setView(full);
							window.draw(msg[6]);
							window.display();
							Sleep(1500);
							window.clear();
							break;
						}
					}
					else if (Keyboard::isKeyPressed(Keyboard::N))
					{
						break;
					}
				}
			}
		}
			else if (plr[own].plrPlace == 5)
			{
				Text taxt;
				taxt.setFont(font2);
				taxt.setColor(Color::White);
				taxt.setPosition(midx - (midx / 2), midy - (midy / 2));
				taxt.setCharacterSize(30);
				taxt.setString("Luxury tax of "+toString(t[0].amount)+" \nis deduced from your account");
				window.clear();
				window.setView(full);
				window.draw(taxt);
				window.display();
				Sleep(1500);
				plr[own].playerBalance -= t[0].amount;
				if (plr[own].playerBalance<=0)
				{
					bankrupt(p);
				}
			}
			else if (plr[own].plrPlace == 6)
			{
				Text textRR[3];
				textRR[0].setFont(font2);
				textRR[0].setColor(Color::White);
				textRR[0].setPosition(midx-(midx/2),midy-(midy/2));
				textRR[0].setCharacterSize(30);
				textRR[1].setFont(font2);
				textRR[1].setColor(Color::White);
				textRR[1].setPosition(midx - (midx / 2), midy - (midy / 2));
				textRR[1].setCharacterSize(30);
				textRR[2].setFont(font2);
				textRR[2].setColor(Color::White);
				textRR[2].setPosition(midx - (midx / 2), midy - (midy / 2));
				textRR[2].setCharacterSize(30);
				textRR[0].setString("On an occupied Railroad\npaying tax "+toString(rRoad[0].tax)+" to owner");
				textRR[1].setString("Do you want to buy the railroad?(Y/N)\n150");
				textRR[2].setString("Not enough money");
				if (rRoad[0].owner >=1 &&rRoad[0].owner<=4)
				{					
					if (rRoad[0].owner != p)
					{
						window.clear();
						window.setView(full);
						window.draw(textRR[0]);
						window.display();
						Sleep(2000);
						plr[own].playerBalance -= rRoad[0].tax;
						plr[rRoad[0].owner].playerBalance += rRoad[0].tax;
						if (plr[own].playerBalance <= rRoad[0].tax)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						window.clear();
						window.setView(full);
						window.draw(textRR[1]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance>rRoad[0].cost)
							{
								plr[own].playerBalance -= rRoad[0].cost;
								rRoad[0].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(textRR[2]);
								window.display();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 8)
			{
				Text textU[3];
				textU[0].setFont(font2);
				textU[0].setColor(Color::White);
				textU[0].setPosition(midx - (midx / 2), midy - (midy / 2));
				textU[0].setCharacterSize(30);
				textU[1].setFont(font2);
				textU[1].setColor(Color::White);
				textU[1].setPosition(midx - (midx / 2), midy - (midy / 2));
				textU[1].setCharacterSize(30);
				textU[2].setFont(font2);
				textU[2].setColor(Color::White);
				textU[2].setPosition(midx - (midx / 2), midy - (midy / 2));
				textU[2].setCharacterSize(30);
				textU[0].setString("On an occupied Railroad\npaying tax " + toString(U[0].tax) + " to owner");
				textU[1].setString("Do you want to buy the Electric Company?\n150");
				textU[2].setString("Not enough money");
				if (U[0].owner >= 1 && U[0].owner <= 4)
				{
					if (U[0].owner != p)
					{
						window.clear();
						window.setView(full);
						window.draw(textU[0]);
						window.display();
						Sleep(2000);
						plr[own].playerBalance -= U[0].tax;
						plr[U[0].owner].playerBalance += U[0].tax;
						if (plr[own].playerBalance <= U[0].tax)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						window.clear();
						window.setView(full);
						window.draw(textU[1]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance>U[0].cost)
							{
								plr[own].playerBalance -= U[0].cost;
								U[0].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(textU[2]);
								window.display();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 9)
			{
				stopper = 0;
				if (strt[3].owner >= 1 && strt[3].owner <= 4)
				{
					if (strt[3].owner == p)
					{
						if ((strt[3].owner == strt[5].owner == strt[4].owner == p) && (strt[3].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[3].houses == 3)
												{
													strt[3].houses++;
													plr[own].playerBalance -= 200;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[3].houses++;
													plr[own].playerBalance -= 200;
													strt[3].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[3].houses == 2)
												{
													strt[3].houses += 2;
													plr[own].playerBalance -= 400;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 3)
												{
													strt[3].houses++;
													plr[own].playerBalance -= 200;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[3].houses += 2;
													plr[own].playerBalance -= 400;
													strt[3].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[3].houses == 1)
												{
													strt[3].houses += 3;
													plr[own].playerBalance -= 600;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 2)
												{
													strt[3].houses += 2;
													plr[own].playerBalance -= 400;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 3)
												{
													strt[3].houses += 1;
													plr[own].playerBalance -= 200;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[3].houses += 3;
													plr[own].playerBalance -= 600;
													strt[3].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[3].owner == 0)
												{
													strt[3].houses += 4;
													plr[own].playerBalance -= 800;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 1)
												{
													strt[3].houses += 3;
													plr[own].playerBalance -= 600;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 2)
												{
													strt[3].houses += 2;
													plr[own].playerBalance -= 400;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[3].houses == 3)
												{
													strt[3].houses += 1;
													plr[own].playerBalance -= 200;
													strt[3].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[3].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[3].tax;
						own2 = strt[3].owner - 1;
						plr[own2].playerBalance += strt[3].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[3].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[3].cost)
							{
								plr[own].playerBalance -= strt[3].cost;
								strt[3].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
				else if (plr[own].plrPlace == 10)
				{
					Text taxt;
					taxt.setFont(font2);
					taxt.setColor(Color::White);
					taxt.setPosition(midx - (midx / 2), midy - (midy / 2));
					taxt.setCharacterSize(30);
					taxt.setString("income tax of " + toString(t[1].amount) + " \nis deduced from your account");
					window.clear();
					window.setView(full);
					window.draw(taxt);
					window.display();
					Sleep(1500);
					plr[own].playerBalance -= t[1].amount;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}
			else if (plr[own].plrPlace == 11)
			{
				stopper = 0;
				if (strt[4].owner >= 1 && strt[4].owner <= 4)
				{
					if (strt[4].owner == p)
					{
						if ((strt[4].owner == strt[5].owner == strt[3].owner == p) && (strt[4].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[4].houses == 3)
												{
													strt[4].houses++;
													plr[own].playerBalance -= 200;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[4].houses++;
													plr[own].playerBalance -= 200;
													strt[4].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[4].houses == 2)
												{
													strt[4].houses += 2;
													plr[own].playerBalance -= 400;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 3)
												{
													strt[4].houses++;
													plr[own].playerBalance -= 200;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[4].houses += 2;
													plr[own].playerBalance -= 400;
													strt[4].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[4].houses == 1)
												{
													strt[4].houses += 3;
													plr[own].playerBalance -= 600;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 2)
												{
													strt[4].houses += 2;
													plr[own].playerBalance -= 400;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 3)
												{
													strt[4].houses += 1;
													plr[own].playerBalance -= 200;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[4].houses += 3;
													plr[own].playerBalance -= 600;
													strt[4].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[4].owner == 0)
												{
													strt[4].houses += 4;
													plr[own].playerBalance -= 800;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 1)
												{
													strt[4].houses += 3;
													plr[own].playerBalance -= 600;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 2)
												{
													strt[4].houses += 2;
													plr[own].playerBalance -= 400;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[4].houses == 3)
												{
													strt[4].houses += 1;
													plr[own].playerBalance -= 200;
													strt[4].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[4].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[4].tax;
						own2 = strt[4].owner - 1;
						plr[own2].playerBalance += strt[4].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[4].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[4].cost)
							{
								plr[own].playerBalance -= strt[4].cost;
								strt[4].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 12)
			{
				C.setCharacterSize(40);
				C.setFont(font2);
				C.setColor(Color::White);
				C.setPosition(midx - (midx / 1.2), midy - (midy / 1.2));
				C2.setCharacterSize(40);
				C2.setFont(font2);
				C2.setColor(Color::White);
				C2.setPosition(midx - (midx / 1.2), 0);
				C2.setString("Community Chest");
				int randomN;
				randomN = rand() % 6 + 1;
				if (randomN == 1)
				{
					C.setString("Move 10 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 10; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							plr[own].playerBalance += 200;
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 2)
				{
					C.setString("Move 5 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 5; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 3)
				{
					C.setString("Get 500");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance += 500;
				}
				else if (randomN == 4)
				{
					C.setString("Roll dice");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					int intj;
					intj = dice.roll();
					for (int i = 0; i < intj; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < players; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 5)
				{
					C.setString("You got 1 jail out card");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].jailOutCards++;
				}
				else if (randomN == 6)
				{
					C.setString("give 200 to bank as tax");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance -= 200;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}

			}
			else if (plr[own].plrPlace == 11)
			{
				stopper = 0;
				if (strt[5].owner >= 1 && strt[5].owner <= 4)
				{
					if (strt[5].owner == p)
					{
						if ((strt[3].owner == strt[5].owner == strt[4].owner == p) && (strt[5].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[5].houses == 3)
												{
													strt[5].houses++;
													plr[own].playerBalance -= 200;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[5].houses++;
													plr[own].playerBalance -= 200;
													strt[5].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[5].houses == 2)
												{
													strt[5].houses += 2;
													plr[own].playerBalance -= 400;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 3)
												{
													strt[5].houses++;
													plr[own].playerBalance -= 200;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[5].houses += 2;
													plr[own].playerBalance -= 400;
													strt[5].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[5].houses == 1)
												{
													strt[5].houses += 3;
													plr[own].playerBalance -= 600;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 2)
												{
													strt[5].houses += 2;
													plr[own].playerBalance -= 400;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 3)
												{
													strt[5].houses += 1;
													plr[own].playerBalance -= 200;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[5].houses += 3;
													plr[own].playerBalance -= 600;
													strt[5].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[5].owner == 0)
												{
													strt[5].houses += 4;
													plr[own].playerBalance -= 800;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 1)
												{
													strt[5].houses += 3;
													plr[own].playerBalance -= 600;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 2)
												{
													strt[5].houses += 2;
													plr[own].playerBalance -= 400;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[5].houses == 3)
												{
													strt[5].houses += 1;
													plr[own].playerBalance -= 200;
													strt[5].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[5].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[5].tax;
						own2 = strt[5].owner - 1;
						plr[own2].playerBalance += strt[5].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[5].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[5].cost)
							{
								plr[own].playerBalance -= strt[5].cost;
								strt[5].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 14)
			{
				Text Jtext[3];
				Jtext[0].setFont(font2);
				Jtext[0].setCharacterSize(40);
				Jtext[0].setColor(Color::White);
				Jtext[0].setPosition(0, midy);
				Jtext[0].setString("You are in JAil\npress 1 to roll dice 3 times if full(free) if not (150)\n2 to pay normal tax (50)");
				Jtext[1].setFont(font2);
				Jtext[1].setCharacterSize(40);
				Jtext[1].setColor(Color::White);
				Jtext[1].setPosition(0, midy - (midy / 2));
				Jtext[1].setString("No jail cards\npaying normal 50 tax");
				Jtext[2].setFont(font2);
				Jtext[2].setCharacterSize(40);
				Jtext[2].setColor(Color::White);
				Jtext[2].setPosition(0, midy - (midy / 2));
				Jtext[2].setString("Jail card mis used");
				if (plr[own].jailOutCards > 0)
				{
					window.clear();
					window.setView(full);
					window.draw(Jtext[2]);
					window.display();
				}
				else if (plr[own].jailOutCards <= 0)
				{
					if (plr[own].playerBalance > 50)
					{
						for (;;)
						{
							window.clear();
							window.setView(full);
							window.draw(Jtext[0]);
							window.display();
							if (Keyboard::isKeyPressed(Keyboard::Num1))
							{
								int inc;
								inc = dice.roll();
								if (inc == 12)
								{
									for (int i = 0; i < 8; i++)
									{
										if (plr[own].plrPlace == 0)
											plx[own] += ix0019;
										else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
											plx[own] += ix;
										else if (plr[own].plrPlace == 7)
											ply[own] += iy1427;
										else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
											ply[own] += iy;
										else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
											plx[own] -= ix;
										else if (plr[own].plrPlace == 20)
											plx[own] -= ix0019;
										else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
											ply[own] -= iy;
										else if (plr[own].plrPlace == 27)
											ply[own] -= iy1427;
										for (int i = 0; i < 4; i++)
											plr[i].playerB.setPosition(plx[i], ply[i]);
										window.clear();
										window.setView(game);
										{
											boardG.draw();
											for (int j = 0; j < players; j++)
											{
												window.draw(txtP[j]);
											}
											for (int i = 0; i < players; i++)
											{
												window.draw(plr[i].playerB);
											}
										}
										window.display();
										Sleep(1000);
										if (plr[own].plrPlace == 27)
										{
											window.clear();
											window.setView(full);
											{
												window.draw(pass);
											}
											window.display();
											Sleep(1000);
											plr[own].plrPlace = 0;
											plr[own].playerBalance += 200;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
										}
										else
										{
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
											plr[own].plrPlace++;
										}
									}
									break;
								}
								else
									inc = dice.roll();
								if (inc == 12)
								{
									for (int i = 0; i < 8; i++)
									{
										if (plr[own].plrPlace == 0)
											plx[own] += ix0019;
										else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
											plx[own] += ix;
										else if (plr[own].plrPlace == 7)
											ply[own] += iy1427;
										else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
											ply[own] += iy;
										else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
											plx[own] -= ix;
										else if (plr[own].plrPlace == 20)
											plx[own] -= ix0019;
										else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
											ply[own] -= iy;
										else if (plr[own].plrPlace == 27)
											ply[own] -= iy1427;
										for (int i = 0; i < 4; i++)
											plr[i].playerB.setPosition(plx[i], ply[i]);
										window.clear();
										window.setView(game);
										{
											boardG.draw();
											for (int j = 0; j < players; j++)
											{
												window.draw(txtP[j]);
											}
											for (int i = 0; i < players; i++)
											{
												window.draw(plr[i].playerB);
											}
										}
										window.display();
										Sleep(1000);
										if (plr[own].plrPlace == 27)
										{
											window.clear();
											window.setView(full);
											{
												window.draw(pass);
											}
											window.display();
											Sleep(1000);
											plr[own].plrPlace = 0;
											plr[own].playerBalance += 200;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
										}
										else
										{
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
											plr[own].plrPlace++;
										}
									}
									break;
								}
								else
									inc = dice.roll();
								if (inc == 12)
								{
									for (int i = 0; i < 8; i++)
									{
										if (plr[own].plrPlace == 0)
											plx[own] += ix0019;
										else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
											plx[own] += ix;
										else if (plr[own].plrPlace == 7)
											ply[own] += iy1427;
										else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
											ply[own] += iy;
										else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
											plx[own] -= ix;
										else if (plr[own].plrPlace == 20)
											plx[own] -= ix0019;
										else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
											ply[own] -= iy;
										else if (plr[own].plrPlace == 27)
											ply[own] -= iy1427;
										for (int i = 0; i < 4; i++)
											plr[i].playerB.setPosition(plx[i], ply[i]);
										window.clear();
										window.setView(game);
										{
											boardG.draw();
											for (int j = 0; j < players; j++)
											{
												window.draw(txtP[j]);
											}
											for (int i = 0; i < players; i++)
											{
												window.draw(plr[i].playerB);
											}
										}
										window.display();
										Sleep(1000);
										if (plr[own].plrPlace == 27)
										{
											window.clear();
											window.setView(full);
											{
												window.draw(pass);
											}
											window.display();
											Sleep(1000);
											plr[own].plrPlace = 0;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
											plr[own].playerBalance += 200;
										}
										else
										{
											plr[own].plrPlace++;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
										}
									}
									break;
								}
								else
								{
									plr[own].playerBalance -= 150;
									for (int i = 0; i < 8; i++)
									{
										if (plr[own].plrPlace == 0)
											plx[own] += ix0019;
										else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
											plx[own] += ix;
										else if (plr[own].plrPlace == 7)
											ply[own] += iy1427;
										else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
											ply[own] += iy;
										else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
											plx[own] -= ix;
										else if (plr[own].plrPlace == 20)
											plx[own] -= ix0019;
										else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
											ply[own] -= iy;
										else if (plr[own].plrPlace == 27)
											ply[own] -= iy1427;
										for (int i = 0; i < 4; i++)
											plr[i].playerB.setPosition(plx[i], ply[i]);
										window.clear();
										window.setView(game);
										{
											boardG.draw();
											for (int j = 0; j < players; j++)
											{
												window.draw(txtP[j]);
											}
											for (int i = 0; i < players; i++)
											{
												window.draw(plr[i].playerB);
											}
										}
										window.display();
										Sleep(1000);
										if (plr[own].plrPlace == 27)
										{
											window.clear();
											window.setView(full);
											{
												window.draw(pass);
											}
											window.display();
											Sleep(1000);
											plr[own].plrPlace = 0;
											plr[own].playerBalance += 200;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
										}
										else
										{
											plr[own].plrPlace++;
											PlaySound("resources/1.wav", NULL, SND_ASYNC);
										}
									}
									break;
								}
							}
							else if (Keyboard::isKeyPressed(Keyboard::Num2))
							{
								plr[own].playerBalance -= 50;
								for (int i = 0; i < 8; i++)
								{
									if (plr[own].plrPlace == 0)
										plx[own] += ix0019;
									else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
										plx[own] += ix;
									else if (plr[own].plrPlace == 7)
										ply[own] += iy1427;
									else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
										ply[own] += iy;
									else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
										plx[own] -= ix;
									else if (plr[own].plrPlace == 20)
										plx[own] -= ix0019;
									else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
										ply[own] -= iy;
									else if (plr[own].plrPlace == 27)
										ply[own] -= iy1427;
									for (int i = 0; i < 4; i++)
										plr[i].playerB.setPosition(plx[i], ply[i]);
									window.clear();
									window.setView(game);
									{
										boardG.draw();
										for (int j = 0; j < players; j++)
										{
											window.draw(txtP[j]);
										}
										for (int i = 0; i < players; i++)
										{
											window.draw(plr[i].playerB);
										}
									}
									window.display();
									Sleep(1000);
									if (plr[own].plrPlace == 27)
									{
										window.clear();
										window.setView(full);
										{
											window.draw(pass);
										}
										window.display();
										Sleep(1000);
										plr[own].plrPlace = 0;
										plr[own].playerBalance += 200;
										PlaySound("resources/1.wav", NULL, SND_ASYNC);
									}
									else
									{
										plr[own].plrPlace++;
										PlaySound("resources/1.wav", NULL, SND_ASYNC);
									}
								}
								break;
							}
						}
					}
					else
						bankrupt(p);
				}
			}
			else if (plr[own].plrPlace == 15)
			{
				C.setCharacterSize(40);
				C.setFont(font2);
				C.setColor(Color::White);
				C.setPosition(midx - (midx / 1.2), midy - (midy / 1.2));
				C2.setCharacterSize(40);
				C2.setFont(font2);
				C2.setColor(Color::White);
				C2.setPosition(midx - (midx / 1.2), 0);
				C2.setString("Chance");
				int randomN;
				randomN = rand() % 6 + 1;
				if (randomN == 1)
				{
					C.setString("Move 15 bloccks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 15; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 2)
				{
					C.setString("Move 7 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 7; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 3)
				{
					C.setString("Get 200");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance += 200;
				}
				else if (randomN == 4)
				{
					C.setString("Roll dice");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					int intj=0;
					intj = dice.roll();
					for (int i = 0; i < intj; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 5)
				{
					C.setString("You got 1 jail out card");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].jailOutCards++;
				}
				else if (randomN == 6)
				{
					C.setString("give 100 to bank as tax");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance -= 100;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}

			}
			else if (plr[own].plrPlace == 16)
			{
				stopper = 0;
				if (strt[6].owner >= 1 && strt[6].owner <= 4)
				{
					if (strt[6].owner == p)
					{
						if ((strt[6].owner == strt[7].owner == strt[8].owner == p) && (strt[6].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[6].houses == 3)
												{
													strt[6].houses++;
													plr[own].playerBalance -= 200;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[6].houses++;
													plr[own].playerBalance -= 200;
													strt[6].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[6].houses == 2)
												{
													strt[6].houses += 2;
													plr[own].playerBalance -= 400;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 3)
												{
													strt[6].houses++;
													plr[own].playerBalance -= 200;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[6].houses += 2;
													plr[own].playerBalance -= 400;
													strt[6].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[6].houses == 1)
												{
													strt[6].houses += 3;
													plr[own].playerBalance -= 600;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 2)
												{
													strt[6].houses += 2;
													plr[own].playerBalance -= 400;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 3)
												{
													strt[6].houses += 1;
													plr[own].playerBalance -= 200;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[6].houses += 3;
													plr[own].playerBalance -= 600;
													strt[6].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[6].owner == 0)
												{
													strt[6].houses += 4;
													plr[own].playerBalance -= 800;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 1)
												{
													strt[6].houses += 3;
													plr[own].playerBalance -= 600;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 2)
												{
													strt[6].houses += 2;
													plr[own].playerBalance -= 400;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[6].houses == 3)
												{
													strt[6].houses += 1;
													plr[own].playerBalance -= 200;
													strt[6].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[6].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[6].tax;
						own2 = strt[6].owner - 1;
						plr[own2].playerBalance += strt[6].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[6].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[6].cost)
							{
								plr[own].playerBalance -= strt[6].cost;
								strt[6].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
				else if (plr[own].plrPlace == 17)
				{
					Text textRR[3];
					textRR[0].setFont(font2);
					textRR[0].setColor(Color::White);
					textRR[0].setPosition(midx - (midx / 2), midy - (midy / 2));
					textRR[0].setCharacterSize(30);
					textRR[1].setFont(font2);
					textRR[1].setColor(Color::White);
					textRR[1].setPosition(midx - (midx / 2), midy - (midy / 2));
					textRR[1].setCharacterSize(30);
					textRR[2].setFont(font2);
					textRR[2].setColor(Color::White);
					textRR[2].setPosition(midx - (midx / 2), midy - (midy / 2));
					textRR[2].setCharacterSize(30);
					textRR[0].setString("On an occupied Railroad\npaying tax " + toString(rRoad[1].tax) + " to owner");
					textRR[1].setString("Do you want to buy the railroad?(Y/N)\n150");
					textRR[2].setString("Not enough money");
					if (rRoad[1].owner >= 1 && rRoad[1].owner <= 4)
					{
						if (rRoad[1].owner != p)
						{
							window.clear();
							window.setView(full);
							window.draw(textRR[0]);
							window.display();
							Sleep(2000);
							plr[own].playerBalance -= rRoad[1].tax;
							plr[rRoad[1].owner].playerBalance += rRoad[1].tax;
							if (plr[own].playerBalance <= rRoad[1].tax)
							{
								bankrupt(p);
							}
						}
					}
					else
					{
						for (;;)
						{
							window.clear();
							window.setView(full);
							window.draw(textRR[1]);
							window.display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
							{
								if (plr[own].playerBalance>rRoad[1].cost)
								{
									plr[own].playerBalance -= rRoad[1].cost;
									rRoad[1].owner = p;
									break;
								}
								else
								{
									window.clear();
									window.setView(full);
									window.draw(textRR[2]);
									window.display();
									break;
								}
							}
							else if (Keyboard::isKeyPressed(Keyboard::N))
							{
								break;
							}
						}
					}
				}
				else if (plr[own].plrPlace == 18)
				{
					Text textU[3];
					textU[0].setFont(font2);
					textU[0].setColor(Color::White);
					textU[0].setPosition(midx - (midx / 2), midy - (midy / 2));
					textU[0].setCharacterSize(30);
					textU[1].setFont(font2);
					textU[1].setColor(Color::White);
					textU[1].setPosition(midx - (midx / 2), midy - (midy / 2));
					textU[1].setCharacterSize(30);
					textU[2].setFont(font2);
					textU[2].setColor(Color::White);
					textU[2].setPosition(midx - (midx / 2), midy - (midy / 2));
					textU[2].setCharacterSize(30);
					textU[0].setString("On an occupied Railroad\npaying tax " + toString(U[1].tax) + " to owner");
					textU[1].setString("Do you want to buy the Steel mill?\n180");
					textU[2].setString("Not enough money");
					if (U[1].owner >= 1 && U[1].owner <= 4)
					{
						if (U[1].owner != p)
						{
							window.clear();
							window.setView(full);
							window.draw(textU[0]);
							window.display();
							Sleep(2000);
							plr[own].playerBalance -= U[1].tax;
							plr[U[1].owner].playerBalance += U[1].tax;
							if (plr[own].playerBalance <= U[1].tax)
							{
								bankrupt(p);
							}
						}
					}
					else
					{
						for (;;)
						{
							window.clear();
							window.setView(full);
							window.draw(textU[1]);
							window.display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
							{
								if (plr[own].playerBalance>U[1].cost)
								{
									plr[own].playerBalance -= U[1].cost;
									U[1].owner = p;
									break;
								}
								else
								{
									window.clear();
									window.setView(full);
									window.draw(textU[2]);
									window.display();
									break;
								}
							}
							else if (Keyboard::isKeyPressed(Keyboard::N))
							{
								break;
							}
						}
					}
				}
			else if (plr[own].plrPlace == 19)
			{
				stopper = 0;
				if (strt[7].owner >= 1 && strt[7].owner <= 4)
				{
					if (strt[7].owner == p)
					{
						if ((strt[6].owner == strt[7].owner == strt[8].owner == p) && (strt[7].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[7].houses == 3)
												{
													strt[7].houses++;
													plr[own].playerBalance -= 200;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[7].houses++;
													plr[own].playerBalance -= 200;
													strt[7].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[7].houses == 2)
												{
													strt[7].houses += 2;
													plr[own].playerBalance -= 400;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 3)
												{
													strt[7].houses++;
													plr[own].playerBalance -= 200;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[7].houses += 2;
													plr[own].playerBalance -= 400;
													strt[7].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[7].houses == 1)
												{
													strt[7].houses += 3;
													plr[own].playerBalance -= 600;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 2)
												{
													strt[7].houses += 2;
													plr[own].playerBalance -= 400;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 3)
												{
													strt[7].houses += 1;
													plr[own].playerBalance -= 200;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[7].houses += 3;
													plr[own].playerBalance -= 600;
													strt[7].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[7].owner == 0)
												{
													strt[7].houses += 4;
													plr[own].playerBalance -= 800;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 1)
												{
													strt[7].houses += 3;
													plr[own].playerBalance -= 600;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 2)
												{
													strt[7].houses += 2;
													plr[own].playerBalance -= 400;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[7].houses == 3)
												{
													strt[7].houses += 1;
													plr[own].playerBalance -= 200;
													strt[7].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[7].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[7].tax;
						own2 = strt[7].owner - 1;
						plr[own2].playerBalance += strt[7].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[7].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[7].cost)
							{
								plr[own].playerBalance -= strt[7].cost;
								strt[7].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
		else if (plr[own].plrPlace == 20)
		{
			stopper = 0;
			if (strt[8].owner >= 1 && strt[8].owner <= 4)
			{
				if (strt[8].owner == p)
				{
					if ((strt[6].owner == strt[7].owner == strt[8].owner == p) && (strt[8].houses<4))
					{
						for (; stopper != 1;)
						{
							window.clear();
							window.setView(full);
							window.draw(msg[0]);
							window.display();
							if (Keyboard::isKeyPressed(Keyboard::Y))
							{
								for (;;)
								{
									window.clear();
									window.setView(full);
									window.draw(msg[1]);
									window.display();
									if (Keyboard::isKeyPressed(Keyboard::Num1))
									{
										if (plr[own].playerBalance > 200)
										{
											if (strt[8].houses == 3)
											{
												strt[8].houses++;
												plr[own].playerBalance -= 200;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[8].houses++;
												plr[own].playerBalance -= 200;
												strt[8].tax += 200;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num2))
									{
										if (plr[own].playerBalance>400)
										{
											if (strt[8].houses == 2)
											{
												strt[8].houses += 2;
												plr[own].playerBalance -= 400;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 3)
											{
												strt[8].houses++;
												plr[own].playerBalance -= 200;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[8].houses += 2;
												plr[own].playerBalance -= 400;
												strt[8].tax += 400;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num3))
									{
										if (plr[own].playerBalance > 600)
										{
											if (strt[8].houses == 1)
											{
												strt[8].houses += 3;
												plr[own].playerBalance -= 600;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 2)
											{
												strt[8].houses += 2;
												plr[own].playerBalance -= 400;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 3)
											{
												strt[8].houses += 1;
												plr[own].playerBalance -= 200;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else
											{
												strt[8].houses += 3;
												plr[own].playerBalance -= 600;
												strt[8].tax += 600;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
									else if (Keyboard::isKeyPressed(Keyboard::Num4))
									{
										if (plr[own].playerBalance > 800)
										{
											if (strt[8].owner == 0)
											{
												strt[8].houses += 4;
												plr[own].playerBalance -= 800;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 1)
											{
												strt[8].houses += 3;
												plr[own].playerBalance -= 600;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 2)
											{
												strt[8].houses += 2;
												plr[own].playerBalance -= 400;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
											else if (strt[8].houses == 3)
											{
												strt[8].houses += 1;
												plr[own].playerBalance -= 200;
												strt[8].tax = 2000;
												stopper = 1;
												break;
											}
										}
										else
										{
											window.clear();
											window.setView(full);
											window.draw(msg[6]);
											window.display();
											Sleep(1500);
											window.clear();
											stopper = 1;
											break;
										}
									}
								}
							}
							else if (Keyboard::isKeyPressed(Keyboard::N))
							{
								break;
							}
						}
					}
				}
				else
				{
					msg[4].setString("Tax is : " + toString(strt[8].tax));
					window.clear();
					window.setView(full);
					window.draw(msg[2]);
					window.draw(msg[4]);
					window.display();
					plr[own].playerBalance -= strt[8].tax;
					own2 = strt[8].owner - 1;
					plr[own2].playerBalance += strt[8].tax;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}
			}
			else
			{
				for (;;)
				{
					msg[5].setString("cost is :" + toString(strt[8].cost));
					window.clear();
					window.setView(full);
					window.draw(msg[3]);
					window.draw(msg[5]);
					window.display();
					if (Keyboard::isKeyPressed(Keyboard::Y))
					{
						if (plr[own].playerBalance > strt[8].cost)
						{
							plr[own].playerBalance -= strt[8].cost;
							strt[8].owner = p;
							break;
						}
						else
						{
							window.clear();
							window.setView(full);
							window.draw(msg[6]);
							window.display();
							Sleep(1500);
							window.clear();
							break;
						}
					}
					else if (Keyboard::isKeyPressed(Keyboard::N))
					{
						break;
					}
				}
			}
		}
			else if (plr[own].plrPlace == 21)
			{

			}
			else if (plr[own].plrPlace == 22)
			{
				stopper = 0;
				if (strt[9].owner >= 1 && strt[9].owner <= 4)
				{
					if (strt[9].owner == p)
					{
						if ((strt[9].owner == strt[10].owner == strt[11].owner == p) && (strt[9].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[9].houses == 3)
												{
													strt[9].houses++;
													plr[own].playerBalance -= 200;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[9].houses++;
													plr[own].playerBalance -= 200;
													strt[9].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[9].houses == 2)
												{
													strt[9].houses += 2;
													plr[own].playerBalance -= 400;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 3)
												{
													strt[9].houses++;
													plr[own].playerBalance -= 200;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[9].houses += 2;
													plr[own].playerBalance -= 400;
													strt[9].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[9].houses == 1)
												{
													strt[9].houses += 3;
													plr[own].playerBalance -= 600;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 2)
												{
													strt[9].houses += 2;
													plr[own].playerBalance -= 400;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 3)
												{
													strt[9].houses += 1;
													plr[own].playerBalance -= 200;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[9].houses += 3;
													plr[own].playerBalance -= 600;
													strt[9].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[9].owner == 0)
												{
													strt[9].houses += 4;
													plr[own].playerBalance -= 800;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 1)
												{
													strt[9].houses += 3;
													plr[own].playerBalance -= 600;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 2)
												{
													strt[9].houses += 2;
													plr[own].playerBalance -= 400;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[9].houses == 3)
												{
													strt[9].houses += 1;
													plr[own].playerBalance -= 200;
													strt[9].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[9].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[9].tax;
						own2 = strt[9].owner - 1;
						plr[own2].playerBalance += strt[9].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[9].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[9].cost)
							{
								plr[own].playerBalance -= strt[9].cost;
								strt[9].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 23)
			{
				C.setCharacterSize(40);
				C.setFont(font2);
				C.setColor(Color::White);
				C.setPosition(midx - (midx / 1.2), midy - (midy / 1.2));
				C2.setCharacterSize(40);
				C2.setFont(font2);
				C2.setColor(Color::White);
				C2.setPosition(midx - (midx / 1.2), 0);
				C2.setString("Chance");
				int randomN;
				randomN = rand() % 6 + 1;
				if (randomN == 1)
				{
					C.setString("Move 15 bloccks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 15; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							plr[own].playerBalance += 200;
						}
						else
						{
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
							plr[own].plrPlace++;
						}
					}
				}
				else if (randomN == 2)
				{
					C.setString("Move 7 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 7; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 3)
				{
					C.setString("Get 200");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance += 200;
				}
				else if (randomN == 4)
				{
					C.setString("Roll dice");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					int intj;
					intj = dice.roll();
					for (int i = 0; i < intj; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 5)
				{
					C.setString("You got 1 jail out card");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].jailOutCards++;
				}
				else if (randomN == 6)
				{
					C.setString("give 100 to bank as tax");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance -= 100;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}

			}
			else if (plr[own].plrPlace == 24)
			{
				Text taxt;
				taxt.setFont(font2);
				taxt.setColor(Color::White);
				taxt.setPosition(midx - (midx / 2), midy - (midy / 2));
				taxt.setCharacterSize(30);
				taxt.setString("income tax of " + toString(t[2].amount) + " \nis deduced from your account");
				window.clear();
				window.setView(full);
				window.draw(taxt);
				window.display();
				Sleep(1500);
				plr[own].playerBalance -= t[2].amount;
				if (plr[own].playerBalance <= 0)
				{
					bankrupt(p);
				}
			}
			else if (plr[own].plrPlace == 25)
			{
				C.setCharacterSize(40);
				C.setFont(font2);
				C.setColor(Color::White);
				C.setPosition(midx - (midx / 1.2), midy - (midy / 1.2));
				C2.setCharacterSize(40);
				C2.setFont(font2);
				C2.setColor(Color::White);
				C2.setPosition(midx - (midx / 1.2), 0);
				C2.setString("Community Chest");
				int randomN;
				randomN = rand() % 6 + 1;
				if (randomN == 1)
				{
					C.setString("Move 10 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 10; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 2)
				{
					C.setString("Move 5 blocks");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					for (int i = 0; i < 5; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 3)
				{
					C.setString("Get 500");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance += 500;
				}
				else if (randomN == 4)
				{
					C.setString("Roll dice");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					int intj;
					intj = dice.roll();
					for (int i = 0; i < intj; i++)
					{
						if (plr[own].plrPlace == 0)
							plx[own] += ix0019;
						else if (plr[own].plrPlace > 0 && plr[own].plrPlace < 7)
							plx[own] += ix;
						else if (plr[own].plrPlace == 7)
							ply[own] += iy1427;
						else if (plr[own].plrPlace >7 && plr[own].plrPlace < 14)
							ply[own] += iy;
						else if (plr[own].plrPlace >= 14 && plr[own].plrPlace < 20)
							plx[own] -= ix;
						else if (plr[own].plrPlace == 20)
							plx[own] -= ix0019;
						else if (plr[own].plrPlace >= 20 && plr[own].plrPlace < 27)
							ply[own] -= iy;
						else if (plr[own].plrPlace == 27)
							ply[own] -= iy1427;
						for (int i = 0; i < 4; i++)
							plr[i].playerB.setPosition(plx[i], ply[i]);
						window.clear();
						window.setView(game);
						{
							boardG.draw();
							for (int j = 0; j < players; j++)
							{
								window.draw(txtP[j]);
							}
							for (int i = 0; i < players; i++)
							{
								window.draw(plr[i].playerB);
							}
						}
						window.display();
						Sleep(1000);
						if (plr[own].plrPlace == 27)
						{
							window.clear();
							window.setView(full);
							{
								window.draw(pass);
							}
							window.display();
							Sleep(1000);
							plr[own].plrPlace = 0;
							plr[own].playerBalance += 200;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
						else
						{
							plr[own].plrPlace++;
							PlaySound("resources/1.wav", NULL, SND_ASYNC);
						}
					}
				}
				else if (randomN == 5)
				{
					C.setString("You got 1 jail out card");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].jailOutCards++;
				}
				else if (randomN == 6)
				{
					C.setString("give 200 to bank as tax");
					window.clear();
					window.setView(full);
					window.draw(C);
					window.draw(C2);
					window.display();
					Sleep(1000);
					plr[own].playerBalance -= 200;
					if (plr[own].playerBalance <= 0)
					{
						bankrupt(p);
					}
				}

			}
			else if (plr[own].plrPlace == 26)
			{
				stopper = 0;
				if (strt[10].owner >= 1 && strt[10].owner <= 4)
				{
					if (strt[10].owner == p)
					{
						if ((strt[9].owner == strt[10].owner == strt[11].owner == p) && (strt[10].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[10].houses == 3)
												{
													strt[10].houses++;
													plr[own].playerBalance -= 200;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[10].houses++;
													plr[own].playerBalance -= 200;
													strt[10].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[10].houses == 2)
												{
													strt[10].houses += 2;
													plr[own].playerBalance -= 400;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 3)
												{
													strt[10].houses++;
													plr[own].playerBalance -= 200;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[10].houses += 2;
													plr[own].playerBalance -= 400;
													strt[10].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[10].houses == 1)
												{
													strt[10].houses += 3;
													plr[own].playerBalance -= 600;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 2)
												{
													strt[10].houses += 2;
													plr[own].playerBalance -= 400;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 3)
												{
													strt[10].houses += 1;
													plr[own].playerBalance -= 200;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[10].houses += 3;
													plr[own].playerBalance -= 600;
													strt[10].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[10].owner == 0)
												{
													strt[10].houses += 4;
													plr[own].playerBalance -= 800;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 1)
												{
													strt[10].houses += 3;
													plr[own].playerBalance -= 600;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 2)
												{
													strt[10].houses += 2;
													plr[own].playerBalance -= 400;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[10].houses == 3)
												{
													strt[10].houses += 1;
													plr[own].playerBalance -= 200;
													strt[10].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[10].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[10].tax;
						own2 = strt[10].owner - 1;
						plr[own2].playerBalance += strt[10].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[10].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[10].cost)
							{
								plr[own].playerBalance -= strt[10].cost;
								strt[10].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
			else if (plr[own].plrPlace == 27)
			{
				stopper = 0;
				if (strt[11].owner >= 1 && strt[11].owner <= 4)
				{
					if (strt[11].owner == p)
					{
						if ((strt[9].owner == strt[10].owner == strt[11].owner == p) && (strt[11].houses<4))
						{
							for (; stopper != 1;)
							{
								window.clear();
								window.setView(full);
								window.draw(msg[0]);
								window.display();
								if (Keyboard::isKeyPressed(Keyboard::Y))
								{
									for (;;)
									{
										window.clear();
										window.setView(full);
										window.draw(msg[1]);
										window.display();
										if (Keyboard::isKeyPressed(Keyboard::Num1))
										{
											if (plr[own].playerBalance > 200)
											{
												if (strt[11].houses == 3)
												{
													strt[11].houses++;
													plr[own].playerBalance -= 200;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[11].houses++;
													plr[own].playerBalance -= 200;
													strt[11].tax += 200;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num2))
										{
											if (plr[own].playerBalance>400)
											{
												if (strt[11].houses == 2)
												{
													strt[11].houses += 2;
													plr[own].playerBalance -= 400;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 3)
												{
													strt[11].houses++;
													plr[own].playerBalance -= 200;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[11].houses += 2;
													plr[own].playerBalance -= 400;
													strt[11].tax += 400;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num3))
										{
											if (plr[own].playerBalance > 600)
											{
												if (strt[11].houses == 1)
												{
													strt[11].houses += 3;
													plr[own].playerBalance -= 600;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 2)
												{
													strt[11].houses += 2;
													plr[own].playerBalance -= 400;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 3)
												{
													strt[11].houses += 1;
													plr[own].playerBalance -= 200;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else
												{
													strt[11].houses += 3;
													plr[own].playerBalance -= 600;
													strt[11].tax += 600;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
										else if (Keyboard::isKeyPressed(Keyboard::Num4))
										{
											if (plr[own].playerBalance > 800)
											{
												if (strt[11].owner == 0)
												{
													strt[11].houses += 4;
													plr[own].playerBalance -= 800;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 1)
												{
													strt[11].houses += 3;
													plr[own].playerBalance -= 600;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 2)
												{
													strt[11].houses += 2;
													plr[own].playerBalance -= 400;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
												else if (strt[11].houses == 3)
												{
													strt[11].houses += 1;
													plr[own].playerBalance -= 200;
													strt[11].tax = 2000;
													stopper = 1;
													break;
												}
											}
											else
											{
												window.clear();
												window.setView(full);
												window.draw(msg[6]);
												window.display();
												Sleep(1500);
												window.clear();
												stopper = 1;
												break;
											}
										}
									}
								}
								else if (Keyboard::isKeyPressed(Keyboard::N))
								{
									break;
								}
							}
						}
					}
					else
					{
						msg[4].setString("Tax is : " + toString(strt[11].tax));
						window.clear();
						window.setView(full);
						window.draw(msg[2]);
						window.draw(msg[4]);
						window.display();
						plr[own].playerBalance -= strt[11].tax;
						own2 = strt[11].owner - 1;
						plr[own2].playerBalance += strt[11].tax;
						if (plr[own].playerBalance <= 0)
						{
							bankrupt(p);
						}
					}
				}
				else
				{
					for (;;)
					{
						msg[5].setString("cost is :" + toString(strt[11].cost));
						window.clear();
						window.setView(full);
						window.draw(msg[3]);
						window.draw(msg[5]);
						window.display();
						if (Keyboard::isKeyPressed(Keyboard::Y))
						{
							if (plr[own].playerBalance > strt[11].cost)
							{
								plr[own].playerBalance -= strt[11].cost;
								strt[11].owner = p;
								break;
							}
							else
							{
								window.clear();
								window.setView(full);
								window.draw(msg[6]);
								window.display();
								Sleep(1500);
								window.clear();
								break;
							}
						}
						else if (Keyboard::isKeyPressed(Keyboard::N))
						{
							break;
						}
					}
				}
			}
		}
};
	class Game :public baseGame{
	public:
		playerC *player;
		mainMenu menu;
		board boardC;
		Music fmusic;
		Game(){
			startWindow();
			menu.startMenuGraph();
			player = new playerC[players];
			int j;
			fmusic.openFromFile("resources/Fmusic.ogg");
			fmusic.setLoop(true);
			for (int i = 0; i < players; i++)
			{
				j = i + 1;
				player[i].playerColor = ColorN(j);
				player[i].playerNum = j;
				player[i].jailOutCards = 0;
				player[i].playerBalance = 2000;
				player[i].setSprite(j);
				player[i].plrPlace = 0;
			}
		}
		void gamePlay(){
			fmusic.play();
			pturnI[0].loadFromFile("resources/p1t.png");
			pturnI[1].loadFromFile("resources/p2t.png");
			pturnI[2].loadFromFile("resources/p3t.png");
			pturnI[3].loadFromFile("resources/p4t.png");
			for (int i = 0; i < 4; i++)
			{
				pturnT[i].loadFromImage(pturnI[i]);
				pturn[i].setTexture(pturnT[i]);
				pturn[i].setScale(winx / pturnT[i].getSize().x, winy / pturnT[i].getSize().y);
			}
			for (;;)
			{
				for (int k = 0; k < players; k++)
				{
					lk = k + 1;
					txtP[k].setString("Player# " + toString(lk) + "\n" + toString(player[k].playerBalance));
				}
				for (int i = 0; i < 4; i++)
					player[i].playerB.setPosition(plx[i], ply[i]);
				window.clear();
				window.setView(game);
				{
					boardG.draw();
					for (int j = 0; j < players; j++)
					{
						window.draw(txtP[j]);
					}
					for (int i = 0; i < players; i++)
					{
						window.draw(player[i].playerB);
					}
				}
				window.display();
				Sleep(1000);
				if (turn == players)
				{
					turn = 0;
				}
				window.clear();
				window.draw(pturn[turn]);
				window.display();
				Sleep(1000);
				int inc;
				inc = dice.roll();
				for (int i = 0; i < inc; i++)
				{
					if (player[turn].plrPlace == 0)
						plx[turn] += ix0019;
					else if (player[turn].plrPlace > 0 && player[turn].plrPlace < 7)
						plx[turn] += ix;
					else if (player[turn].plrPlace == 7)
						ply[turn] += iy1427;
					else if (player[turn].plrPlace >7 && player[turn].plrPlace < 14)
						ply[turn] += iy;
					else if (player[turn].plrPlace >= 14 && player[turn].plrPlace < 20)
						plx[turn] -= ix;
					else if (player[turn].plrPlace == 20)
						plx[turn] -= ix0019;
					else if (player[turn].plrPlace >= 20 && player[turn].plrPlace < 27)
						ply[turn] -= iy;
					else if (player[turn].plrPlace == 27)
						ply[turn] -= iy1427;
					for (int i = 0; i < 4; i++)
						player[i].playerB.setPosition(plx[i], ply[i]);
					window.clear();
					window.setView(game);
					{
						boardG.draw();
						for (int j = 0; j < players; j++)
						{
							window.draw(txtP[j]);
						}
						for (int i = 0; i < players; i++)
						{
							window.draw(player[i].playerB);
						}
					}
					window.display();
					Sleep(1000);
					if (player[turn].plrPlace == 27)
					{
						window.clear();
						window.setView(full);
						{
							window.draw(pass);
						}
						window.display();
						Sleep(1000);
						player[turn].plrPlace = 0;
						player[turn].playerBalance += 200;
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
					}
					else
					{
						PlaySound("resources/1.wav", NULL, SND_ASYNC);
						player[turn].plrPlace++;
					}
				}
				boardC.doFunc(turn,player);
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}
				turn++;
			}
			fmusic.stop();
		}
	};

	void main(){
		Game gameInstance;
		gameInstance.gamePlay();
	}

