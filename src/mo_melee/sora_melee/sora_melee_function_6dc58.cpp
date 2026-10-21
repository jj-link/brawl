#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

class VObj {
public:
    virtual void v0();
    virtual void* v1(u32);
};

struct ModPtr {
    u32 a;
    void* ptr;
};

struct Data {
    u8 pad[0xd8];
    ModPtr* modules;
};

struct Accessor {
    u8 pad[0x44];
    Data* data;
};

class MMod {
public:
    u32 a;
    u32 b;

    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40(u32, u32, u32);
};

struct Self {
    u8 pad[0x38];
    u32 m38;
    u8 pad1[0xC];
    VObj* m48;
    u8 pad2[4];
    u32 m50;
};

extern "C" Accessor* fn_27_6F30C(void*);

extern "C" void fn_27_6DC58(Self* self, u32 arg2, u32 arg3) {
    void* result = self->m48->v1(self->m38);
    Accessor* acc = fn_27_6F30C((char*)result + 0x1c);
    MMod* mod = (MMod*)acc->data->modules->ptr;
    mod->m40(self->m50, arg2, arg3);
}
