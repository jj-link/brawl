#pragma force_active on

extern "C" {

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void exit__6gfTaskFv(void*);
void fn_8000D7B8(void*);
void fn_800DFC08(void);
void fn_80108DE4(void);
void fn_80108A04(void*, int);
extern void* g_gfSceneRoot;

struct Pad0x8 { char pad[0x8]; };
struct Iface0x8 : Pad0x8 { virtual void foo(int) = 0; };

struct Pad0x74 { char pad[0x74]; };
struct Iface0x74 : Pad0x74 { virtual void foo(int) = 0; };

struct Pad0xCC { char pad[0xCC]; };
struct Iface0xCC : Pad0xCC { virtual void foo(int) = 0; };

struct Pad0x124 { char pad[0x124]; };
struct Iface0x124 : Pad0x124 { virtual void foo(int) = 0; };

struct Pad0x1E0 { char pad[0x1E0]; };
struct Iface0x1E0 : Pad0x1E0 { virtual void foo(int) = 0; };

struct Pad0x300 { char pad[0x300]; };
struct Iface0x300 : Pad0x300 { virtual void foo(int) = 0; };

struct Pad0x5D4 { char pad[0x5D4]; };
struct Iface0x5D4 : Pad0x5D4 { virtual void foo(int) = 0; };

void fn_800DC2E0(void* arg0) {
    char* self = (char*)arg0;

    // f44
    Iface0x1E0* p44 = *(Iface0x1E0**)(self + 0x44);
    if (p44) {
        if (p44) {
            p44->foo(1);
        }
        *(Iface0x1E0**)(self + 0x44) = 0;
    }

    // Loop over 7 entries at offset 0x4C
    char* q = self;
    for (int i = 0; i < 7; i++) {
        Iface0x5D4* p = *(Iface0x5D4**)(q + 0x4C);
        if (p) {
            if (p) {
                p->foo(1);
            }
            *(Iface0x5D4**)(q + 0x4C) = 0;
        }
        q += 4;
    }

    fn_800DFC08();

    // f70
    Iface0x74* p70 = *(Iface0x74**)(self + 0x70);
    if (p70) {
        if (p70) {
            p70->foo(1);
        }
        *(Iface0x74**)(self + 0x70) = 0;
    }

    // f74
    Iface0x124* p74 = *(Iface0x124**)(self + 0x74);
    if (p74) {
        if (p74) {
            p74->foo(1);
        }
        *(Iface0x124**)(self + 0x74) = 0;
    }

    // f78
    Iface0x300* p78 = *(Iface0x300**)(self + 0x78);
    if (p78) {
        if (p78) {
            p78->foo(1);
        }
        *(Iface0x300**)(self + 0x78) = 0;
    }

    // f94
    if (*(void**)(self + 0x94)) {
        fn_80108DE4();
        fn_80108A04(*(void**)(self + 0x94), 1);
        *(void**)(self + 0x94) = 0;
    }

    // f8C
    Iface0xCC* p8C = *(Iface0xCC**)(self + 0x8C);
    if (p8C) {
        if (p8C) {
            p8C->foo(1);
        }
        *(Iface0xCC**)(self + 0x8C) = 0;
        *(void**)(self + 0xAC) = 0;
    }

    // fB0
    void* pB0 = *(void**)(self + 0xB0);
    if (pB0) {
        exit__6gfTaskFv(pB0);
        *(void**)(self + 0xB0) = 0;
    }

    // f9C
    void* p9C = *(void**)(self + 0x9C);
    if (p9C) {
        exit__6gfTaskFv(p9C);
        *(void**)(self + 0x9C) = 0;
    }

    // fB8
    Iface0x8* pB8 = *(Iface0x8**)(self + 0xB8);
    if (pB8) {
        if (pB8) {
            pB8->foo(1);
        }
        *(Iface0x8**)(self + 0xB8) = 0;
    }

    // g_gfSceneRoot
    fn_8000D7B8(g_gfSceneRoot);

    // fA0
    void* pA0 = *(void**)(self + 0xA0);
    if (pA0) {
        exit__6gfTaskFv(pA0);
        *(void**)(self + 0xA0) = 0;
    }

    // fA4
    void* pA4 = *(void**)(self + 0xA4);
    if (pA4) {
        exit__6gfTaskFv(pA4);
        *(void**)(self + 0xA4) = 0;
    }

    // f8
    void* p8 = *(void**)(self + 0x8);
    if (p8) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p8);
        *(void**)(self + 0x8) = 0;
    }

    // fC
    void* pC = *(void**)(self + 0xC);
    if (pC) {
        Destroy__Q34nw4r3g3d6G3dObjFv(pC);
        *(void**)(self + 0xC) = 0;
    }

    // f10
    void* p10 = *(void**)(self + 0x10);
    if (p10) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p10);
        *(void**)(self + 0x10) = 0;
    }

    // f14
    void* p14 = *(void**)(self + 0x14);
    if (p14) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p14);
        *(void**)(self + 0x14) = 0;
    }

    // f18
    void* p18 = *(void**)(self + 0x18);
    if (p18) {
        Destroy__Q34nw4r3g3d6G3dObjFv(p18);
        *(void**)(self + 0x18) = 0;
    }
}

}