#include <types.h>
#pragma force_active on

struct fn27Entry {
    char* m_base;
    s32 m_count;
};

extern "C" {
void fn_27_120304(char* p);

void fn_27_122078(fn27Entry* arr) {
    for (s32 i = 0; i < arr->m_count; i++) {
        fn_27_120304(arr->m_base + i * 0x4d4);
    }
}
}
