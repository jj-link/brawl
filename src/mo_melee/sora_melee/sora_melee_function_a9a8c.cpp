#include <types.h>
#pragma force_active on

struct fn27Obj {
    char pad[0x20];
    char* m_a;
    char* m_b;
    char* m_c;
    s32 m_count;
};

extern "C" {
void fn_27_A90F8(char* a, char* b, char* c);

void fn_27_A9A8C(fn27Obj* self) {
    s32 off20 = 0;
    s32 off18 = 0;
    s32 i = 0;
    for (; i < self->m_count; i++) {
        fn_27_A90F8(self->m_b + off18, self->m_a, self->m_c + off20);
        off20 += 0x20;
        off18 += 0x18;
    }
}
}
