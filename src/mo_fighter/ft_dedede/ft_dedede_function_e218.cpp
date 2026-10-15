// The interface pointer for this entry points 0x88 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the shared fighter situation handler in sora_melee, forwarding
// the integer and accesser arguments unchanged.
// fn_27_135EE8's verified interface is (void* object, int, soModuleAccesser*)
// -> void; the registered ft_luigi thunk fn_99_BAE8 and the registered
// ft_metaknight adjustors call it through the same cross-module declaration,
// so the declaration below repeats those parameter types exactly and the
// forwarded arguments need no conversion.
class soModuleAccesser;

extern "C" void fn_27_135EE8(void*, int, soModuleAccesser*);

extern "C" void fn_117_E218(void* object, int situation,
        soModuleAccesser* accesser) {
    fn_27_135EE8(static_cast<unsigned char*>(object) - 0x88, situation,
                 accesser);
}
