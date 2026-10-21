#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 pad[0x83];
    u8 hi : 6;
    u8 bit1 : 1;
    u8 lo : 1;
};

struct GameGlobal {
    u8 pad[0x34];
    Obj* obj;
};

extern GameGlobal* g_GameGlobal;

extern "C" {
void fn_8014FE04(int arg0) {
    Obj* o = g_GameGlobal->obj;
    if (arg0 != 0) {
        o->bit1 = 1;
    } else {
        o->bit1 = 0;
    }
}
}
