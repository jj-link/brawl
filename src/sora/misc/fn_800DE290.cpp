#pragma force_active on
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void fn_800B8A0C(void*, int);

struct Base {
    char pad[0x5C];
};
struct Entry : Base {
    virtual void f2(int);
};

extern "C" void fn_800DE290(char* self) {
    char* q = self;
    for (int i = 0; i < 4; i++) {
        void* p = *(void**)(q + 0x154);
        if (p != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(p);
            *(void**)(q + 0x154) = 0;
        }
        q += 4;
    }

    q = self;
    for (int i = 0; i < 0x51; i++) {
        Entry* e = *(Entry**)(q + 0x10);
        if (e != 0) {
            if (e != 0) {
                e->f2(1);
            }
            *(void**)(q + 0x10) = 0;
        }
        q += 4;
    }

    void* p = *(void**)(self + 0x164);
    if (p != 0) {
        fn_800B8A0C(p, 1);
        *(void**)(self + 0x164) = 0;
    }
}