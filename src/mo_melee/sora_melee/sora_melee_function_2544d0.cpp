#include <types.h>
#pragma force_active on

struct X {
    char _0x40[0x40];
    bool m_isSomething;
};

extern "C" void fn_27_2544D0(X* obj) {
    obj->m_isSomething = true;
}
