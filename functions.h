#include <iostream>
#include <TXLib.h>
#include <fstream>
#include "widgets.h"
#include "base_block.h"
#include "block.h"
#include "lava_block.h"
#include "main_hero_intro.h"
#include "main_hero.h"
#include "platypus.h"
#include "fugu.h"

using namespace std;

void add_widgets();
void upload_images();
void hello_window();
void menu();
void choose_hero();
void promotion();
void choose_level();
vector<vector<shared_ptr <BaseBlock>>> upload_level(string filename);
void start_level(string filename);
void donate();
void magic();
void delete_images();


void choose_platypus_func();
void choose_fish_func();

void start_train_level_button_func();

HDC menu_background;
HDC choose_hero_background;
HDC choose_level_background;
Button play_button(760, 500, choose_hero, "Играть", "Bell MT", 50, 60, 400, RGB(130, 0, 0) , TX_WHITE, false);
Button promotion_button(760, 600, promotion, "Заказать рекламу", "Bell MT", 40, 60, 400, RGB(107, 0, 229), TX_WHITE, false);
Button donate_button(760, 700, donate, "Донат", "Bell MT", 40, 60, 400, RGB(7, 110, 51), TX_WHITE, false);
Button magic_button(760, 800, magic, "Магическая Кнопка", "Bell MT", 40, 60, 400, RGB(123, 145, 123), TX_WHITE, false);
//Button continue_button(810, 1000, magic, "Продолжить", "Bell MT", 40, 60, 300, RGB(130, 0, 0), TX_WHITE, false);

Button choose_platypus_button(200, 900, choose_platypus_func, "Выбрать персонажа", "Bell MT", 40, 60, 300, RGB(235, 194, 175), TX_WHITE, false);
Button choose_fish_button(1350, 900, choose_fish_func, "Выбрать персонажа", "Bell MT", 40, 60, 300, RGB(235, 194, 175), TX_WHITE, false);

Button start_train_level_button(423, 730, start_train_level_button_func, "Старт", "Bell MT", 40, 50, 168, RGB(86, 52, 68), RGB(54, 32, 42), false);

int chosen_hero;

void add_widgets() {
    buttons.push_back(&play_button);
    buttons.push_back(&promotion_button);
    buttons.push_back(&donate_button);
    buttons.push_back(&magic_button);
    buttons.push_back(&choose_platypus_button);
    buttons.push_back(&choose_fish_button);
    buttons.push_back(&start_train_level_button);
    //buttons.push_back(&continue_button);
}

void upload_images() {
    menu_background = txLoadImage("images\\background1.bmp");
    choose_hero_background = txLoadImage("images\\choose_hero_bg.bmp");
    choose_level_background = txLoadImage("images\\choose_level_bg.bmp");

}

