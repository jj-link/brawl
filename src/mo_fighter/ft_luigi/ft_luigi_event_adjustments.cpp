class soModuleAccesser;
class acAnimCmd;

extern "C" bool fn_27_133AA4(void*, const acAnimCmd*, soModuleAccesser*, int);
extern "C" void fn_27_1324D4(void*, void*, soModuleAccesser*, int, int);
extern "C" void fn_27_131CD0(void*, int, int, soModuleAccesser*);

extern "C" bool fn_99_BA90(void* object, const acAnimCmd* command,
                          soModuleAccesser* accesser, int kind) {
    return fn_27_133AA4(static_cast<unsigned char*>(object) - 0x48,
                        command, accesser, kind);
}

extern "C" void fn_99_BA98(void* object, void* event,
                          soModuleAccesser* accesser, int kind, int index) {
    fn_27_1324D4(static_cast<unsigned char*>(object) - 0x54,
                 event, accesser, kind, index);
}

extern "C" void fn_99_BAA0(void* object, int status, int previousStatus,
                          soModuleAccesser* accesser) {
    fn_27_131CD0(static_cast<unsigned char*>(object) - 0x70,
                 status, previousStatus, accesser);
}
