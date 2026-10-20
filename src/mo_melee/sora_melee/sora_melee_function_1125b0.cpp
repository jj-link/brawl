#include <types.h>
#pragma force_active on

typedef struct {
    char _pad[0x6c];
    s32 m_6c;
} someStruct;

extern "C" s32 fn_27_1125B0(someStruct** p) {
    return p[0]->m_6c;
}
