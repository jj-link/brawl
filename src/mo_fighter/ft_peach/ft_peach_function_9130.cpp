#include <types.h>
#pragma force_active on

extern "C" {

void* fn_103_9190(void* self);
void fn_27_3313B4(void* a, void* b);
void fn_27_12DCA8(void* a);

struct ObjC {
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
    virtual s32 m16();
};

struct ObjD {
    u8 pad[0x70];
    ObjC* c;
};

struct ObjB {
    u8 pad[0xd8];
    ObjD* d;
};

struct ObjA {
    u8 pad[0x60];
    ObjB* b;
};

void fn_103_9130(ObjA* self) {
    ObjC* c = self->b->d->c;
    s32 result = c->m16();
    if (result == 0x112) {
        fn_27_3313B4(fn_103_9190((void*)result), self->b);
    }
    fn_27_12DCA8(self);
}

}
