#pragma force_active on
struct Mod58 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void f24(int);
};
struct Mod64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void f54(int);
};
struct Mod84 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void f48(int, int);
};
struct Modules {
    char pad0[0x58];
    Mod58* m58;
    char pad5c[0x8];
    Mod64* m64;
    char pad68[0x1c];
    Mod84* m84;
};
struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

extern "C" void fn_27_13138C(void*, int, int, void*, Accesser*);
extern "C" void fn_27_12D904(void*, bool, bool, int);

extern "C" void fn_107_ADB0(void* self, int prev, int status, void* data, Accesser* acc) {
    fn_27_13138C(self, prev, status, data, acc);
    if (prev != status) {
        Modules* m = acc->modules;
        Mod84* o = m->m84;
        switch (status) {
        case 0x24:
        case 0x25:
            if (prev != 0x24 && prev != 0x25) {
                o->f48(6, 0);
            }
            break;
        case 0x29:
            o->f48(6, 0);
            break;
        case 0x2a:
        case 0x2b:
        case 0x2c:
            if (prev != 0x2a && prev != 0x2b && prev != 0x2c) {
                o->f48(6, 0);
            }
            break;
        case 0x18:
        case 0x33:
            if (prev != 0x33 && prev != 0x18) {
                o->f48(6, 0);
            }
            break;
        case 0x116:
            if (prev < 0x11d || prev > 0x138) {
                m->m58->f24(1);
                o->f48(5, 0);
                fn_27_12D904(self, true, true, 0);
            }
            break;
        }
        if (status >= 0x11d && status <= 0x138 && (prev < 0x11d || prev > 0x138)) {
            acc->modules->m64->f54(0x12000041);
            acc->modules->m58->f24(1);
            o->f48(5, 0);
            fn_27_12D904(self, true, true, 0);
        }
    }
}
