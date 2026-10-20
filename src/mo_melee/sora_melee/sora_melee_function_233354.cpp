#include <types.h>
#pragma force_active on

extern "C" int fn_40_F8E0(char* self, unsigned int id, unsigned char* out);

struct Inner {
    u8 pad[8];
    u32 id;
};

struct Elem {
    u8 pad[0xc];
    u32 state;
    Inner* inner;
};

struct Self {
    u8 pad[0x54];
    Elem** list;
    u32 count;
};

extern "C" void fn_27_233354(Self* self, u32 id) {
    u8 buf;
    for (u32 i = 0; i < self->count; i++) {
        if (self->list[i]->inner->id == id) {
            self->list[i]->state = 3;
            fn_40_F8E0((char*)self->list[i], id, &buf);
        }
    }
}
