#pragma force_active on
extern "C" bool fn_96_E110(void*);
extern "C" void fn_96_D5C4(void*, void*, int);

struct V64 {
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
    virtual void check(unsigned int);
};

struct V14 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int get();
};

struct V70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void set(int, void*);
};

struct Inner {
    char pad0[0x14];
    V14* v14obj;
    char pad1[0x4C];
    V64* v64obj;
    char pad2[0x8];
    V70* v70obj;
};

struct Outer {
    char pad[0xd8];
    Inner* inner;
};

struct Self {
    char pad[0x60];
    Outer* outer;
};

extern "C" void fn_96_DC08(void* self) {
    Self* s = (Self*)self;
    if (fn_96_E110(self)) {
        s->outer->inner->v64obj->check(0x12000042);
        if (s->outer->inner->v14obj->get() == 2) {
            s->outer->inner->v70obj->set(0xe, s->outer);
        } else {
            s->outer->inner->v70obj->set(0, s->outer);
        }
    }
    fn_96_D5C4(self, s->outer, 1);
}
