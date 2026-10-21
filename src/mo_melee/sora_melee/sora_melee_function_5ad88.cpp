#include <types.h>
#pragma force_active on

extern "C" char lbl_27_data_61F8[];
extern "C" char lbl_27_data_6168[];
extern "C" char __vt__22soAnimCmdEventObserver[];

class Query {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s16 get();
};

class Observer {
public:
    virtual void attach(s32, s32);
    s16 a;
    s16 b;
    s16 c;
    u8 d;
    u8 e;
};

struct Self {
    void* vt;
    Observer sub;
    void* arg;
};

extern "C" void* fn_27_5AD88(Self* self, u8* arg) {
    self->vt = lbl_27_data_61F8;
    u8* obj = *(u8**)(*(u8**)(arg + 0xD8) + 0x80);
    s16 r = ((Query*)(obj + 8))->get();
    self->sub.a = -1;
    self->sub.b = 5;
    self->sub.c = -1;
    *(void**)&self->sub = __vt__22soAnimCmdEventObserver;
    self->sub.attach((s32)r, -1);
    self->sub.d = 1;
    self->vt = lbl_27_data_6168;
    *(void**)&self->sub = lbl_27_data_6168 + 0x34;
    self->arg = arg;
    return self;
}
