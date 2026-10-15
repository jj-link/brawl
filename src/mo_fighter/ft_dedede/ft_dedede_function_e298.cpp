// The interface pointer for this entry points 0xD0 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_13B96C from the sora_melee module, the
// dispatch also reached by the registered ft_luigi (fn_99_BB68) and
// ft_metaknight (fn_111_C6A0) interface adjustors through the same -0xD0
// correction. fn_27_13B96C's verified interface, from the disassembly of its
// preserved 0x2C bytes (evidence/input/fn_27_13B96C.bin), is
// (void* object) -> void: it reads only the object pointer, stepping
// *(r3+0x60) -> *(r3+0xD8) -> *(r3+0x50) and tail-calling vtable slot 7 with
// (r3, 8110, 0, 0, 0). The incoming r4 is not read, so this entry follows the
// ft_luigi single-argument spelling; every other incoming register is passed
// through unchanged by the thunk in either spelling.

extern "C" void fn_27_13B96C(void* object);

extern "C" void fn_117_E298(void* object) {
    fn_27_13B96C(static_cast<unsigned char*>(object) - 0xD0);
}
