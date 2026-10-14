// The interface pointer for this entry points 0x48 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the shared animation-command handler, which is imported from the
// sora_melee module.
class soModuleAccesser;
class acAnimCmd;

extern "C" bool fn_27_133AA4(void*, const acAnimCmd*, soModuleAccesser*, int);

extern "C" bool fn_117_E1E0(void* object, const acAnimCmd* command,
                            soModuleAccesser* accesser, int kind) {
    return fn_27_133AA4(static_cast<unsigned char*>(object) - 0x48,
                        command, accesser, kind);
}
