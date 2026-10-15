// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13BB54 from the sora_melee module, passing
// the item, index and flag words unchanged.
//
// fn_27_13BB54's machine-verified contract (sora_melee .text 0x13BB54, size
// 0x278): it saves the object (mr r29, r3; later lwz r30, 96(r3)) and the
// item (mr r31, r4), zeroes its own fourth word (li r6, 0) and calls
// fn_27_13C43C with (object, item, index, 0, fifth-word). fn_27_13C43C
// (0x13C43C, size 0xF4) saves its third and fourth words (mr r30, r5;
// mr r31, r6) and compares the fourth against 1 (cmplwi r31, 1) -- dead in
// this chain because that word is the zeroed one -- and never reads its
// fifth word, so no read of r8 or later argument registers occurs anywhere
// in the chain. The forwarded flag word is therefore not consumed; the
// word spellings still follow ft_metaknight's fn_111_C690 to keep the
// cross-module declaration in agreement with the registered declaration of
// fn_27_13BB54, and the pass-through object is identical to ft_luigi's
// three-word fn_99_BB58 spelling. Dedede's -0xD0 slot run maps 1:1 onto the
// same handler sequence as Luigi's fn_99_BB* run and Metaknight's
// fn_111_C6* run: E278 is the fn_27_13C428 slot and E288 the fn_27_13BB54
// slot in all three fighters (vtable slots 0x378/0x860 vs 0x370/0x858 of
// the same -0xD0 interface groups).
#include <types.h>

class BaseItem;

extern "C" void fn_27_13BB54(void* object, BaseItem* item, u32 index,
                             u32 flagWord);

extern "C" void fn_117_E288(void* interface, BaseItem* item, u32 index,
                            u32 flagWord) {
    fn_27_13BB54(static_cast<u8*>(interface) - 0xD0, item, index, flagWord);
}
