#pragma force_active on

extern "C" void fn_800FD5D0(void);
extern "C" void fn_8000D7B8(void*);
extern "C" void fn_800BF830(void*);
extern "C" void exit__6gfTaskFv(void*);
extern void* g_gfSceneRoot;

struct Pad10 {
    char pad[0x10];
};
struct Iface10 : Pad10 {
    virtual void fn_802CE61C(int);
};

struct PadCC {
    char pad[0xCC];
};
struct IfaceCC : PadCC {
    virtual void destroy(int);
};

struct Pad1C {
    char pad[0x1C];
};
struct Iface1C : Pad1C {
    virtual void destroy(int);
};

extern "C" void fn_800FCA50(char* self) {
    void* p18 = *(void**)(self + 0x18);
    if (p18 != 0) {
        if (p18 != 0) {
            ((Iface10*)p18)->fn_802CE61C(1);
        }
        *(void**)(self + 0x18) = 0;
    }

    char* q = self;
    for (int i = 0; i < 7; i++) {
        void* p = *(void**)(q + 0x1C);
        if (p != 0) {
            if (p != 0) {
                ((Iface1C*)p)->destroy(1);
            }
            *(void**)(q + 0x1C) = 0;
        }
        q += 4;
    }

    fn_800FD5D0();

    void* p38 = *(void**)(self + 0x38);
    if (p38 != 0) {
        if (p38 != 0) {
            ((IfaceCC*)p38)->destroy(1);
        }
    }

    fn_8000D7B8(g_gfSceneRoot);

    void* p40 = *(void**)(self + 0x40);
    if (p40 != 0) {
        exit__6gfTaskFv(p40);
        *(void**)(self + 0x40) = 0;
    }

    void* p3C = *(void**)(self + 0x3C);
    if (p3C != 0) {
        exit__6gfTaskFv(p3C);
        *(void**)(self + 0x3C) = 0;
    }

    if (*(void**)(self + 0x44) != 0) {
        fn_800BF830(*(void**)(self + 0x44));
        exit__6gfTaskFv(*(void**)(self + 0x44));
        *(void**)(self + 0x44) = 0;
    }
}
