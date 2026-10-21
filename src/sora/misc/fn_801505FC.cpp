#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad0[0x1A];
    u8 count;
};

struct Global {
    char pad0[0x38];
    Obj* obj;
};

extern "C" {
extern Global* g_GameGlobal;

void fn_801505FC(void) {
    Obj* o = g_GameGlobal->obj;
    o->count = o->count + 1;
}
}
