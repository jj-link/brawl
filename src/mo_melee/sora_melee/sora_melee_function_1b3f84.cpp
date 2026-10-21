#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct C {
    Pair p;
    u32 c;
    float d;
};

#define D(x) virtual void f##x() {}
class V1 {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25)
    virtual C* getSrc();
};
class V2 {
public:
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25)
    virtual C* getDst(u32 idx);
};

extern "C" void fn_27_1B3F84(V1* self, void* unused, u32 idx) {
    C* src = self->getSrc();
    C* dst = ((V2*)self)->getDst(idx);
    *dst = *src;
}