void hello_window(){
    Platypuss platypus;
    platypus.set_x(0);
    platypus.set_y(150);
    platypus.set_fall_down(false);

    //txCreateWindow(1920,1080);
    txSetFillColor(RGB(63,63,63));
    txClear();
    txPlaySound ("sounds\\hello1.wav",SND_ASYNC);

    int x = 0;
    while(x < 490){
        txClear();
        txSetColor(RGB(45,45,45),20);
        txLine(0,0,1920,0);
        txLine(1920,0,1920,1080);
        txLine(0,1080,0,0);
        txSetColor(RGB(45,45,45),10);
        txLine(1920,1065,0,1065);
        txSetColor(TX_BLACK);
        txSelectFont("Fixedsys", 50);
        txTextOut(824,990,"by Double K Games");

        txSelectFont("Calibri", 200);
        txSetColor(RGB(165,5,193));
        txTextOut(x,25,"Platypus");
        x = x + 5;
        txSleep(1);
    }
    txSleep(1000);
    x=0;
    while(x>-60){
        txClear();
        txSetColor(RGB(45,45,45),20);
        txLine(0,0,1920,0);
        txLine(1920,0,1920,1080);
        txLine(0,1080,0,0);
        txSetColor(RGB(45,45,45),10);
        txLine(1920,1065,0,1065);
        txSetColor(TX_BLACK);
        txSelectFont("Fixedsys", 50);
        txTextOut(824,990,"by Double K Games");
        txSelectFont("Calibri", 200);
        txSetColor(RGB(165,5,193));
        txTextOut(565,25,"latypus");

        txSelectFont("Calibri",200,-1,FW_DONTCARE,false,false,false,x);
        txTextOut(490,25,"P");
        txSleep(10);
        x=x-3;
    }

    int y=25 ;
    while(y<1065){
        txClear();
        txSetColor(RGB(45,45,45),20);
        txLine(0,0,1920,0);
        txLine(1920,0,1920,1080);
        txLine(0,1080,0,0);
        txSetColor(RGB(45,45,45),10);
        txLine(1920,1065,0,1065);
        txSetColor(TX_BLACK);
        txSelectFont("Fixedsys", 50);
        txTextOut(824,990,"by Double K Games");
        txSelectFont("Calibri", 200);
        txSetColor(RGB(165,5,193));
        txTextOut(565,25,"latypus");

        txSelectFont("Calibri",200,-1,FW_DONTCARE,false,false,false,-60);
        txTextOut(490,y,"P");
        txSleep(1);
        y=y+5;

    }
    y = -100;
    while(y < 10){
        txClear();
        txSetColor(RGB(45,45,45),20);
        txLine(0,0,1920,0);
        txLine(1920,0,1920,1080);
        txLine(0,1080,0,0);
        txSetColor(RGB(45,45,45),10);
        txLine(1920,1065,0,1065);
        txSetColor(TX_BLACK);
        txSelectFont("Fixedsys", 50);
        txTextOut(824,990,"by Double K Games");
        txSelectFont("Calibri", 200);
        txSetColor(RGB(165,5,193));
        txTextOut(565,25,"latypus");

        txSelectFont("Calibri", 250);
        txSetColor(RGB(193,21,1));
        txTextOut(1090,y,"RUN");
        y = y + 10;
        txSleep(10);
    }

    x=0;
    while(x<=470){
        txSetFillColor(RGB(63,63,63));
        txClear();
        txSetColor(RGB(45,45,45),20);
        txLine(0,0,1920,0);
        txLine(1920,0,1920,1080);
        txLine(0,1080,0,0);
        txSetColor(RGB(45,45,45),10);
        txLine(1920,1065,0,1065);
        txSetColor(TX_BLACK);
        txSelectFont("Fixedsys", 50);
        txTextOut(824,990,"by Double K Games");
        txSelectFont("Calibri", 200);
        txSetColor(RGB(165,5,193));
        txTextOut(565,25,"latypus");
        txSelectFont("Calibri", 250);
        txSetColor(RGB(193,21,1));
        txTextOut(1090,10,"RUN");

        platypus.update(x,180);
        platypus.draw_platypus();
        x=x+5;
        txSleep(10);
    }
    txSetFillColor(RGB(63,63,63));
    txClear();
    txSetColor(RGB(45,45,45),20);
    txLine(0,0,1920,0);
    txLine(1920,0,1920,1080);
    txLine(0,1080,0,0);
    txSetColor(RGB(45,45,45),10);
    txLine(1920,1065,0,1065);
    txSetColor(TX_BLACK);
    txSelectFont("Fixedsys", 50);
    txTextOut(824,990,"by Double K Games");
    txSelectFont("Calibri", 200);
    txSetColor(RGB(165,5,193));
    txTextOut(565,25,"latypus");
    txSelectFont("Calibri", 250);
    txSetColor(RGB(193,21,1));
    txTextOut(1090,10,"RUN");
    platypus.update(x,180);
    platypus.update(x,180);
    platypus.draw_platypus();

}

void menu(){
    play_button.set_state(true);
    promotion_button.set_state(true);
    donate_button.set_state(true);
    //magic_button.set_state(true);
    if (!menu_background) {
        txMessageBox("!menu_background");
    }
    txBitBlt(txDC(), 0, 0, 1920, 1080, menu_background);
}

void choose_hero() {
    play_button.set_state(false);
    promotion_button.set_state(false);
    donate_button.set_state(false);
    choose_platypus_button.set_state(true);
    choose_fish_button.set_state(true);
   // continue_button.set_state(true);
    txClear();
    txBitBlt(txDC(), 0, 0, 1920, 1080, choose_hero_background);
}

void choose_level() {
    choose_platypus_button.set_state(false);
    choose_fish_button.set_state(false);
    start_train_level_button.set_state(true);
    txBitBlt(txDC(), 0, 0, 1920, 1080, choose_level_background);
        
}

void start_level(string filename){
    bool game = true;
    start_train_level_button.set_state(false);
    txClear();
   // shared_ptr<MainHero> hero = make_shared<MainHero>(100,500);
    MainHero* hero = new MainHero (100, 500);
    cout << hero->get_x() << '\n';
    if (chosen_hero == 0) {
        delete (hero);
        Platypus* hero = new Platypus(100, 500);
       // shared_ptr<Platypus> hero = make_shared<Platypus>(100, 500);
        cout << hero->get_x() << '\n';
    }
    else{ //if(chosen_hero == 1) {
        delete (hero);
        Fugu* hero = new Fugu(100, 500);
       // shared_ptr<Fugu> hero = make_shared<Fugu>(100, 500);
        cout << "POOP";
    }
    cout << hero->get_x() << '\n';
    //shared_ptr <BaseBlock> blocks[] = upload_level(filename);
    vector <vector<shared_ptr <BaseBlock>>> blocks = upload_level(filename);

    for (auto i : blocks) {
        for (auto j : i) {
            j->draw();
        }
        //cout << i->get_x() << '\n';
    }
    while (!GetAsyncKeyState(VK_ESCAPE)) {
        txClear();
        for (auto i : blocks) {
            for (auto j : i) {
                j->draw();
            }
            //cout << i->get_x() << '\n';
        }
        hero->update();
        txSleep(50);
        //cout<<hero->get_x()<<'\n';
    }
    
}

