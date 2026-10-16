// The interface pointer for this entry points 0xF4 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13C7D0 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2E0,0xE2E8) is the raw word pair 3863ff0c 48015c14
// = addi r3,r3,-0xF4 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2E4 (m27 import-stream entry) carries addend 0x13C7D0, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E20C->0x135468, E274->0x135EB4, E27C->0x13C428
// exactly, and all 2031 section-1 REL24 word0s in the module are branches
// (0 non-branch) to the unresolved veneer (evidence/rel_decode_e2e0.py).
//
// Slot-run context: the -0xE8 run closes at E2D0; the -0xF4 run opens at E2D8
// (0x13DD00) and continues at E2E0 (0x13C7D0), E2E8 (0x13CAF8), E2F0
// (0x13C724) and E2F8 (0x136528). fn_27_13C7D0 is the shared single-object
// notification slot: ft_luigi's fn_99_BBB0 and ft_metaknight's fn_111_C6F0
// are the same -0xF4 adjustor with the identical callee, spelled void
// fn_27_13C7D0(void*) in both accepted sources.
#include <types.h>

extern "C" void fn_27_13C7D0(void* object);

extern "C" void fn_117_E2E0(void* interface) {
    fn_27_13C7D0(static_cast<u8*>(interface) - 0xF4);
}
