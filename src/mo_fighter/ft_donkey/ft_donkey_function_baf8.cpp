#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_92_C7C0(void*, int);
void* fn_92_C6D8(void*, int);
void* fn_92_C5F0(void*, int);
void* fn_92_C508(void*, int);
void* fn_92_C420(void*, int);
void* fn_92_C338(void*, int);
void* fn_92_C250(void*, int);
void* fn_92_C168(void*, int);
}

// Initialize the fighter-specific state and activate each embedded event entry.
extern "C" void fn_92_BAF8(unsigned char* object, int fighterKind, soModuleAccesser* moduleAccessor) {
    fn_27_15FA20(fighterKind, object + 4, moduleAccessor);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C7C0(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C6D8(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C5F0(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C508(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C420(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C338(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C250(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_92_C168(object + 8, i));
}
