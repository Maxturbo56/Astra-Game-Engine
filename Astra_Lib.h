#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <fstream>

//COLORS ----------------------
#define GREEN "\033[32m"        
#define BLUE "\033[34m"         
#define YELLOW "\033[33m"       
#define WHITE "\033[37m"        
#define RED "\033[31m"          
#define CYAN "\033[36m"         
//COLORS ----------------------

class Color{
public:
    std::string hue;
};

class Handler{
public:
    void Wait(int sec);
    void Clear();
    void hideCursor();
};

class Input{
    char key;
public:
    bool is_key_Pressed(char key);
};

struct Vector2{
    int x, y;
};

class Symbol{
    std::string _bit;
    Color hue;
public:
    void set_Bit(std::string b);
    std::string get_Bit();
    void set_Color(std::string h);
    std::string get_Color();
};

class Symbol_Image{
    Vector2 position;
    Symbol texture[3][3];
public:
    void Load_Texture(std::string s);
};

class Entity{
    int index;
    char image;
    Color color;
    std::vector <Entity*> entities; //Vector of pointers to entities in your game! O  _ o 
public:
    void Set_Color(std::string c);
    std::string Get_Color();
    Vector2 position;
    Entity();
    Entity(Vector2 p, int index, char image, std::string color);
    void set_Index(int index);
    void set_Image(char image);
    char get_Image();
    int get_Index();
    ~Entity() = default;

    // HIERARCHY ----------------------------------------
    void Add_Child(Entity* e); // Passes in a pointer to an entity 
    Entity Get_Child(int index); // Returns an instance of an entity via pointer 
    int Get_Child_Count(); // Returns the size of entities vector declared in class
    void Queue_Free(int index); // Clears the entity on said index from memory
};

class Screen{
    int screen_Width;
    int screen_Height;
    char monitor[100][100];
public:
    void Init_Screen(int x, int y);
    void Update(Entity &e);
    void Draw_Symbol_Image(int pos_x, int pos_y, Symbol_Image &image);
    int get_X();
    int get_Y();
};