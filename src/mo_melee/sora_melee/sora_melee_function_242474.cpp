#include <types.h>
#pragma force_active on

class Foo {
public:
    void a();
    void b();
    void c();
    void d();
    void e();
    void f();
    char pad[0x40];
    u8 m_40;
};

struct FooTable {
    void (Foo::*p[6])();
};

extern const FooTable lbl_27_rodata_3DC0;

extern "C" void fn_27_242474(Foo* self) {
    FooTable t = lbl_27_rodata_3DC0;
    (self->*t.p[self->m_40])();
}
