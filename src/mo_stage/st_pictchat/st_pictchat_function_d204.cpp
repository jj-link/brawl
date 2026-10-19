#pragma force_active on
struct Object;
struct Part;

struct PartVTable {
    char pad[0x18];
    void (*invoke)(Part*, int, int);
};

struct Part {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void invoke(int, int);
    int unk4;
    int state;
};

struct ObjectVTable {
    char pad[0x70];
    void (*invoke)(Object*);
};

struct Header {
    char pad0[0x3c];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void invoke();
};

struct Object : Header {
    char pad40[0x90];
    Part part;
    char padDC[0xc4];
    unsigned char a;
    int b;
    int c;
    unsigned char d;
    int e;
    unsigned char f;
    unsigned char g;
};

extern "C" void __ct__15grGimmickLadderFPCc(Object*, const char*);
extern "C" ObjectVTable lbl_73_data_4E28;

extern "C" Object* fn_73_D204(Object* self, const char* name) {
    __ct__15grGimmickLadderFPCc(self, name);
    *(ObjectVTable**)((char*)self + 0x3c) = &lbl_73_data_4E28;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->e = 0;
    self->f = 0;
    self->g = 0;

    Part* part = &self->part;
    if (!part)
        return self;

    part->state = 1;
    part->invoke(0, 15);
    self->invoke();
    return self;
}
