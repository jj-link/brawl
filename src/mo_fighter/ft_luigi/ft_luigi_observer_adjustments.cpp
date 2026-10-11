class soModuleAccesser;

extern "C" void fn_99_7FF0(void*, int, int, soModuleAccesser*);
extern "C" void fn_27_135468(void*, soModuleAccesser*);
extern "C" void fn_27_135160(void*, void*, soModuleAccesser*, float);
extern "C" void fn_27_135EE8(void*, int, soModuleAccesser*);
extern "C" void fn_27_135A70(void*);
extern "C" void fn_27_135848(void*, int, int, int, soModuleAccesser*, float, float, float);
extern "C" void fn_27_135A54(void*, int, int, int, soModuleAccesser*, float, float, float);
extern "C" bool fn_27_135DE8(void*);
extern "C" void fn_27_135D90(void*, int, int, int);
extern "C" void fn_27_135CE8(void*, int, int, int, float);
extern "C" bool fn_27_135EAC(void*);
extern "C" void fn_27_135EA8(void*);
extern "C" bool fn_27_135EE0(void*);
extern "C" void fn_27_135EDC(void*);
extern "C" void fn_27_135EB4(void*, soModuleAccesser*, int, int, int);

extern "C" void fn_99_BAD0(void* object, int status, int previousStatus,
                          soModuleAccesser* accesser) {
    fn_99_7FF0(static_cast<unsigned char*>(object) - 0x70,
               status, previousStatus, accesser);
}

extern "C" void fn_99_BAD8(void* object, soModuleAccesser* accesser) {
    fn_27_135468(static_cast<unsigned char*>(object) - 0x7c, accesser);
}

extern "C" void fn_99_BAE0(void* object, void* info,
                          soModuleAccesser* accesser, float value) {
    fn_27_135160(static_cast<unsigned char*>(object) - 0x7c, info, accesser, value);
}

extern "C" void fn_99_BAE8(void* object, int situation, soModuleAccesser* accesser) {
    fn_27_135EE8(static_cast<unsigned char*>(object) - 0x88, situation, accesser);
}

extern "C" void fn_99_BAF0(void* object) {
    fn_27_135A70(static_cast<unsigned char*>(object) - 0x94);
}

extern "C" void fn_99_BAF8(void* object, int kind, int index, int flags,
                          soModuleAccesser* accesser, float x, float y, float z) {
    fn_27_135A54(static_cast<unsigned char*>(object) - 0x94,
                 kind, index, flags, accesser, x, y, z);
}

extern "C" void fn_99_BB00(void* object, int kind, int index, int flags,
                          soModuleAccesser* accesser, float x, float y, float z) {
    fn_27_135848(static_cast<unsigned char*>(object) - 0x94,
                 kind, index, flags, accesser, x, y, z);
}

extern "C" bool fn_99_BB08(void* object) {
    return fn_27_135DE8(static_cast<unsigned char*>(object) - 0xa0);
}

extern "C" void fn_99_BB10(void* object, int first, int second, int kind) {
    fn_27_135D90(static_cast<unsigned char*>(object) - 0xa0, first, second, kind);
}

extern "C" void fn_99_BB18(void* object, int first, int second, int kind, float value) {
    fn_27_135CE8(static_cast<unsigned char*>(object) - 0xa0, first, second, kind, value);
}

extern "C" bool fn_99_BB20(void* object) {
    return fn_27_135EAC(static_cast<unsigned char*>(object) - 0xac);
}

extern "C" void fn_99_BB28(void* object) {
    fn_27_135EA8(static_cast<unsigned char*>(object) - 0xac);
}

extern "C" bool fn_99_BB30(void* object) {
    return fn_27_135EE0(static_cast<unsigned char*>(object) - 0xb8);
}

extern "C" void fn_99_BB38(void* object) {
    fn_27_135EDC(static_cast<unsigned char*>(object) - 0xb8);
}

extern "C" void fn_99_BB40(void* object, soModuleAccesser* accesser,
                          int first, int second, int third) {
    fn_27_135EB4(static_cast<unsigned char*>(object) - 0xc4,
                 accesser, first, second, third);
}
