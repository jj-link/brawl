#pragma force_active on

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)

struct Hdr8 { int a; int b; };

struct M10 : Hdr8 {
    V32(a) V16(b) V4(c) V2(d) V1(e)
    virtual unsigned int f55(int, int);
};

struct M14 {
    V4(a) V2(b)
    virtual void f6(int, bool);
};

struct M64 {
    V4(a) V1(b)
    virtual void f5(unsigned int, unsigned int);
};

struct M70 {
    V2(a) V1(b)
    virtual void f3(int, void*);
    V8(c) V4(d)
    virtual int f16();
};

struct R : Hdr8 {
    V8(a) V2(b)
    virtual unsigned int f10();
    virtual void f11();
    virtual unsigned int f12();
};

struct M90 {
    V8(a) V4(b) V1(c)
    virtual int f13(int);
    V8(e) V4(f) V2(g)
    virtual R* f28();
};

struct Modules {
    char pad0[0x10];
    M10* m10;
    M14* m14;
    char pad18[0x64 - 0x18];
    M64* m64;
    char pad68[0x70 - 0x68];
    M70* m70;
    char pad74[0x90 - 0x74];
    M90* m90;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

struct Object {
    char pad0[0x60];
    Accesser* accesser;
};

extern "C" void fn_27_1DA034(void);
extern "C" bool fn_113_18F40(void*, int);

static inline bool checkB(int value) {
    switch (value) {
    case 0x2b:
    case 0x2c:
    case 0x2d:
        return true;
    default:
        return false;
    }
}

static inline bool checkA(int value) {
    switch (value) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        return true;
    default:
        return false;
    }
}

extern "C" void fn_113_17D1C(Object* self) {
    fn_27_1DA034();
    int value = self->accesser->modules->m70->f16();
    if (checkB(value) == true) {
        if (self->accesser->modules->m10->f55(8, 0) == 1U) {
            if (checkA(value) == false) {
                if (self->accesser->modules->m90->f13(0) == 0 ||
                    self->accesser->modules->m90->f28()->f10() == 0U) {
                    self->accesser->modules->m14->f6(0, false);
                    Accesser* acc = self->accesser;
                    acc->modules->m70->f3(6, acc);
                }
            }
        }
    } else if (fn_113_18F40(self, value) == 1U) {
        if (self->accesser->modules->m90->f13(0) == 1U) {
            if (self->accesser->modules->m90->f28()->f10() == 1U) {
                Accesser* acc = self->accesser;
                acc->modules->m70->f3(0x2b, acc);
                self->accesser->modules->m64->f5(
                    self->accesser->modules->m90->f28()->f12(), 0x20000002U);
            }
        }
    }
}
