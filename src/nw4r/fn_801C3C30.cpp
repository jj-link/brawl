#pragma force_active on
extern "C" {
    char* fn_801CC2E4();
    void OSLockMutex(void* m);
    void OSUnlockMutex(void* m);
    void fn_801C3D3C(void*, int);
    void fn_801C3FA0(void*);
    void fn_801C51F4(void*);
}

struct Obj {
    char pad[0x8c];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad2[0x9c - 0x8f];
    int d;
    float e;
    char pad3[0xb8 - 0xa4];
    void* slots[16];
};

extern float lbl_805A3584;

extern "C" void fn_801C3C30(Obj* self) {
    int i;
    Obj* p = self;
    OSLockMutex(fn_801CC2E4() + 0x354);
    if (self->a == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }
    if (self->b == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }
    if (self->d != 0 || self->e > lbl_805A3584) {
        fn_801C3FA0(self);
    } else if (self->c == 0) {
        fn_801C3D3C(self, 3);
    }
    OSLockMutex(fn_801CC2E4() + 0x354);
    i = 0;
    do {
        void* s;
        if (i > 15) s = 0; else s = *(void**)((char*)p + 0xb8);
        if (s != 0) fn_801C51F4(s);
        i++;
        p = (Obj*)((char*)p + 4);
    } while (i < 16);
    OSUnlockMutex(fn_801CC2E4() + 0x354);
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}