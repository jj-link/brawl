#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);
extern "C" void fn_16_AF8(void*);
extern "C" void fn_800B8A0C(void*, int);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Base {
    char pad[0x5C];
};
struct Entry : Base {
    virtual void f2(int);
};

extern "C" void fn_16_228C(char* self) {
    void* p408 = *(void**)(self + 0x408);
    if (p408 != 0) {
        exit__6gfTaskFv(p408);
        *(void**)(self + 0x408) = 0;
    }

    void* p45C = *(void**)(self + 0x45C);
    if (p45C != 0) {
        exit__6gfTaskFv(p45C);
        *(void**)(self + 0x45C) = 0;
    }

    fn_16_AF8(self + 0x158);

    void* p154 = *(void**)(self + 0x154);
    if (p154 != 0) {
        fn_800B8A0C(p154, 1);
        *(void**)(self + 0x154) = 0;
    }

    char* q = self;
    for (int i = 0; i < 3; i++) {
        unsigned char flag = *(unsigned char*)(self + 0x3F4);
        if (flag == 0 || i < 0 || i > 1) {
            void* p = *(void**)(q + 0x8C);
            if (p != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(p);
                *(void**)(q + 0x8C) = 0;
            }
        }
        q += 4;
    }

    q = self;
    for (int i = 0; i < 0x13; i++) {
        unsigned char flag = *(unsigned char*)(self + 0x3F4);
        if (flag == 0 || i < 0 || i > 3) {
            Entry* e = *(Entry**)(q + 0x40);
            if (e != 0) {
                if (e != 0) {
                    e->f2(1);
                }
                *(void**)(q + 0x40) = 0;
            }
        }
        q += 4;
    }
}