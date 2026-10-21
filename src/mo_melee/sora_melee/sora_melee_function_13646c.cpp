#pragma force_active on
typedef unsigned int u32;

class Iface {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, u32);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(u32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual u32 v14(u32);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59(u32, u32);
};

class Sub {
public:
    char pad0[0x18];
    Iface* a;
    char pad1[0xA8 - 0x1C];
    Iface* b;
};

class Mid {
public:
    char pad[0xD8];
    Sub* sub;
};

class Outer {
public:
    char pad[0x60];
    Mid* mid;
};

extern "C" void fn_27_13646C(Outer* self, u32 arg1, u32 arg2) {
    Mid* m = self->mid;
    m->sub->a->v3(arg1, 0);
    m->sub->a->v9(arg2);
    if (m->sub->b->v14(0) == 1) {
        m->sub->b->v59(arg1, 0);
    }
}
