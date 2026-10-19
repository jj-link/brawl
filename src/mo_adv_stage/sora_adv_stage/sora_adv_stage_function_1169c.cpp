#include <types.h>
#pragma force_active on

// Placeholder type: the real class is not identified. Only the word at offset 0x8 is known from the assembly.
struct AdvStageFlagObject {
    u32 m_0x0;
    u32 m_0x4;
    u32 m_flags : 5;      // top 5 bits of the word at 0x8 (CodeWarrior allocates bitfields from the MSB)
    u32 m_0x8_rest : 27;  // remaining bits of the word at 0x8
};

// Writes the low 5 bits of `flags` into bits 31..27 of the word at offset 0x8.
// Note: sora_adv_stage_function_12258.cpp declares fn_40_1169C(void*) with one parameter,
// which conflicts with the second argument (r4) that this function reads.
extern "C" void fn_40_1169C(AdvStageFlagObject* self, u32 flags) {
    self->m_flags = flags;
}
