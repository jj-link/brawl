#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void __dt__9gfArchiveFv(void*, int);
extern "C" void fn_18_FA0(void*);

struct Pad5C {
    char pad[0x5C];
};

struct Iface5C : Pad5C {
    virtual void destroy(int);
    virtual void f1(void);
    virtual void f2(void);
};

struct Pad668 {
    char pad[0x668];
};

struct Iface668 : Pad668 {
    virtual void destroy(int);
    virtual void f1(void);
    virtual void f2(void);
};

extern "C" int fn_1_136A4(char* self) {
    void* p7B4 = *(void**)(self + 0x7B4);
    if (p7B4 != 0) {
        exit__6gfTaskFv(p7B4);
        *(void**)(self + 0x7B4) = 0;
    }

    exit__6gfTaskFv(*(void**)(self + 0x7B8));
    *(void**)(self + 0x7B8) = 0;
    exit__6gfTaskFv(*(void**)(self + 0x7BC));
    *(void**)(self + 0x7BC) = 0;

    char* q = self;
    for (unsigned int i = 0; i < 0x1D; i++) {
        Iface668* p = *(Iface668**)(q + 0x35C);
        if (p != 0) {
            p->destroy(1);
        }
        *(void**)(q + 0x35C) = 0;
        q += 4;
    }

    q = self;
    for (unsigned int i = 0; i < 0x1E; i++) {
        Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(q + 0x738));
        *(void**)(q + 0x738) = 0;
        q += 4;
    }

    q = self;
    for (unsigned int i = 0; i < 0xD6; i++) {
        Iface5C* e = *(Iface5C**)(q + 0x3E0);
        if (e != 0) {
            e->destroy(1);
        }
        *(void**)(q + 0x3E0) = 0;
        q += 4;
    }

    __dt__9gfArchiveFv(*(void**)(self + 0xAA4), 1);
    __dt__9gfArchiveFv(*(void**)(self + 0xAA8), 1);

    if (*(void**)(self + 0x7C0) != 0) {
        fn_18_FA0(*(void**)(self + 0x7C0));
        exit__6gfTaskFv(*(void**)(self + 0x7C0));
        *(void**)(self + 0x7C0) = 0;
    }
    return 0;
}
