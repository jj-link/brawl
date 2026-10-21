#pragma force_active on

struct GameMode {
    char pad[4];
    unsigned char mode;
};

struct GameGlobal {
    char pad[0x10];
    GameMode* mode;
};

struct Player {
    int kind;
    char pad[0x1B0];
    int state;
};

struct Menu {
    char pad[0x44];
    Player* players[4];
    char pad2[0x648 - 0x54];
    int count;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern int g_muWifiInterfaceTask;

int fn_10_12E58(void*);
int fn_800D64A8(int, int);

int fn_10_61D8(Menu* self) {
    Menu* cursor;
    int i;
    int result;
    int active;
    int waiting;
    int wifi = g_muWifiInterfaceTask;
    result = 0;
    active = 0;
    waiting = 0;

    if ((int)g_GameGlobal->mode->mode == 12) {
        cursor = self;
        for (i = 0; i < self->count;
             cursor = (Menu*)((char*)cursor + 4), ++i) {
            Player* player = cursor->players[0];
            switch (player->kind) {
            default:
                break;
            case 2:
                break;
            case 0:
                if (player->state != 2)
                    ++active;
                else
                    ++waiting;
                break;
            case 1:
                int state = fn_10_12E58(player);
                if (state == 0 && fn_800D64A8(wifi, i) != 0)
                    ++waiting;
                if ((unsigned int)(state - 1) <= 1)
                    ++active;
                break;
            }
        }

        if (waiting > 0 && active < 3)
            result = 1;
    }

    return result;
}
}
