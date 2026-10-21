#include <types.h>
#pragma force_active on

struct MenuObject {
    unsigned char padding[0x5C];
    virtual void slot08(int);
};

struct Self {
    unsigned char pad0[0x40];
    unsigned int handle;
    unsigned char f44[4];
    void* f48;
    unsigned char pad4C[0x68];
    unsigned int fB4;
};

extern "C" {
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_8018E808(void*);
}

extern "C" void fn_25_11B4(Self* self) {
    switch ((int)self->fB4) {
    case 1:
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle));
        break;
    case 2:
        break;
    }
    release__14gfFileIOHandleFv(&self->handle);
    fn_8018E808(&self->f44[0]);
    MenuObject* m = (MenuObject*)self->f48;
    if (m != nullptr) {
        m->slot08(1);
    }
    self->f48 = 0;
}
