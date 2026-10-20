#include <types.h>
#pragma force_active on

namespace {
    class I {
    public:
        virtual ~I() {}
        virtual void f0() = 0;
        virtual void f1() = 0;
        virtual void f2() = 0;
        virtual void f3() = 0;
        virtual void f4() = 0;
        virtual void f5() = 0;
        virtual void f6() = 0;
        virtual void f7() = 0;
    };

    class Obj {
        char a[0x24];
    public:
        I* m24;
        I* m28;
        I* m2c;
    };
}

extern "C" void fn_27_B5EF0(Obj* o) {
    o->m24->f7();
    o->m2c->f7();
    o->m28->f7();
}
