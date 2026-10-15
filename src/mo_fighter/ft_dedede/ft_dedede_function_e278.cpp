// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13C428 from the sora_melee module, which
// forwards the item, argument and flag words unchanged.
//
// fn_27_13C428's machine-verified contract is
// (void*, BaseItem*, int, u32, u32) -> void: its body compares the fourth
// argument (cmpwi r6, 1), moves the fifth into its place (mr r6, r7) and
// tail-branches to fn_27_13C43C, which compares the forwarded fifth word
// (cmpwi r31, 1) without ever dereferencing it; no read of r8 or later
// argument registers occurs anywhere in the chain. The word spellings
// therefore follow ft_metaknight's fn_111_C680 rather than ft_luigi's
// void* context in fn_99_BB48. Dedede's -0xD0 slot run [E2C0..E278] maps
// onto the same handler sequence as Luigi's fn_99_BB48 run and Metaknight's
// fn_111_C680 run, and E278 is the fn_27_13C428 slot in all three fighters.
#include <types.h>

class BaseItem;

extern "C" void fn_27_13C428(void* object, BaseItem* item, int argument,
                             u32 enabledWord, u32 visibilityWord);

extern "C" void fn_117_E278(void* interface, BaseItem* item, int argument,
                            u32 enabledWord, u32 visibilityWord) {
    fn_27_13C428(static_cast<u8*>(interface) - 0xD0, item, argument,
                 enabledWord, visibilityWord);
}
