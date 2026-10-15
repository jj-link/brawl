// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13BDCC from the sora_melee module, the
// item-attachment flag adjustment also reached by the registered ft_luigi
// (fn_99_BB50) and ft_metaknight (fn_111_C688) interface adjustors through
// the same -0xD0 correction. fn_27_13BDCC's verified interface is
// (void* object, BaseItem* item, u32 index, u32 flagWord) -> void: the
// destination reads the item pointer and the two flag words. The two
// registered callers agree on the forwarded register words, not on their
// semantic C++ spellings: ft_metaknight declares the last two parameters
// u32 index, u32 flagWord, while ft_luigi declares int kind, void* context.
// This entry follows the ft_metaknight u32 spellings; either spelling
// forwards the same words for this thunk.
class BaseItem;

extern "C" void fn_27_13BDCC(void* object, BaseItem* item, unsigned int index,
                             unsigned int flagWord);

extern "C" void fn_117_E280(void* object, BaseItem* item, unsigned int index,
                            unsigned int flagWord) {
    fn_27_13BDCC(static_cast<unsigned char*>(object) - 0xD0, item, index, flagWord);
}
