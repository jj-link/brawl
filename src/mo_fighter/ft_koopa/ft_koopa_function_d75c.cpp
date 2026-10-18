#pragma force_active on
extern "C" {
void fn_102_D694(void* arg);
void fn_102_D75C(void* arg);
}

struct A {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(int, int);
};

struct B {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4C(int);
    virtual void v50();
    virtual void v54();
    virtual void v58(int);
};

struct CBase {
    void* p0;
    void* p4;
};

struct CWrap : CBase {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C(int, int);
};

struct UnkD8 {
    char pad0[0x10];
    CWrap* m10;
    A* m14;
    char pad1[0x64 - 0x18];
    B* m64;
};

struct Fighter {
    char pad[0xD8];
    UnkD8* mD8;
};

void fn_102_D75C(void* arg) {
    Fighter* f = (Fighter*)arg;
    B* b = f->mD8->m64;
    int result = f->mD8->m14->v0C();
    b->v58(2);
    b->v4C(0x22000010);
    b->v4C(0x22000011);
    f->mD8->m14->v18(2, 0);
    f->mD8->m10->v4C(5, 0);
    if (result != 2) {
        b->v48(0x22000012);
        fn_102_D694(arg);
    } else {
        b->v4C(0x22000012);
    }
}
