// The interface pointer for this entry points 0xF4 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13C724 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2F0,0xE2F8) is the raw word pair 3863ff0c 48015c04
// = addi r3,r3,-0xF4 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2F4 (m27 import-stream entry) carries addend 0x13C724, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E20C->0x135468, E274->0x135EB4, E27C->0x13C428,
// E2D8->0x13DD00 exactly, and every section-1 REL24 word0 in the module is a
// branch to the unresolved veneer (evidence/rel_decode_e2f0.py).
//
// Slot-run context: the -0xF4 run opens at E2D8 (0x13DD00) and continues at
// E2E0 (0x13C7D0), E2E8 (0x13CAF8) and E2F0 (0x13C724), the shared damage
// notification slot: ft_luigi's fn_99_BBC0 and ft_metaknight's fn_111_C700
// are the same -0xF4 adjustor with the identical callee.
//
// fn_27_13C724's machine-verified contract (sora_melee .text 0x13C724, size
// 0xAC, extracted to evidence/fn_27_13C724.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the object (mr r30, r3) and the float
// argument (fmr f31, f1 at 0x13C738) in the prologue, then reloads the float
// into f1 for a virtual call (fmr f1, f31 at 0x13C760). r4 and r5 are only
// ever written (lwz/lis/li), never read, so forwarding the interface words is
// complete and harmless. Both registered fighter spellings of this callee
// (ft_luigi fn_27_13C724(void*, float) and ft_metaknight
// fn_27_13C724(void* object, float damage)) agree on a void two-argument
// (pointer, float) ABI, so no result pointer is involved.
#include <types.h>

extern "C" void fn_27_13C724(void* object, float damage);

extern "C" void fn_117_E2F0(void* interface, float damage) {
    fn_27_13C724(static_cast<u8*>(interface) - 0xF4, damage);
}
