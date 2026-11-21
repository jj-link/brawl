#include <types.h>
#include <so/controller/so_controller_module_impl.h>
#pragma force_active on

struct Data {
    u8 b4;
    u8 pad[3];
    u32 w[20];
    u8 c[0x32];
};

struct Ctrl {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13(int, int);
    Data d;
};

struct Entry {
    u32 z;
    Data d;
};

struct Arr {
    virtual void v0();
    virtual Entry* get(int i);
};

struct Acc { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual int get(); };
struct D { u8 pad[0x44]; Acc* p; };
struct E { u8 pad[0xd8]; D* d; };

struct Impl {
    void* vt;
    u8 pad0[0x28];
    E* owner;
    Ctrl ctrl;
    u8 pad[0x148 - 0x30 - sizeof(Ctrl)];
    Arr* arr;
    int p14c;
    int cnt;
    int idx;
    int p158;
    int size;
    int clatter;
    int p164;
    u8 flag;
};

struct WordPair { u32 v[2]; };
#define WP(n) *(WordPair*)&e->w[n] = *(WordPair*)&s->w[n];
struct BytePair { u8 v[32]; };
#define CP(n) *(BytePair*)&e->c[n] = *(BytePair*)&s->c[n];
#define CS(n) e->c[n] = s->c[n];

extern "C" void fn_27_150688(Impl* self, int a, u32 b) {
    int r = self->owner->d->p->get();
    if (b == 1) self->ctrl.a13(a, r);
    if (self->flag == 1) {
        if (self->cnt < self->size) self->cnt++;
        if (self->cnt > 0) {
            if (++self->idx >= self->size) self->idx = 0;
            Data* e = &self->arr->get(self->idx)->d;
            Data* s = &self->ctrl.d;
            e->b4 = s->b4;
            WP(0) WP(2) WP(4) WP(6) WP(8) WP(10) WP(12)
            e->w[14] = s->w[14];
            WP(15) WP(17)
            e->w[19] = s->w[19];
            CP(0)
            CS(32) CS(33) CS(34) CS(35) CS(36) CS(37) CS(38) CS(39) CS(40) CS(41) CS(42) CS(43) CS(44) CS(45) CS(46) CS(47) CS(48) CS(49)
        }
    }
    self->ctrl.a13(a, r);
    ((soControllerModuleImpl*)self)->updateClatter((soController*)&self->ctrl);
    if (self->clatter > 0) self->clatter--;
}