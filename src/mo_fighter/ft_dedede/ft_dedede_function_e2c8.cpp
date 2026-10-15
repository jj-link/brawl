// The interface pointer for this entry points 0xE8 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_1362E4 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2C8,0xE2D0) is the raw word pair 3863ff18 48015c2c
// = addi r3,r3,-0xE8 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2CC (m27 import-stream entry) carries addend 0x1362E4, symbol
// section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E208->0x135468, E270->0x135EB4, E278->0x13C428
// exactly, and every section-1 REL24 word0 in the module is a branch to the
// unresolved veneer (evidence/rel_decode_e2c8.py).
//
// Slot-run context: the -0xD0 run ends at E2C0; the -0xE8 run opens at E2C8
// and continues at E2D0 (0x13604C). fn_27_1362E4 is the shared damage-event
// slot: ft_luigi's fn_99_BB98 and ft_metaknight's fn_111_C6D8 are the same
// -0xE8 adjustor with the identical callee.
//
// fn_27_1362E4's machine-verified contract (sora_melee .text 0x1362E4, size
// 0x188, extracted to evidence/fn_27_1362E4.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the object (mr r31, r3), the damage
// record (mr r29, r4) and the accesser (mr r30, r5), reads floats from the
// damage record (lfs f1,148(r29); lfs f0,0(r29)) and passes the accesser
// through (lwz r3,216(r30); lwz r3,96(r30) before further virtual calls).
// Every use of r6 is a write (mr r6,r30; li r6,0) and r7/r8 are never
// touched, so forwarding the three interface words is complete and harmless.
// Both registered fighter spellings of this slot (ft_luigi fn_99_BB98,
// ft_metaknight fn_111_C6D8) agree on a void return, so no result pointer is
// involved.
#include <types.h>

class soDamage;
class soModuleAccesser;

extern "C" void fn_27_1362E4(void* object, soDamage* damage,
                             soModuleAccesser* accesser);

extern "C" void fn_117_E2C8(void* interface, soDamage* damage,
                            soModuleAccesser* accesser) {
    fn_27_1362E4(static_cast<u8*>(interface) - 0xE8, damage, accesser);
}
