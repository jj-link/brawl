// The interface pointer for this entry points 0xF4 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13DD00 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2D8,0xE2E0) is the raw word pair 3863ff0c 48015c1c
// = addi r3,r3,-0xF4 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2DC (m27 import-stream entry) carries addend 0x13DD00, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E208->0x135468, E270->0x135EB4, E278->0x13C428
// exactly, and every section-1 REL24 word0 in the module is a branch to the
// unresolved veneer (evidence/rel_decode_e2d8.py).
//
// Slot-run context: the -0xE8 run ends at E2D0; the -0xF4 run opens at E2D8
// and continues at E2E0 (0x13C7D0), E2E8 (0x13CAF8) and E2F0 (0x13C724).
// fn_27_13DD00 is the shared power/task-notification slot: ft_luigi's
// fn_99_BBA8 and ft_metaknight's fn_111_C6E8 are the same -0xF4 adjustor
// with the identical callee.
//
// fn_27_13DD00's machine-verified contract (sora_melee .text 0x13DD00, size
// 0x1F0, extracted to evidence/fn_27_13DD00.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the object (mr r31, r3) and the
// float argument (fmr f31, f1), then reads the object's word 40
// (lwz r0,40(r3)) and compares the incoming integer argument against it
// (cmplw r4, r0) with an early return on equality; the float argument is
// re-loaded from f31 for two later virtual calls (fmr f1,f31 at 0x15C and
// 0x1B4). Every other use of r4/r5/r6 is a write (li/addi/lwz/mr) and
// r7-r10 are never touched, so forwarding the interface words is complete
// and harmless. Both registered fighter spellings of this slot
// (ft_luigi fn_99_BBA8, ft_metaknight fn_111_C6E8) agree on a void return,
// so no result pointer is involved.
#include <types.h>

extern "C" void fn_27_13DD00(void* object, float power, int taskId);

extern "C" void fn_117_E2D8(void* interface, float power, int taskId) {
    fn_27_13DD00(static_cast<u8*>(interface) - 0xF4, power, taskId);
}
