// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13B998 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE290,0xE298) is the raw word pair 3863ff30 48015c64
// = addi r3,r3,-0xD0 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE294 (import-stream file offset 0x33508) carries addend 0x13B998,
// symbol section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E208->0x135468, E270->0x135EB4, E278->0x13C428
// and E280->0x13BDCC exactly (evidence/rel_decode_v2_e290.py).
//
// Slot-run context: the -0xD0 run E278..E298 carries the callees 0x13C428,
// 0x13BDCC, 0x13BB54, 0x13B998, 0x13B96C in descending slot order, the same
// handler sequence as ft_metaknight's fn_111_C680..fn_111_C6A0 adjustor run
// and ft_luigi's fn_99_BB48..fn_99_BB68 run. E290 is the two-argument slot,
// matching the registered ft_metaknight fn_111_C698 entry.
//
// fn_27_13B998's observed contract (sora_melee auto asm, VA
// 0x13B998..0x13BB54): it saves the incoming r3/r4 into r29/r30, immediately
// overwrites r4 with 0, reads the object at +0x60 and dispatches on a virtual
// query result (0x2c/0xd/0x3a); every branch reaches the common tail at
// 0x13BB24, which loads the vtable from the saved second argument
// (lwz r12, 0x3c(r30)) and calls its slot at +0x254 with the second argument
// as this. The second argument is therefore an object pointer that receives a
// virtual call, which follows ft_metaknight's BaseItem* spelling
// (fn_27_13B998(void* object, BaseItem* item)) and contradicts ft_luigi's
// int-kind spelling in fn_99_BB60. The thunk itself only corrects r3 and
// passes every other incoming register through unchanged; the callee's own
// r4 handling does not depend on the caller's spelling.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13B998(void* object, BaseItem* item);

extern "C" void fn_117_E290(void* interface, BaseItem* item) {
    fn_27_13B998(static_cast<u8*>(interface) - 0xD0, item);
}
