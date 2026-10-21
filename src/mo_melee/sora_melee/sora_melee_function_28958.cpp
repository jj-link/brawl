#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

class Self {
public:
    u8 pad[8];
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
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual u32 get();
};

struct A {
    u8 pad[0xF];
    u8 flags;
};

struct B {
    u8 pad[0x54];
    u8 flags;
};

struct C {
    u8 pad[0x2C];
    u8 flags;
};

struct Bits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Local {
    u32 id;
    u8 pad[4];
    A* a;
    B* b;
    C* c;
    u8 byte;
    Bits bits;

    bool valid() const {
        return a && b && c;
    }
};

extern "C" u32 fn_80111CB0(void*, void*);

extern "C" int fn_27_28958(Self* self) {
    u32 id = self->get();
    if (id == 0xFFFF)
        return 1;

    Local l;
    l.id = id;
    l.a = 0;
    l.b = 0;
    l.c = 0;
    l.byte = 0;
    l.bits.hi = 0;

    if (fn_80111CB0(&l.id, &l.a) == 0)
        return 1;

    bool valid = l.valid();
    int enabled;
    if (valid && ((l.b->flags >> 4) & 1) &&
        ((l.c->flags >> 7) & 1))
        enabled = 1;
    else
        enabled = 0;

    if (!enabled)
        return 1;

    return (l.a->flags >> 7) & 1;
}
