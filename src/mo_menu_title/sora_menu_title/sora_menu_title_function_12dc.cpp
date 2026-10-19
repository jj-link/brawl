#include <types.h>
#pragma force_active on

struct ChildPad {
    u8 pad[0x5C];
};

struct Child : ChildPad {
    virtual void slot0(int);
};

struct Self {
    u8 pad[0x44];
    void* f44;
    Child* f48;
};

extern "C" {
void fn_8018E808(void*);
void exit__6gfTaskFv(void*);
}

extern "C" void fn_24_12DC(Self* self) {
    fn_8018E808((u8*)self + 0x40);
    exit__6gfTaskFv(self->f44);
    Child* c = self->f48;
    self->f44 = nullptr;
    if (c != nullptr) {
        c->slot0(1);
    }
    self->f48 = nullptr;
}
