#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;

int fn_800506DC();
int* fn_8004E6B8(void*);
int* fn_8004E6C4(void*);
int fn_8004F258(unsigned int*, unsigned int, int);

struct Game {
    char pad[0x24];
    void* state;
};

struct State {
    char pad[0x7F4];
    unsigned int frames;
};

int fn_2_1EA2C(void) {
    unsigned int value = fn_800506DC();
    Game* game = (Game*)g_GameGlobal;
    unsigned int quotient = ((State*)game->state)->frames / 60;
    int a = *fn_8004E6B8(g_GameGlobal);
    int b = *fn_8004E6C4(g_GameGlobal);

    fn_8004F258(&value, quotient, 0x157529FF);
    fn_8004F258(&value, a, 0x157529FF);
    fn_8004F258(&value, b, 0x157529FF);
    return value;
}
}
