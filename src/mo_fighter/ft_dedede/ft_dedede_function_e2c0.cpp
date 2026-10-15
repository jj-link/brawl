// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13A418 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2C0,0xE2C8) is the raw word pair 3863ff30 48015c34
// = addi r3,r3,-0xD0 ; b <_unresolved placeholder at .text 0x23EF8>. Exactly
// one relocation of any type hits the window in any import stream
// (m27/m117/m0): the REL24 at .text 0xE2C4 (import-stream m27) carries
// addend 0x13A418, symbol section 1 of the sora_melee import. The decode
// reproduces the machine-confirmed anchors E208->0x135468, E270->0x135EB4,
// E278->0x13C428, E290->0x13B998, E2A0->0x13B5AC and E2A8->0x13ACC4 exactly
// (evidence/rel_decode_e2c0.py), and every section-1 REL24 word0 in the
// module is a branch to the 0x23EF8 veneer (0 non-branch).
//
// Slot-run context: the -0xD0 run E278..E2C8 carries the callees 0x13C428,
// 0x13BDCC, 0x13BB54, 0x13B998, 0x13B96C, 0x13B5AC, 0x13ACC4, 0x13A89C,
// 0x13A4A0, 0x13A418 in descending slot order, the same handler sequence as
// ft_metaknight's fn_111_C680.. adjustor run and ft_luigi's fn_99_BB48..
// run. E2C0 is the (item, result) slot: fn_27_13A418 (sora_melee .text
// 0x13A418, size 0x88, per sora_melee symbols.txt line 12030 it ends where
// fn_27_13A4A0 begins at 0x13A4A0) saves the item (mr r30, r4) and the
// result pointer (mr r31, r5), and never reads r3 or r6 or a later argument
// register, so the three-word (interface, item, result) forwarding here is
// complete. Its result word is stored exactly twice, both as words
// (li r0,0; stw r0,0(r31) on the cleared path and li r0,1; stw r0,0(r31) on
// the virtual-call accept path), so the result parameter is spelled int*,
// like the word-spelled result slots rather than the byte-spelled bool* of
// the E2A0 slot. A plain branch does not alter r4/r5, and r3 is reloaded by
// the callee only from r30, so the -0xD0 addi is the sole register change.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13A418(void* object, BaseItem* item, int* result);

extern "C" void fn_117_E2C0(void* interface, BaseItem* item, int* result) {
    fn_27_13A418(static_cast<u8*>(interface) - 0xD0, item, result);
}
