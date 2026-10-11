class soModuleAccesser;
class acAnimCmd;

extern "C" void* fn_99_85F0(void*, int);
extern "C" bool fn_99_82A8(void*, const acAnimCmd*, soModuleAccesser*, int);
extern "C" bool fn_99_8384(void*, int);

extern "C" void* fn_99_BAA8(void* object, int deleting) {
    return fn_99_85F0(static_cast<unsigned char*>(object) - 0x40, deleting);
}

extern "C" bool fn_99_BAB0(void* object, const acAnimCmd* command,
                          soModuleAccesser* accesser, int kind) {
    return fn_99_82A8(static_cast<unsigned char*>(object) - 0x48,
                      command, accesser, kind);
}

extern "C" bool fn_99_BAB8(void* object, int group) {
    return fn_99_8384(static_cast<unsigned char*>(object) - 0x48, group);
}
