#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry48 {
    u8 data[0x30];
};

struct Data {
    u16 flags;
    u16 index;
    u8 pad[0x30];
    Entry48 a[32];
};

struct Entry {
    u32 flags;
    u8 light[0x40];
};

struct Object {
    u16 count;
    u16 pad2;
    u32 entries;
    u8 pad8[8];
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    signed char slots[8];
};

extern Data lbl_804A7F40;
extern "C" void fn_801B6708(void*);
extern "C" void fn_801B6898(void*, void*, u16);
extern "C" void fn_801F2418(void*, u32);

extern "C" void fn_8019EBAC(Object* self, u16* arg) {
    u32 offset;
    u32 one;

    fn_801B6708(self);
    fn_801B6898(self, &lbl_804A7F40.a[lbl_804A7F40.index], *arg);

    self->field10 = -1;
    u32 count = self->count;
    self->field14 = 0;
    self->field18 = 0;
    self->field1C = 0;
    self->field20 = 0;

    self->slots[0] = self->slots[1] = self->slots[2] = self->slots[3] =
        self->slots[4] = self->slots[5] = self->slots[6] = self->slots[7] = -1;

    u32 slot = 0;
    u32 i = 0;
    one = 1;
    offset = 0;

    for (; slot < 8 && i < count; offset += 0x44, ++i) {
        Entry* entry = (Entry*)((u8*)self->entries + offset);
        if (entry->flags & 4) {
            self->slots[slot] = i;
            fn_801F2418(entry->light, 1 << slot);
            ++slot;
        }
    }
}
