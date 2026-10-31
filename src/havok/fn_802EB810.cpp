#pragma force_active on

struct Param {
    char padding0[0x10];
    int offset;
    char padding1[4];
    signed char state;
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Param*);
    virtual unsigned int v7();
    virtual void v8(Param*);
};

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void*);
    virtual unsigned int v7(void*);
    virtual void v8(void*);
};

struct ObjB {
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
    virtual unsigned int v18(void*, Param*);
};

extern "C" void fn_802EB810(Obj* a, Param* p, ObjB* b) {
    unsigned int c1 = a->v7() >> 24;
    void* field = (char*)a + 0x1c;

    if ((signed char)(b->v18(field, p) >> 24) != 0) {
        if ((signed char)c1 == 0) {
            a->v6(p);
        }
        if (p->state == 2) {
            if ((signed char)(((Target*)((char*)p + p->offset))->v7(field) >> 24) == 0) {
                ((Target*)((char*)p + p->offset))->v6(field);
            }
        }
    } else {
        if ((signed char)c1 != 0) {
            a->v8(p);
        }
        if (p->state == 2) {
            if ((signed char)(((Target*)((char*)p + p->offset))->v7(field) >> 24) != 0) {
                ((Target*)((char*)p + p->offset))->v8(field);
            }
        }
    }
}
