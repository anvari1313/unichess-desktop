#include "src/game.h"

int main( int argc, char* args[] )
{
    Game g;
    g.Init();
    g.Run();
    g.Close();

    return EXIT_SUCCESS;
}
