#pragma force_active on

#include <gf/gf_heap_manager.h>

extern "C" {
int fn_8014CEC4(void* self);
int fn_8014DD34(void* self, int flag);
int fn_8014E720(void* self);
int fn_8014EA8C(void* self, int value, void* buf);
}

struct Self {
    char pad0[0x4];
    Heaps::HeapType heap4;
    char pad8[0x24 - 0x8];
    int state24;
    int unk28;
    char pad2c[0x80 - 0x2c];
    char unk80[0x8];
    void* unk88;
    unsigned char unk8C;
    char pad8d[3];
    int unk90;
};

extern "C" void fn_8014E344(void* p) {
    Self* self = (Self*)p;

    switch (self->state24) {
    case 0:
        break;
    case 1:
        if (fn_8014CEC4(self) != 0) {
            self->unk90 = 0;
        } else {
            self->unk90 = -1;
        }
        break;
    case 2: {
        int r = fn_8014E720(self);
        if (r == 0) {
            self->unk90 = 0;
        } else if (r == -1) {
            self->unk90 = -1;
        } else {
            self->unk90 = -4;
        }
        break;
    }
    case 3:
        self->unk88 = gfHeapManager::alloc(self->heap4, 0x23000, 0x20);
        if (self->unk88 != 0) {
            self->unk90 = fn_8014EA8C(self, self->unk28, self->unk80);
            gfHeapManager::free(self->unk88);
            self->unk88 = 0;
        } else {
            self->unk90 = -1;
        }
        break;
    case 4:
        if (fn_8014DD34(self, 1) != 0) {
            self->unk90 = 0;
        } else {
            self->unk90 = -1;
        }
        break;
    }

    self->unk8C = 1;
}
