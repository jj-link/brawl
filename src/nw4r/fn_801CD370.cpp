#pragma force_active on
struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void cleanup();
};

extern "C" {
extern char lbl_80466C30[];
char* fn_801CC2E4();
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void fn_801C093C(void*, void*, int);
void fn_801CD318(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_8015C238(void*, int);
void fn_801CF9D4(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_801CD370(void* self, int flag) {
    char* p = (char*)self;
    if (p) {
        *(void**)p = lbl_80466C30;
        *(void**)(p + 0x7c) = lbl_80466C30 + 0x24;
        OSLockMutex(fn_801CC2E4() + 0x354);
        ((Object*)p)->cleanup();
        if (*(unsigned char*)(p + 0xb8) == 0) {
            OSUnlockMutex(fn_801CC2E4() + 0x354);
        } else {
            *(int*)(p + 0x7b8) = 0;
            fn_801C093C(p + 0x134, p + 0x138, 0x680);
            *(unsigned char*)(p + 0xb8) = 0;
            OSUnlockMutex(fn_801CC2E4() + 0x354);
        }
        __destroy_arr(p + 0x138, fn_801CD318, 0x34, 0x20);
        void* a = p + 0x128;
        if (a) fn_8015C238(a, 0);
        void* b = p + 0x108;
        if (b) fn_801CF9D4(b, 0);
        if (flag > 0) __dl__FPv(p);
    }
    return self;
}
