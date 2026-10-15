// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13A89C from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2B0,0xE2B8) is the raw word pair 3863ff30 48015c44
// = addi r3,r3,-0xD0 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2B4 (import-stream file offset 0x33528) carries addend 0x13A89C,
// symbol section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E208->0x135468, E270->0x135EB4, E278->0x13C428
// exactly (evidence/rel_decode_e2b0.py).
//
// Slot-run context: the -0xD0 run E278..E2C0 carries the callees 0x13C428,
// 0x13BDCC, 0x13BB54, 0x13B998, 0x13B96C, 0x13B5AC, 0x13ACC4, 0x13A89C,
// 0x13A4A0, 0x13A418 in descending slot order, the same handler sequence as
// ft_metaknight's fn_111_C678..fn_111_C6C8 adjustor run and ft_luigi's
// fn_99_BB48..fn_99_BB90 run. E2B0 is the six-argument slot, matching the
// registered ft_metaknight fn_111_C6B8 entry (and ft_luigi's fn_99_BB80).
//
// fn_27_13A89C's machine-verified contract (sora_melee .text 0x13A89C, size
// 0x424, extracted to evidence/fn_27_13A89C.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the item (mr r26, r4), the object
// (mr r25, r3), the fifth and seventh words (mr r22, r5; mr r23, r7) and
// the eighth word (mr r27, r8, tested by cmpwi r27, 0), and loads the
// accesser from the object's word 96 (lwz r31, 96(r3)). Its fourth argument
// register r6 is never read: every r6 use in the function is a write
// (addi r6,r1,28; lwz r6,216(r31); li r6,0), so forwarding all six interface
// words is complete and harmless. The callee returns void (both registered
// fighter spellings agree), so no result pointer is involved. The thunk
// itself only corrects r3 and passes every other incoming register through
// unchanged; the callee's own register handling does not depend on the
// caller's spelling.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13A89C(void* object, BaseItem* item, u32 nodeIndex,
                             u32 attachNodeIndex, u32 flagWord, u32 flagWord2);

extern "C" void fn_117_E2B0(void* interface, BaseItem* item, u32 nodeIndex,
                            u32 attachNodeIndex, u32 flagWord, u32 flagWord2) {
    fn_27_13A89C(static_cast<u8*>(interface) - 0xD0, item, nodeIndex,
                 attachNodeIndex, flagWord, flagWord2);
}