vector<vector<shared_ptr <BaseBlock>>> upload_level(string filename){
    int i, j;
    int margin_x = 10;
    int margin_y = 40;
    ifstream level_file("libs//train_level.txt");
 
    level_file >> i >> j;
    vector <string> file_blocks;
    vector <vector<shared_ptr <BaseBlock>>> blocks;


    HDC stone = txLoadImage("libs//stone.bmp");
    HDC grass_dirt = txLoadImage("libs//grass_dirt.bmp");
    HDC dirt = txLoadImage("libs//dirt.bmp");
    HDC lava = txLoadImage("libs//lava.bmp");
    HDC quick_sand = txLoadImage("libs//quick_sand.bmp");
    txSetFillColor(TX_BLACK);
    txClear();
    txSetFillColor(RGB(20, 109, 181));
    txRectangle(10, 40, 1910, 1040);
    cout << i << j;
    for (int i0 = 0; i0 < i; i0++) {
        vector<shared_ptr <BaseBlock>> line;
        for (int j0 = 0; j0 < j; j0++) {
            string word;
            level_file >> word;
            //file_blocks[i0][j0] = word;
            //file_blocks.push_back({});
            file_blocks.push_back(word);


            //if(word == "empty"){
             //   Win32::TransparentBlt(txDC(),j0*100,i0*100,100,100,empty,0,0,100,100,TX_WHITE);
            //}
            //blocks.push_back({});
            if (word == "lava") {
                line.push_back(make_shared <LavaBlock>(margin_x + j0*100, margin_y + i0*100, 10, lava));
               // Win32::TransparentBlt(txDC(), 210 + j0 * 100, i0 * 100, 100, 100, lava, 0, 0, 100, 100, TX_WHITE);
            }
            else if (word == "stone") {
                line.push_back(make_shared <Block>(margin_x + j0 * 100, margin_y + i0 * 100, stone));
               // Win32::TransparentBlt(txDC(), 210 + j0 * 100, i0 * 100, 100, 100, stone, 0, 0, 100, 100, TX_WHITE);
            }
            else if (word == "dirt") {
                line.push_back(make_shared <Block>(margin_x + j0 * 100, margin_y + i0 * 100, dirt));
               // Win32::TransparentBlt(txDC(), 210 + j0 * 100, i0 * 100, 100, 100, dirt, 0, 0, 100, 100, TX_WHITE);
            }
            else if (word == "grass_dirt") {
                line.push_back(make_shared <Block>(margin_x + j0 * 100, margin_y + i0 * 100, grass_dirt));
               // Win32::TransparentBlt(txDC(), 210 + j0 * 100, i0 * 100, 100, 100, grass_dirt, 0, 0, 100, 100, TX_WHITE);
            }
            else if (word == "quick_sand") {
                line.push_back(make_shared <BaseBlock>(margin_x + j0 * 100, margin_y + i0 * 100, quick_sand));
               // Win32::TransparentBlt(txDC(), 210 + j0 * 100, i0 * 100, 100, 100, quick_sand, 0, 0, 100, 100, TX_WHITE);
            }
        }
        blocks.push_back(line);
    }
    /*txDeleteDC(lava);
    txDeleteDC(stone);
    txDeleteDC(grass_dirt);
    //txDeleteDC(empty);
    txDeleteDC(quick_sand);
    txDeleteDC(dirt);*/
    return blocks;
}

void promotion() {
    system("explorer https://vk.com/doublekgames");
}

void donate() {
    system("explorer https://www.donationalerts.com/r/double_k_games");
}

void magic() {
    int num = rand() % 2;
    if (num == 0) {
        system("explorer https://dnevnik.mos.ru/diary/diary/marks");
    }
    else if (num == 1) {
        system("explorer https://www.youtube.com/watch?v=XuUw2iW4h9w&ab");
    }
    else if (num == 2) {

    }
    else if (num == 3) {

    }
}

void delete_images() {
    txDeleteDC(menu_background);
    txDeleteDC(choose_hero_background);
    txDeleteDC(choose_level_background);
}



void choose_platypus_func() {
    chosen_hero = 0;
    choose_level();
}

void choose_fish_func() {
    chosen_hero = 1;
    choose_level();
}

void start_train_level_button_func(){
    start_level("train_level.txt");
}