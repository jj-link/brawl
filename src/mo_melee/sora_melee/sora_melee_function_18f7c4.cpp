#pragma force_active on
struct Obj14 {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

struct Obj54 {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15(int, void*);
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

struct Obj70 {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3(int, void*);
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

struct Sub {
    char pad0[0x14];
    Obj14* p14;
    char pad1[0x3c];
    Obj54* p54;
    char pad2[0x18];
    Obj70* p70;
};

struct Actor {
    char pad0[0xd8];
    Sub* sub;
};

struct Local {
    int x;
    char y;
    int z;
    int w;
    int v;
    float f;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
};

extern "C" float lbl_27_rodata_2630;

extern "C" {
void fn_27_18F7C4(void* unused, Actor* actor) {
    if (actor->sub->p14->v3() == 0) {
        Local local;
        local.x = 0x29;
        local.y = 0;
        local.z = -1;
        local.w = -1;
        local.v = 0;
        local.f = lbl_27_rodata_2630;
        actor->sub->p54->v15(4, &local);
        actor->sub->p70->v3(0x4a, actor);
    }
}
}
