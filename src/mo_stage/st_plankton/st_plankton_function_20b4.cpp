#pragma force_active on

typedef unsigned char u8;

struct Entry {
    u8 state;
    u8 pad[11];
};

struct Obj {
    u8 pad[0x3D8];
    Entry entries[16];
};

extern "C" u8 fn_74_20B4(Obj* self) {
    u8 i;
    for (i = 0; i < 16; ++i) {
        if (self->entries[i].state == 3) break;
    }
    return i;
}
