// The interface pointer for this entry points 0xF4 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13CAF8 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2E8,0xE2F0) is the raw word pair 3863ff0c 48015c0c
// = addi r3,r3,-0xF4 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2EC (m27 import-stream entry) carries addend 0x13CAF8, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E2D8->0x13DD00, E2E0->0x13C7D0 and E2F0->0x13C724
// exactly, and every section-1 REL24 word0 in the module is a branch to the
// unresolved veneer (evidence/rel_decode_e2e8.py).
//
// Slot-run context: the -0xF4 run opens at E2D8 (0x13DD00) and continues at
// E2E0 (0x13C7D0), E2E8 (0x13CAF8) and E2F0 (0x13C724); the -0xE8 run ends at
// E2D0. fn_27_13CAF8 is the shared single-object-pointer slot: ft_luigi's
// fn_99_BBB8 and ft_metaknight's fn_111_C6F8 are the same -0xF4 adjustor with
// the identical callee.
//
// fn_27_13CAF8's machine-verified contract (sora_melee .text 0x13CAF8, size
// 0x12C, extracted to evidence/fn_27_13CAF8.bin after the .text offset 0xD4
// was validated byte-exact against E2B8's known-good fn_27_13A4A0 extraction,
// disassembled with powerpc-eabi-objdump 2.42): its only use of the incoming
// argument register is lwz r30,96(r3); the first write to r4 (li r4,0 at
// 0x13CB00) precedes every read, and r5-r10 are never read before being
// written, so forwarding the adjusted interface pointer alone is complete and
// harmless. Both registered fighter spellings of this slot (ft_luigi
// fn_99_BBB8, ft_metaknight fn_111_C6F8) agree on a void return, so no result
// pointer is involved.
#include <types.h>

extern "C" void fn_27_13CAF8(void* object);

extern "C" void fn_117_E2E8(void* interface) {
    fn_27_13CAF8(static_cast<u8*>(interface) - 0xF4);
}
