// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13ACC4 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2A8,0xE2B0) is the raw word pair 3863ff30 48015c4c
// = addi r3,r3,-0xD0 ; b <_unresolved placeholder at .text 0x23EF8>. Exactly
// one relocation of any type hits the window in any import stream
// (m27/m117/m0): the REL24 at .text 0xE2AC (import-stream file offset
// 0x33520) carries addend 0x13ACC4, symbol section 1 of the sora_melee
// import. The decode reproduces the machine-confirmed anchors
// E208->0x135468, E270->0x135EB4, E278->0x13C428, E280->0x13BDCC and
// E290->0x13B998 exactly (evidence/rel_decode_v2_e2a8.py).
//
// Slot-run context: the -0xD0 run E278..E2B0 carries the callees 0x13C428,
// 0x13BDCC, 0x13BB54, 0x13B998, 0x13B96C, 0x13B5AC, 0x13ACC4, 0x13A89C in
// descending slot order, the same handler sequence as ft_metaknight's
// fn_111_C680..fn_111_C6B0 adjustor run and ft_luigi's fn_99_BB48..fn_99_BB78
// run. E2A8 is the (item, nodeIndex, result) slot, matching the registered
// ft_metaknight fn_111_C6B0 entry. A plain branch does not alter r3, so the
// callee's return value reaches this entry's caller unchanged under either
// the void spelling used here or ft_luigi's bool spelling of the same slot.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13ACC4(void* object, BaseItem* item, u32 nodeIndex, int* result);

extern "C" void fn_117_E2A8(void* interface, BaseItem* item, u32 nodeIndex, int* result) {
    fn_27_13ACC4(static_cast<u8*>(interface) - 0xD0, item, nodeIndex, result);
}
