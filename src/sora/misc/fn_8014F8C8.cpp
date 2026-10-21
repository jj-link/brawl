#pragma force_active on
typedef unsigned char u8;

struct GameGlobal {
    char pad[0x34];
    struct Obj *obj;
};

struct Obj {
    char pad[0x17];
    u8 b17;
    u8 b18;
    u8 b19;
    u8 b1A;
};

extern struct GameGlobal *g_GameGlobal;

extern "C" {
void fn_8014F8C8(unsigned int arg0, int arg1, int arg2) {
    struct Obj *o = g_GameGlobal->obj;
    o->b17 = (u8)((arg0 >> 8) & 0xFF);
    o->b18 = (u8)arg0;
    o->b19 = (u8)arg1;
    o->b1A = (u8)arg2;
}
}
