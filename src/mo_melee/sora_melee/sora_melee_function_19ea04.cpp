#include <types.h>
#pragma force_active on

extern "C" {

struct fn27_struct {
    s32 m_00;
    s32 m_04;
    s32 m_08;
};

s32 fn_27_19EA04(fn27_struct* p) {
    return p->m_08 >> 26;
}

}
