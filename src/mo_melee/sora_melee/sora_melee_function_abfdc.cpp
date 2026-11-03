#include <types.h>
#pragma force_active on

struct Data {
    u32 a;
    u32 b;
    u32 c;
    s16 d;
    s16 e;
};

class Array {
public:
    virtual void v0() = 0;
    virtual Data* get(s32 idx) = 0;
    virtual void v2() = 0;
    virtual s32 getCount() = 0;
};

class Handler {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void handle(Data** data) = 0;
};

extern "C" void fn_27_7756C(Data* dst, const Data* src);
extern "C" void fn_27_AB41C(s16* dst, const Data* src);

struct Container {
    u32 pad0;
    u32 pad4;
    Array* arr;
};

extern "C" void fn_27_ABFDC(Container* self, s16* flag, Handler* handler) {
    Data local;
    Data* src;
    s32 i = 0;
    while (i < self->arr->getCount()) {
        src = self->arr->get(i);
        fn_27_7756C(&local, src);
        local.c = src->c;
        local.d = src->d;
        local.e = src->e;
        s16 result;
        fn_27_AB41C(&result, &local);
        if (result & *flag) {
            Data* p = &local;
            handler->handle(&p);
        }
        i++;
    }
}