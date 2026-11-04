#include <internal/mem.h>
#pragma force_active on
extern "C" int fn_800BA3D8(void*);

struct Entry29 {
    signed char id;
    char pad[19];
};
struct Obj29 {
    char pad0[0x164];
    int indices[10];
    int count;
    char pad190[4];
    char sub194[0xA8];
    int alternate;
    char pad240[0x24];
    int selection;
    char pad268[4];
    Entry29 entries[11];
    int* output;
};

extern "C" void fn_29_21F0(Obj29* self) {
    if (self->output != 0) {
        memset(self->output, 0, 0x68);
        for (int i = 0; i < self->count; ++i) {
            self->output[i] = self->entries[self->indices[i]].id;
            self->output[i + 10] = 0x3E;
        }
        self->output[20] = self->count;
        self->output[23] = self->selection;
        if ((((unsigned int)fn_800BA3D8(self->sub194) >> 31) ^ 1) != 0) {
            int index;
            if (self->selection == 0) {
                index = self->indices[0];
            } else {
                index = self->alternate;
            }
            self->output[21] = self->entries[index].id;
            self->output[22] = 0x3E;
        } else {
            self->output[21] = 0x28;
            self->output[22] = 0x3E;
        }
    }
}
