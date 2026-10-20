#include <types.h>
#pragma force_active on

namespace {
    struct Target {
        virtual void func0();
        virtual void func1();
        virtual void func2();
        virtual void func3();
        virtual void func4();
        virtual void func5();
        virtual void func6();
    };

    struct Outer {
        u8 padding[0x1e70];
        Target target;
    };
}

extern "C" void fn_27_318C24(void* self) {
    reinterpret_cast<Outer*>(self)->target.func6();
}
