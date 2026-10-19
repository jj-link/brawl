#pragma force_active on
struct SubObj {
    char pad[0x603];
    unsigned char flag;
};

struct GameGlobal {
    char pad[0x30];
    SubObj* sub;
};

extern GameGlobal* g_GameGlobal;

struct grYakumono {
    signed char getPlayerNumber(int* p);
};

extern "C" void fn_40_3C24C(grYakumono* self, int unused, int* p) {
    if (g_GameGlobal->sub->flag == 0) {
        if (!self->getPlayerNumber(p)) {
            *((char*)self + 0x188) = 1;
        }
    }
}
