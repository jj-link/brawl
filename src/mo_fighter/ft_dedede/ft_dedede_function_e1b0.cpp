// The secondary interface begins 0x54 bytes into the complete object; this
// vtable entry re-derives the complete object pointer and tail-calls the
// primary link-event handler, which is imported from the sora_melee module.
class soModuleAccesser;

extern "C" void fn_27_1324D4(void*, void*, soModuleAccesser*, int, int);

extern "C" void fn_117_E1B0(void* object, void* event,
                            soModuleAccesser* accesser, int kind, int index) {
    fn_27_1324D4(static_cast<unsigned char*>(object) - 0x54,
                 event, accesser, kind, index);
}
