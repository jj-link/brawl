#pragma force_active on

typedef unsigned char u8;

struct State {
    char pad[0x604];
    u8 mode;
};

struct Players {
    char pad[0x151];
    u8 first;
    char pad2[0x5B];
    u8 second;
};

struct GameGlobal {
    char pad[8];
    Players* players;
    char pad2[0x24];
    State* state;
};

struct Manager {
    char pad[0x48];
    u8 flag : 1;
    u8 rest : 7;
    char pad2[0xBB];
    void* object;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern Manager* g_IfAdvMngr;

void fn_801077D0(Manager*, int);
void fn_80106E48(Manager*);
void fn_8010C38C(void*);
void fn_801071E4(Manager*);

void fn_27_240E6C() {
    int count = 2;
    State* state = g_GameGlobal->state;

    if (state->mode == 3) {
        Players* players = g_GameGlobal->players;
        if (players->first != 3)
            count = 3;
        if (players->second != 3)
            ++count;
    }

    if (g_IfAdvMngr) {
        fn_801077D0(g_IfAdvMngr, count);
        fn_80106E48(g_IfAdvMngr);

        if (state->mode == 2)
            fn_8010C38C(g_IfAdvMngr->object);

        g_IfAdvMngr->flag = 0;
        fn_801071E4(g_IfAdvMngr);
    }
}
}
