#pragma force_active on

struct Mem {
    char pad[0x1c];
    int value;
};

struct Flags165 {
    unsigned char a : 4;
    unsigned char b : 2;
    unsigned char c : 2;
};

extern "C" void fn_27_1B614(void* self, int a, int b, int c, short* d, int e, float f);

class Inner {
public:
    virtual void v0() = 0;
    virtual Mem* v1(int idx) = 0;
};

class Outer {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;

    char pad0[0x88];
    Inner* m8c;
    char pad1[0xd5];
    Flags165 f165;
};

extern "C" void fn_27_17444(Outer* self, int arg, float f) {
    short sp[4];
    self->v48();
    int val = self->m8c->v1(arg)->value;
    sp[0] = 0x20;
    fn_27_1B614(self, arg, val, 1, &sp[0], 0, f);
    sp[2] = 0x80;
    fn_27_1B614(self, arg, val, 0, &sp[2], 0, f);
    self->f165.b = 1;
}
