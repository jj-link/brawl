// The interface pointer for this entry points 0x7C bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the shared adjustor handler, which is imported from the
// sora_melee module. This entry's offset-to-top is the raw word 0xFFFFFF84
// (-0x7C) at section-5 offset 0x2B8, matching the adjustment; the adjacent
// E200 thunk is its own entry one slot earlier, whose offset-to-top is
// -0x70, matching E200's own adjustment. Accepted callers of fn_27_135160
// disagree on the C++ parameter order: ft_luigi's fn_99_BAE0 declares
// (void*, void*, soModuleAccesser*, float) while ft_metaknight's
// fn_111_C618 declares (void*, float, soCollisionLog*, soModuleAccesser*);
// both place a pointer in r4, a pointer in r5 and the float in f1, so either
// declaration produces the same pass-through thunk object. This unit follows
// the ft_luigi shape because the dedede callee run E208 -> fn_27_135468,
// E210 -> fn_27_135160, E218 -> fn_27_135EE8 matches luigi's BAD8/BAE0/BAE8
// run with the same -0x7C adjustment; the semantic identity of the r4/r5
// pointees is not resolvable from this object alone.
class soModuleAccesser;

extern "C" void fn_27_135160(void*, void*, soModuleAccesser*, float);

extern "C" void fn_117_E210(void* object, void* info,
                            soModuleAccesser* accesser, float value) {
    fn_27_135160(static_cast<unsigned char*>(object) - 0x7C, info, accesser,
                 value);
}
