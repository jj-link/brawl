#pragma force_active on

typedef unsigned char u8;

extern "C" {
char* fn_801CC2E4();
void OSLockMutex(void*);
void OSUnlockMutex(void*);
void fn_801C4DEC(void*);
void fn_801CC818(void*, void*);
void* fn_801BE7BC();
void fn_801BE8D0(void*, void*);
void __dl__FPv(void*);
extern char lbl_804669F0[];
}

struct Callee {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void*);
};

struct Obj {
    char pad[0x7C];
    void* sub7C;      // 0x7C
    char pad2[0xB4 - 0x80];
    Callee* callee;   // 0xB4
    void* items[16];  // 0xB8
};

extern "C" void* fn_801C3040(void* arg0, int arg1) {
    int i;
    Obj* self = (Obj*)arg0;
    if (self != 0) {
        *(void**)self = lbl_804669F0;
        self->sub7C = lbl_804669F0 + 0x24;
        *(void**)((char*)self + 0x88) = lbl_804669F0 + 0x38;
        OSLockMutex((void*)((char*)fn_801CC2E4() + 0x354));
        if (*(u8*)((char*)self + 0x8D) != 0) {
            char* ptr = (char*)self;
            if (self != 0) {
                ptr = (char*)self + 0x80;
            }
            fn_801CC818(fn_801CC2E4(), ptr);
            *(u8*)((char*)self + 0x8D) = 0;
        }
        if (*(u8*)((char*)self + 0x8C) != 0) {
            char* ptr = (char*)self;
            if (self != 0) {
                ptr = (char*)self + 0x74;
            }
            fn_801BE8D0(fn_801BE7BC(), ptr);
            *(u8*)((char*)self + 0x8C) = 0;
        }
        i = 0;
        char* p = (char*)self;
        do {
            OSLockMutex((void*)((char*)fn_801CC2E4() + 0x354));
            void* item;
            if (i > 15) {
                item = 0;
            } else {
                item = *(void**)(p + 0xB8);
            }
            if (item == 0) {
                OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
            } else {
                fn_801C4DEC(item);
                self->callee->vf2(*(void**)(p + 0xB8));
                *(void**)(p + 0xB8) = 0;
                OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
            }
            i++;
            p += 4;
        } while (i < 16);
        OSUnlockMutex((void*)((char*)fn_801CC2E4() + 0x354));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return self;
}
