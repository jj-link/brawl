#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_91_DA08(unsigned char* self, int index);
void* fn_91_D920(unsigned char* self, int index);
void* fn_91_D838(unsigned char* self, int index);
void* fn_91_D750(unsigned char* self, int index);
void* fn_91_D668(unsigned char* self, int index);
void* fn_91_D580(unsigned char* self, int index);
void* fn_91_D498(unsigned char* self, int index);
void* fn_91_D3B0(unsigned char* self, int index);
}

// Reset the fighter state, then activate each embedded entry.
extern "C" void fn_91_CD40(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_27_15FA20(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_DA08(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D920(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D838(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D750(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D668(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D580(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D498(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_91_D3B0(object + 8, i));
}
