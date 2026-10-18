#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

#define V1(n) virtual void unused##n();
#define V4(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3)
#define V16(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3)

struct Module {
    V16(m)
    virtual void clear(int, int);
};

struct Work {
    V4(w)
    V1(w4)
    virtual void set(void*, u32);
};

struct Modules {
    u8 pad[0x64];
    Work* work;
    u8 pad2[0x1c];
    Module* module;
};

struct Accesser {
    u8 pad[0xd8];
    Modules* modules;
};

struct FighterBase {
    u8 pad[0x3c];
    V16(f0)
    V16(f1)
    V16(f2)
    V16(f3)
    V16(f4)
    V16(f5)
    V16(f6)
    V16(f7)
    V16(f8)
    V16(f9)
    V16(fa)
    V4(fb0)
    V4(fb1)
    V1(fb2)
    virtual void** get();
};

struct Fighter : FighterBase {
    u8 pad2[0x20];
    Accesser* accesser;
};

#undef V16
#undef V4
#undef V1

extern "C" void fn_27_13138C(Fighter*, int, int, void*, Accesser*);
extern "C" void* fn_27_1D53E4(void*, u32, u32);

extern "C" void fn_114_B2F8(
    Fighter* self, int status, int previous, void* data, Accesser* accesser)
{
    fn_27_13138C(self, status, previous, data, accesser);

    if (previous == 0x34 || previous == 0x36 || previous == 0x38) {
        if (status != 0x35 && status != 0x37) {
            Module* m = self->accesser->modules->module;
            m->clear(4, 0);
        }
    } else if (previous == 0x35 || previous == 0x37 || previous == 0x10c) {
        Module* m = self->accesser->modules->module;
        m->clear(4, 0);
    }

    if (status == 0x116) {
        void** p = self->get();
        void* value = fn_27_1D53E4((u8*)*p + 0x9e8, 0xc, 0);
        Work* w = accesser->modules->work;
        w->set(value, 0x10000041);
    }
}
