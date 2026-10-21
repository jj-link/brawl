#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

#define V1(n) virtual void unused##n();
#define V4(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3)
#define V16(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3)

struct Work {
    V4(w)
    V1(w4)
    virtual void set(void*, u32);
};

struct Modules {
    u8 pad[0x64];
    Work* work;
};

struct Accesser {
    u8 pad[0xd8];
    Modules* modules;
};

struct Fighter {
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

#undef V16
#undef V4
#undef V1

extern "C" void fn_27_13138C(Fighter*, int, int, void*, Accesser*);
extern "C" void* fn_27_1D53E4(void*, u32, u32);

extern "C" void fn_101_C2E4(
    Fighter* self, int status, int previous, void* data, Accesser* accesser)
{
    fn_27_13138C(self, status, previous, data, accesser);

    if (status == 0x116) {
        void** p = self->get();
        void* value = fn_27_1D53E4((u8*)*p + 0x9e8, 0xc, 0);
        Work* w = accesser->modules->work;
        w->set(value, 0x10000041);
    }
}
