#include <types.h>
#pragma force_active on

struct AiScript;

struct AiSelfC728 {
    u8 pad[0x60];
    u32 m_value;
};

extern "C" {
void fn_27_20DB40(AiScript*, u32, s8*, u32, u32);

void fn_27_20C728(AiSelfC728* self, u32 value) {
    s8 buf = -1;
    fn_27_20DB40(reinterpret_cast<AiScript*>(self), 0, &buf, 0, 0);
    self->m_value = value;
}
}
