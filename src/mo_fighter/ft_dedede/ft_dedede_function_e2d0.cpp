// The interface pointer for this entry points 0xE8 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13604C from the sora_melee module, passing
// the damage record, flag word and module accesser unchanged.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2D0,0xE2D8) is the raw word pair 3863ff18 48015c24
// = addi r3,r3,-0xE8 ; b <_unresolved placeholder at .text 0x23EF8>. Exactly
// one relocation of any type hits the window in any import stream
// (m27/m117/m0): the REL24 at .text 0xE2D4 (import-stream m27) carries
// addend 0x13604C, symbol section 1 of the sora_melee import. The decode
// reproduces the machine-confirmed anchors E20C->0x135468, E274->0x135EB4,
// E27C->0x13C428 and E2A4->0x13B5AC exactly (evidence/rel_decode_e2d0.py),
// and every section-1 REL24 word0 in the module is a branch to the 0x23EF8
// veneer (0 non-branch).
//
// fn_27_13604C's machine-verified contract (sora_melee .text 0x13604C, size
// 0x298, per sora_melee symbols.txt line 12010 it ends where fn_27_1362E4
// begins at 0x1362E4; extracted to evidence/fn_27_13604C.bin and
// disassembled with powerpc-eabi-objdump 2.42): it saves the damage record
// (mr r30, r4; reads its floats at 0(r30), 4(r30) and 12(r30)), the flag
// word (mr r27, r5; cmplwi r27,1) and the module accesser (mr r31, r6; lwz
// from 216(r31)), and never reads r7 or a later argument register, so
// forwarding the four interface words is complete. It returns void and
// stores no result on the caller's behalf, so no result parameter is
// spelled. This is the same handler slot as ft_luigi's fn_99_BBA0 and
// ft_metaknight's fn_111_C6E0: Dedede's -0xE8 run E2C8..E2D0 maps 1:1 onto
// the same handler sequence (E2C8 -> fn_27_1362E4, E2D0 -> fn_27_13604C),
// and E2D8 starts the -0xF4 run (-> fn_27_13DD00), matching Luigi's
// fn_99_BB98/fn_99_BBA0/fn_99_BBA8 and Metaknight's
// fn_111_C6D8/fn_111_C6E0/fn_111_C6E8.
#include <types.h>

class soDamage;
class soModuleAccesser;

extern "C" void fn_27_13604C(void* object, soDamage* damage, u32 flagWord,
                             soModuleAccesser* accesser);

extern "C" void fn_117_E2D0(void* interface, soDamage* damage, u32 flagWord,
                            soModuleAccesser* accesser) {
    fn_27_13604C(static_cast<u8*>(interface) - 0xE8, damage, flagWord, accesser);
}
