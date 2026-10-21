#include <types.h>
#pragma force_active on

struct ftOuter {
    u8 pad[0x1D];
    u8 flags;
};

struct Arr {
    virtual void isNull() const = 0;
    virtual ftOuter* at(s32 i);
    virtual ftOuter* atC(s32 i) const;
    virtual s32 size() const;
};

struct Notify {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void update();
};

struct Other {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void update();
};

struct Owner {
    u8 pad[0x30];
    Arr* arr;
    Notify* notify;
    Other* other;
    u8 pad3C[9];
    u8 high : 1;
    u8 enabled : 1;
    u8 low : 6;
};

extern "C" void fn_27_A7610(ftOuter*, int);

extern "C" void fn_27_A3F40(Owner* self, bool flag) {
    if (self->enabled != flag) {
        s32 end = self->arr->size();
        for (s32 i = 0; i < end; ++i) {
            if ((self->arr->at(i)->flags >> 6) & 1U) {
                fn_27_A7610(self->arr->at(i), flag);
            }
        }
        self->enabled = flag;
        self->notify->update();
        self->other->update();
    }
}
