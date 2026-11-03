#pragma force_active on

class Class_71D8 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10E70();
    virtual void fn_109_119D4();
    virtual void fn_109_119CC();
    virtual void fn_109_119C4();
    virtual void fn_109_119BC();
    virtual void fn_109_119B4(int, bool);
    virtual void fn_109_119AC(int);
    virtual void fn_109_119A4();
    virtual void fn_109_1199C();
    virtual void fn_109_11994();
    virtual void fn_109_1198C();
    virtual void fn_109_11984();
    virtual void fn_109_1197C();
    virtual void fn_109_1192C();
    virtual void fn_109_11974();
    virtual void fn_109_11964();
    virtual void fn_109_11954();
    virtual void fn_109_11944();
    virtual void fn_109_11934(int);
    virtual void fn_109_unk58();
};

class R10Base {
public:
    virtual void base08();
};

struct Pad4 {
    int pad0;
};

class R10 : public Pad4, public R10Base {
public:
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(int, int);
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual int ve4(int, int);
};

struct Modules {
    char pad0[0x10];
    R10* m10;
    Class_71D8* m14;
    char pad18[0x40];
    Class_71D8* m58;
    char pad5c[8];
    Class_71D8* m64;
};

struct Fighter {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_109_DDB0(void*, Fighter* fighter) {
    fighter->modules->m58->fn_109_119AC(1);
    fighter->modules->m64->fn_109_11934(0x12000001);
    R10* r31 = fighter->modules->m10;
    if (r31->ve4(8, 0)) {
        fighter->modules->m14->fn_109_119B4(0, false);
        r31->v54(1, 0);
    }
}
