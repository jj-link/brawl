// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13B5AC from the sora_melee module, passing
// the item, index and result pointer unchanged.
//
// fn_27_13B5AC's machine-verified contract (sora_melee .text 0x13B5AC, size
// 0x3C0): it saves the item (mr r28, r4), the index (mr r29, r5) and the
// result pointer (mr r24, r6), and loads the accesser from the object's word
// 96 (lwz r31, 96(r3)). It never reads r7 or a later argument register, so
// forwarding the four interface words is complete. Its result word is stored
// exactly once, as a byte (li r0, 1; stb r0, 0(r24) on the early-accept
// path), so the result parameter is spelled bool*, matching ft_luigi's
// byte-accurate fn_99_BB70 spelling of this shared slot rather than the
// word-spelled int* of ft_metaknight's fn_111_C6A8; both spellings compile
// to the identical thunk. Dedede's -0xD0 slot run maps 1:1 onto the same
// handler sequence as Luigi's fn_99_BB* run and Metaknight's fn_111_C6* run:
// E2A0 is the fn_27_13B5AC slot in all three fighters.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13B5AC(void* object, BaseItem* item, u32 index,
                             bool* result);

extern "C" void fn_117_E2A0(void* interface, BaseItem* item, u32 index,
                            bool* result) {
    fn_27_13B5AC(static_cast<u8*>(interface) - 0xD0, item, index, result);
}
