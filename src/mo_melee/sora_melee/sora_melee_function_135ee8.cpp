#pragma force_active on
struct Iface {
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
    virtual void v16(int, int);
    virtual void v17();
    virtual void v18();
    virtual int v19(unsigned int, void*);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual int v36(int);
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40(int, float);
    virtual void v41(int);
};

struct Modules {
    char pad0[0x20];
    Iface* a;
    char pad1[4];
    Iface* b;
    char pad2[0x38];
    Iface* c;
    char pad3[0x20];
    Iface* d;
};

struct Owner {
    char pad[0xd8];
    Modules* modules;
};

extern const int lbl_27_rodata_1038[4];
extern const float lbl_27_rodata_1048;

extern "C" void fn_27_135EE8(void*, int kind, Owner* owner) {
    int tbl;
    int cur = owner->modules->a->v36(0);
    if (cur != kind && (tbl = lbl_27_rodata_1038[kind]) >= 0) {
        owner->modules->d->v41(tbl);
    }
    if (cur == 0) {
        if (owner->modules->c->v19(0x12000035, owner->modules) == 1U) {
            owner->modules->b->v16(2, 1);
        }
    } else {
        if ((tbl = lbl_27_rodata_1038[cur]) >= 0) {
            owner->modules->d->v40(tbl, lbl_27_rodata_1048);
        }
        if (owner->modules->c->v19(0x12000035, owner->modules) == 1U) {
            owner->modules->b->v36(1);
        }
    }
}
