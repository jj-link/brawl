#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Entry24 {
    u32 value;
    u8 pad[0x20];
};

struct Entry14 {
    u32 value;
    u8 pad[0x10];
};

struct Entry10 {
    u32 value;
    u8 pad[0xC];
};

struct Owner {
    u8 pad[0x40];
    Entry24* table40;
    Entry24* table44;
    Entry14* table48;
    Entry10* table4C;
    s32 enabled;
};

extern "C" s32 fn_27_22AD58(Owner*, Entry24*, u32, u32*);
extern "C" s32 fn_27_22AF0C(Owner*, Entry14*, u32, u32*);
extern "C" s32 fn_27_22B010(Owner*, Entry10*, u32, u32*);

extern "C" void fn_27_22B194(Owner* self, u32 key) {
    u32 idx;

    if (self->enabled != 0) {
        if (fn_27_22AD58(self, self->table40, key, &idx) != 0) {
            self->table40[idx].value = 0;
        }
        if (fn_27_22AD58(self, self->table44, key, &idx) != 0) {
            self->table44[idx].value = 0;
        }
        if (fn_27_22AF0C(self, self->table48, key, &idx) != 0) {
            self->table48[idx].value = 0;
        }
        if (fn_27_22B010(self, self->table4C, key, &idx) != 0) {
            self->table4C[idx].value = 0;
        }
    }
}
