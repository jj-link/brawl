#include <types.h>
#pragma force_active on

struct Data {
    u64 a;
    s32 c;
    s32 d;
};

struct GameInner {
    u8 pad[0x30];
    Data data;
};

struct GameGlobalObj {
    u8 pad[8];
    GameInner* inner;
};

extern "C" {
extern GameGlobalObj* g_GameGlobal;

void fn_80050BB0(Data*, s32);

void fn_8005136C(s32 arg0) {
    Data data;
    GameInner* inner = g_GameGlobal->inner;
    data.a = inner->data.a;
    data.c = inner->data.c;
    data.d = inner->data.d;
    fn_80050BB0(&data, arg0);
}
}
