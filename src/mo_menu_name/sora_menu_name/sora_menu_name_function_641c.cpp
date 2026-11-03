#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

struct Obj {
    unsigned char pad0[0x9C];
    int f9c;
    unsigned char padA0[0x4];
    int fA4;
    unsigned char padA8[0x3B4];
    int f45c;
    unsigned char pad460[0x18];
    int f478;
};

extern "C" int fn_16_641C(Obj* self) {
    int state;

    if (self->f478 < 0)
        return 0x18;

    void* task = (void*)self->f45c;
    if (*(int*)((char*)task + 0x104) != 3) {
        state = 0;
    } else {
        state = 2;
        if (*(unsigned char*)((char*)task + 0x100))
            state = 1;
        exit__6gfTaskFv(task);
        self->f45c = 0;
    }

    if (state == 0)
        return self->f9c;
    if (state == 1) {
        self->fA4 = 0x15;
        return 0xb;
    }
    return 0x10;
}