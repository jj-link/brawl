#pragma force_active on

#include <types.h>
#include <gf/gf_task_scheduler.h>

extern "C" void fn_27_140CC4(void* self, s32 arg);

class Actor {
public:
    virtual void h0();
    virtual signed char category();
    virtual signed char state();
};

class SubA {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual s32 a4();
};

class SubB {
public:
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual s32 b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23(void* p);
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35(s32 p, s32 q);
};

class SubC {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void* c17(s32 id);
};

struct Y {
    u8 pad0[0x14];
    SubA* a;
    u8 pad1[0x64 - 0x18];
    SubC* c;
    u8 pad2[0x70 - 0x68];
    SubB* b;
};

struct Ctx {
    u8 pad0[0xD8];
    Y* y;
};

struct Element {
    s32 unk0;
    void** items;
    s32 count;
};

struct ElementList {
    Element* elems;
    s32 count;
};

class Owner {
public:
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
    virtual int accept(signed char kind);
    u8 pad0[0x28];
    Ctx* ctx;
    ElementList* list;
    s32 unk34;
    u8 unk38;
    u8 unk39;
};

extern "C" int fn_27_140E20(Owner* self, Actor* arg) {
    if (self->accept(arg->category()) == 0) {
        return 0;
    }
    if (arg->state() <= -1 || arg->state() >= 3) {
        return 0;
    }
    switch (arg->state()) {
    case 0: {
        if (self->ctx->y->c->c17(0x1200000B) == 0 &&
            self->ctx->y->c->c17(0x1200002B) == 0 &&
            self->ctx->y->c->c17(0x1200002D) == 0 &&
            self->ctx->y->c->c17(0x12000018) == 0 &&
            self->unk39 != 1) {
            gfTaskScheduler* gi = gfTaskScheduler::getInstance();
            if (gi == 0 || ((s32)((s32)((*(s32*)gi << 8) & 0xFF800000) >> 0x18)) >= 6) {
                fn_27_140CC4(self, self->ctx->y->a->a4());
                if (self->ctx->y->b->b16() == 0x29) {
                    self->ctx->y->b->b35(0x2743, 8);
                }
                self->unk38 = 1;
            }
        }
        return 1;
    }
    case 1: {
        s32 i;
        s32 j;
        s32 off;
        s32 k;
        for (i = 0, off = 0; self->list->count > i; off += 0xC, i++) {
            for (j = 0, k = 0; j < ((Element*)(off + (u32)self->list->elems))->count; k += 4, j++) {
                self->ctx->y->b->b23(*(void**)(k + (u8*)((Element*)(off + (u32)self->list->elems))->items));
            }
        }
        self->unk38 = 0;
        self->unk34 = -1;
        return 1;
    }
    case 2:
        self->v4();
        return 1;
    default:
        return 0;
    }
}
