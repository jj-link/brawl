// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13A4A0 from the sora_melee module.
//
// Target evidence (original ft_dedede.rel, SHA1 a6978416df878081c94afc45b487
// 030cdbbe5371): .text[0xE2B8,0xE2C0) is the raw word pair 3863ff30 48015c3c
// = addi r3,r3,-0xD0 ; b <_unresolved placeholder>. Exactly one relocation of
// any type hits the window in any import stream (m27/m117/m0): the REL24 at
// .text 0xE2BC (import-stream file offset 0x33530) carries addend 0x13A4A0,
// symbol section 1 of the sora_melee import. The decode reproduces the
// machine-confirmed anchors E208->0x135468, E270->0x135EB4 and E278->0x13C428
// exactly (evidence/rel_decode_e2b8.py).
//
// Slot-run context: the -0xD0 run E278..E2C0 carries the callees 0x13C428,
// 0x13BDCC, 0x13BB54, 0x13B998, 0x13B96C, 0x13B5AC, 0x13ACC4, 0x13A89C,
// 0x13A4A0, 0x13A418 in descending slot order, the same handler sequence as
// ft_metaknight's fn_111_C678..fn_111_C6C8 adjustor run and ft_luigi's
// fn_99_BB48..fn_99_BB90 run. E2B8 is the notifyHaveItem slot (the
// BrawlHeaders vtable declares notifyHaveItem(itParam::SizeKind, BaseItem*,
// u32 nodeIndex, u32 index, bool)), matching the registered ft_metaknight
// fn_111_C6C0 entry (and ft_luigi's fn_99_BB88); the itParam::SizeKind and
// complete-word spellings follow the registered ft_metaknight declaration of
// fn_27_13A4A0 where ft_luigi's looser spelling differs.
//
// fn_27_13A4A0's machine-verified contract (sora_melee .text 0x13A4A0, size
// 0x3FC, extracted to evidence/fn_27_13A4A0.bin, disassembled with
// powerpc-eabi-objdump 2.42): it saves the item (mr r29, r5), the object
// (mr r28, r3), the node-index word (mr r25, r6), the index word
// (mr r26, r7) and the flag word (mr r31, r8, tested by cmpwi r31, 0 and
// rlwinm. word tests), and loads the accesser from the object's word 96
// (lwz r30, 96(r3)). Its size argument register r4 is never read: the only
// r4 read, lwz r4, 12(r4) at 0x13A728, is dominated by the local write
// lwz r4, 216(r30) at 0x13A720, and every other r4 use is a write (the
// first being li r4, 0x5BCE at 0x13A4E8). No read of r9 or r10 occurs
// anywhere (both are written as call arguments only), so forwarding the
// interface words is complete and harmless. The callee passes
// (object, item, index, 1) into fn_27_13C43C and returns void (both
// registered fighter spellings agree). The thunk itself only corrects r3
// and passes every other incoming register through unchanged; the callee's
// own register handling does not depend on the caller's spelling.
#include <types.h>
#include <it/it_archive.h>

class BaseItem;

extern "C" void fn_27_13A4A0(void* object, itParam::SizeKind size, BaseItem* item,
                             u32 nodeIndex, u32 index, u32 flagWord);

extern "C" void fn_117_E2B8(void* interface, itParam::SizeKind size, BaseItem* item,
                            u32 nodeIndex, u32 index, u32 flagWord) {
    fn_27_13A4A0(static_cast<u8*>(interface) - 0xD0, size, item, nodeIndex, index,
                 flagWord);
}
