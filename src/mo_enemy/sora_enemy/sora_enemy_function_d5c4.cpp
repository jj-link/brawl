#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u8 flag;
    u8 pad[0xB];
    u32 key;
};

struct Owner {
    u8 pad[0xC];
    u32 count;
};

extern "C" Entry* fn_41_D5A0(Owner* self, u32 index);

extern "C" Entry* fn_41_D5C4(Owner* self, u32 key) {
    u32 i;
    Entry* e;
    for (i = 0; i < self->count; i++) {
        e = fn_41_D5A0(self, i);
        if (e != 0 && e->flag != 0 && e->key == key) {
            return e;
        }
    }
    return 0;
}
