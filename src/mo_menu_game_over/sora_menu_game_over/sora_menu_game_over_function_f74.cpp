#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <types.h>
#pragma force_active on

extern "C" {
int fn_800B61C0(void* res);
void fn_12_588(void* self, int value);
}

struct Self {
    char _0[0x40];
    void* m_res;
    int m_result;
};

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

extern "C" int fn_12_F74(Self* self) {
    if (fn_800B61C0(self->m_res) != 0 || getSysPad().m_buttonsPressedThisFrame.bits != 0) {
        fn_12_588(self, 5);
        return 6;
    }
    return self->m_result;
}
