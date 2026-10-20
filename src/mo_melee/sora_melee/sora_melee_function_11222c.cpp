#include <types.h>
#pragma force_active on

struct B { char pad[0x4b0]; int val; };
struct A { B* ptr; };

extern "C" int fn_27_11222C(const A* a) {
    return a->ptr->val;
}
