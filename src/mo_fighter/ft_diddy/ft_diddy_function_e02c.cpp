#pragma force_active on

struct Mod {
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
    virtual void v17(float, unsigned int);
    virtual int v18();
};

struct Comp {
    char a[0x64];
    Mod* m64;
    char b[0x8];
    Mod* m70;
};

struct Fighter {
    char pad[0xd8];
    Comp* comp;
};

extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern const float lbl_115_rodata_3C;
extern unsigned char lbl_27_bss_7B0C[];

extern "C" void fn_115_E02C(void*, Fighter* f) {
    int r = f->comp->m70->v18();
    int s = fn_27_30FACC(lbl_27_bss_7B0C, 0, r, f, 1);

    switch (s) {
    case 0x117:
        f->comp->m64->v17(lbl_115_rodata_3C, 0x21000004);
        break;
    case 0x119:
        f->comp->m64->v17(lbl_115_rodata_3C, 0x21000005);
        break;
    }
}
