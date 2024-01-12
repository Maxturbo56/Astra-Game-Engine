#include "Astra_Lib.cpp"

int main()
{
    // pozicija  0  0
    Input input;
    Vector2 zero;
    zero.x = 2;
    zero.y = 2;
    Screen s;
    s.Init_Screen(100, 100);
    Handler handler;
    Entity e_parent;

    Entity e(zero, 0, 'H', YELLOW);
    e_parent.Add_Child(&e);

    while(1)
    {
        if(input.is_key_Pressed('W'))
        {
            if(e.position.y != 1)
            {
                e.position.y--;
            }
        }
        else if(input.is_key_Pressed('D'))
        {
            if(e.position.x != 99)
            {
                e.position.x++;
            }
        }
        else if(input.is_key_Pressed('S'))
        {
            if(e.position.y != 99)
            {
                e.position.y++;
            }
        }
        else if(input.is_key_Pressed('A'))
        {
            if(e.position.x != 1)
            {
                e.position.x--;
            }
        }

        s.Update(e_parent);
        handler.Wait(240);
        handler.Clear();
    }

    return 0;
}