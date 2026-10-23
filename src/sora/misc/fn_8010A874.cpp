#pragma force_active on

extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

struct Base {
    char pad[0x5C];
};

struct Entry : Base {
    virtual void destroy(int);
};

extern "C" void fn_8010A874(char* self) {
    char* q = self;
    for (int i = 0; i < 7; i++) {
        Entry* p = *(Entry**)(q + 0xE8);
        if (p != 0) {
            if (p != 0) {
                p->destroy(1);
            }
            *(Entry**)(q + 0xE8) = 0;
        }
        q += 4;
    }

    void* g3d = *(void**)(self + 0x110);
    if (g3d != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(g3d);
        *(void**)(self + 0x110) = 0;
    }
}
