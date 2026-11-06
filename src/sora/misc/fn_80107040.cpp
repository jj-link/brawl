#pragma force_active on

extern "C" void* fn_800DFC68(void);
extern "C" void fn_8010C0DC(void*, void*);
extern "C" void fn_8010C9D8(void*);
extern "C" void fn_800DFC08(void);
extern "C" void* fn_8010B9E4(void*, int);
extern "C" void fn_8010BE98(void);
extern "C" void fn_80108A04(void*, int);
extern "C" void fn_80108DE4(void);
extern "C" void* fn_801080EC(void*, int);
extern "C" void fn_801084CC(void);
extern "C" void fn_8010A874(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void fn_8000D7B8(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void fn_8010D00C(void);
extern void* g_gfSceneRoot;

struct Pad1E0 {
    char pad[0x1E0];
};

struct Iface1E0 : Pad1E0 {
    virtual void destroy(int);
    virtual void f1(void);
    virtual void f2(void);
};

struct Pad5D4 {
    char pad[0x5D4];
};

struct Iface5D4 : Pad5D4 {
    virtual void destroy(int);
    virtual void f1(void);
    virtual void f2(void);
};

extern "C" void fn_80107040(char* self) {
    if (*(void**)(self + 0x104) != 0) {
        fn_8010C0DC(*(void**)(self + 0x104), fn_800DFC68());
    }
    if (*(void**)(self + 0x104) != 0) {
        fn_8010C9D8(*(void**)(self + 0x104));
    }

    void* p108 = *(void**)(self + 0x108);
    if (p108 != 0) {
        if (p108 != 0) {
            ((Iface1E0*)p108)->destroy(1);
        }
        *(void**)(self + 0x108) = 0;
    }

    char* q = self;
    for (int i = 0; i < 7; i++) {
        void* p = *(void**)(q + 0xE8);
        if (p != 0) {
            if (p != 0) {
                ((Iface5D4*)p)->destroy(1);
            }
            *(void**)(q + 0xE8) = 0;
        }
        q += 4;
    }

    fn_800DFC08();
    void* p104 = *(void**)(self + 0x104);
    if (p104 != 0) {
        fn_8010B9E4(p104, 1);
        *(void**)(self + 0x104) = 0;
    }

    fn_8010BE98();
    void* p6C = *(void**)(self + 0x6C);
    if (p6C != 0) {
        fn_80108A04(p6C, 1);
        *(void**)(self + 0x6C) = 0;
    }

    fn_80108DE4();
    void* p60 = *(void**)(self + 0x60);
    if (p60 != 0) {
        fn_801080EC(p60, 1);
        *(void**)(self + 0x60) = 0;
    }

    fn_801084CC();
    void* p74 = *(void**)(self + 0x74);
    if (p74 != 0) {
        fn_8010A874(p74);
    }

    void* p44 = *(void**)(self + 0x44);
    if (p44 != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p44);
        *(void**)(self + 0x44) = 0;
    }

    fn_8000D7B8(g_gfSceneRoot);
    void* p0 = *(void**)(self + 0x0);
    if (p0 != 0) {
        exit__6gfTaskFv(p0);
        *(void**)(self + 0x0) = 0;
    }

    fn_8010D00C();
    void* p8 = *(void**)(self + 0x8);
    if (p8 != 0) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p8);
        *(void**)(self + 0x8) = 0;
    }
}
