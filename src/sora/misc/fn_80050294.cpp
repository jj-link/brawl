#pragma force_active on

struct GameGlobalX {
    unsigned char* field0;
    short* field4;
    unsigned char* field8;
    unsigned char* fieldC;
    unsigned char* field10;
};

extern "C" {
extern char* fn_8004DA14(void*, int, int);
extern GameGlobalX* g_GameGlobal;

void fn_80050294() {
    int off4 = 0;
    int off10 = 0;
    int i = 0;
    do {
        *(short*)((int)g_GameGlobal->field4 + off4) = 0;
        unsigned char* base = g_GameGlobal->field10 + off10;
        int v = base[0xd0];
        if (v != 0x78) {
            short* p = (short*)fn_8004DA14(g_GameGlobal, i, v);
            if (p)
                *p = 0;
        }
        i++;
        off4 += 2;
        base = g_GameGlobal->field10 + off10;
        *(short*)(base + 0xde) = 0;
        off10 += 0x5c;
    } while (i < 4);
}
}
