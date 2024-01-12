#include "Astra_Lib.h"

void Symbol::set_Bit(std::string b)
{
    this->_bit = b;
}
std::string Symbol::get_Bit()
{
    return this->_bit;
}
void Symbol::set_Color(std::string c)
{
    this->hue.hue = c;
}
std::string Symbol::get_Color()
{
    return this->hue.hue;
}
void Symbol_Image::Load_Texture(std::string s)
{
    int horizontal = 0, vertical = 0;
    std::string line;
    std::vector <std::string> lines;
    std::ifstream file_IN;
    file_IN.open(s);
    while(getline(file_IN, line))
    {
        lines.push_back(line);
    }
    file_IN.close();
    for(int i = 0; i < lines.size(); i+=2)
    {
        if(lines[i] != "#")
        {
            this->texture[vertical][horizontal].set_Bit(lines[i]);
            this->texture[vertical][horizontal].set_Color(lines[i+1]);
            horizontal++;
        }
        else
        {
            vertical++;
            horizontal = 0;
        }
    }
}
void Screen::Draw_Symbol_Image(int pos_x, int pos_y, Symbol_Image &image)
{
    for(int i = 0; i < this->screen_Height; i++)
    {
        for(int j = 0; j < this->screen_Width; j++)
        {
            if(i == pos_y && j == pos_x)
            {
                for(int k = 0; k < 2; k++)
                {
                    for(int h = 0; h < 2; h++)
                    {
                        //this->monitor[i + k][j + h] = image.Load_Texture();
                    }
                }
            }
        }
    }
}

void Screen::Init_Screen(int x, int y)
{
    this -> screen_Height = y;
    this -> screen_Width = x; 

    for(int i = 0; i < this->screen_Height; i++)
    {
        for(int j = 0; j < this->screen_Width; j++)
        {
            this -> monitor[i][j] = ' ';
        }
    }
}
void Screen::Update(Entity &e)
{
    for(int i = 0; i < this->screen_Height; i++)
    {
        for(int j = 0; j < this->screen_Width; j++)
        {
            for(int k = 0; k < e.Get_Child_Count(); k++)
            {
                if(e.Get_Child(k).position.x == j && e.Get_Child(k).position.y == i)
                {
                    std::cout<<e.Get_Child(k).Get_Color()<<e.Get_Child(k).get_Image()<<WHITE<<" ";
                }
                else
                {
                    std::cout<<" ";
                }
            }
        }
        std::cout<<std::endl;
    }
}
int Screen::get_X()
{
    return this->screen_Width;
}
int Screen::get_Y()
{
    return this->screen_Height;
}

bool Input::is_key_Pressed(char key)
{
    if(GetKeyState(key) & 0x8000)
    {
        return true;
    }   
    else
    {
        return false;
    }
}

Entity::Entity()
{
    this -> index = 0;
    this -> image = '?';
    this -> position.x = 0;
    this -> position.y = 0;
}
Entity::Entity(Vector2 p, int index, char image, std::string color)
{
    this -> index = index;
    this -> image = image;
    this -> position = p;
    this -> color.hue = color;
}
void Entity::set_Index(int index)
{
    this -> index = index;
}
void Entity::set_Image(char image)
{
    this -> image = image;
}
char Entity::get_Image()
{
    return this -> image;
}
int Entity::get_Index()
{
    return this -> index;
}

// HIERARCHY ----------------------------------

/*
    Explainy time : 

   " (Some Data Type)* " IS A POINTER TO THAT DATA 
   " *(Some Data Type) " THIS TELLS YOU WHAT DATA IS AT A POINTER
   " &(Some Data Type) " THIS TAKES A MEMORY ADRESS AND WORKS WITH THAT EXACT MEMORY

   ATTENTION! : '&' can be passed as an argument to a function that takes a pointer to a data location!!!

   - Without any of these you work with COPIES of data stored at some random locations in the heap / stack !!!
*/

void Entity::Add_Child(Entity* e)
{
    this->entities.push_back(e);
}
Entity Entity::Get_Child(int index)
{
    return *this->entities[index];
}
int Entity::Get_Child_Count()
{
    int size;
    size = this->entities.size();
    return size;
}
void Entity::Queue_Free(int index)
{
    this->entities[index] = this->entities.back();
    this->entities.pop_back();
}
void Entity::Set_Color(std::string c)
{
    this->color.hue = c;
}
std::string Entity::Get_Color()
{
    return this->color.hue;
}

// ----------------------------------------------------------

void Handler::Wait(int sec)
{
    Sleep(sec);
}
void Handler::Clear()
{
    system("CLS");
}
void Handler::hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}