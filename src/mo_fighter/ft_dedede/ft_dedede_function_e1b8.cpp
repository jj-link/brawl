// The interface pointer for this entry points 0x64 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the primary event handler, which is imported from the
// sora_melee module.
class soModuleAccesser;

extern "C" void fn_27_13138C(void*, void*, soModuleAccesser*, int, int);

extern "C" void fn_117_E1B8(void* object, void* event,
                            soModuleAccesser* accesser, int kind, int index) {
    fn_27_13138C(static_cast<unsigned char*>(object) - 0x64, event, accesser,
                 kind, index);
}
