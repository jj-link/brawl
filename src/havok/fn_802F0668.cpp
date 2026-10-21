#include <types.h>
#pragma force_active on

class Foo {
public:
    virtual void call(int);
    u16 f4;
    s16 f6;
};

extern "C" {
void fn_802F0668(Foo* obj) {
    if (obj->f4 == 0)
        return;
    if ((obj->f6 -= 1) != 0)
        return;
    if (obj != 0)
        obj->call(1);
}
}
