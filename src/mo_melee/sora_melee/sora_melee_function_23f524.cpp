#include <types.h>

#pragma force_active on

struct Inner {
    char pad[0x1A];
    u16 kind;
};

struct Obj {
    char pad[0x40];
    Inner* inner;
};

struct Data {
    char pad[0x604];
    u8 value;
};

struct Global {
    char pad[0x30];
    Data* data;
};

extern Global* g_GameGlobal;

extern "C" int fn_27_23F524(Obj* obj) {
    u16 kind = obj->inner->kind;

    if (kind == 0x27) return 0x100000;
    if (kind == 0x13) return 0x366640;
    if (kind == 0x19) return 0x4B3300;
    if (kind == 0x35) return 0x100000;

    if (kind == 0x3D) {
        u8 value = g_GameGlobal->data->value;
        if (value == 3) goto found;
        if (value != 4) goto other;
    found:
        return 0x2840;
    other:
        return 0x400000;
    }

    if (kind == 0x1F) return 0x100000;
    return 0x2000;
}
