// The interface pointer for this entry points 0x100 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_136528 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2F8,0xE300) is the raw word pair 3863ff00 48015bfc
// = addi r3,r3,-0x100 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2FC (m27 import-stream entry) carries addend 0x136528, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E20C->0x135468, E274->0x135EB4, E27C->0x13C428
// exactly, and all 2031 section-1 REL24 word0s in the module are branches
// (0 non-branch) to the unresolved veneer (evidence/rel_decode_e2f8.py).
//
// Slot-run context: the -0xF4 run (E2D8 0x13DD00, E2E0 0x13C7D0, E2E8
// 0x13CAF8, E2F0 0x13C724) closes at E2F0; the -0x100 run opens at E2F8.
// fn_27_136528 is the shared accesser/float-pair notification slot:
// ft_luigi's fn_99_BBC8 and ft_metaknight's fn_111_C708 are the same -0x100
// adjustor with the identical callee, so both registered spellings compile to
// the identical 2-instruction thunk (accesser in r4, second float in f2).
// Spelling follows the accepted ft_dedede convention of adopting the
// registered ft_metaknight declaration where the two differ (E2B8 precedent).
//
// fn_27_136528's machine-verified contract (sora_melee .text 0x136528, size
// 0x10C, extracted to evidence/fn_27_136528.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the accesser (mr r31, r4) and the
// second float (fmr f31, f2), then issues several virtual calls through the
// accesser (the r3 chain starts with lwz r3,216(r4)). The derived interface
// pointer (r3) is never read (its first use is that write), and f1 and
// r5-r10 are only ever written (lfs f1,0(r4), li/lis/addi), so forwarding the
// interface words is complete and harmless. The float is re-loaded from f31
// for the fcmpu against the stored value (fcmpu cr0,f31,f0) and the
// conditional negate/store tail (stfs f0,68(r3); stfs f31,56(r3)).
#include <types.h>

class soModuleAccesser;

extern "C" void fn_27_136528(void* interface, float previous, float current,
                             soModuleAccesser* accesser);

extern "C" void fn_117_E2F8(void* interface, float previous, float current,
                            soModuleAccesser* accesser) {
    fn_27_136528(static_cast<u8*>(interface) - 0x100, previous, current, accesser);
}
