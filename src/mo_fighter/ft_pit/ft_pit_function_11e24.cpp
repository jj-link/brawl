#pragma force_active on
class soModuleAccesser;

namespace {
typedef unsigned char Byte;
}

extern "C" {
void fn_112_12738(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_112_1250C(void*, int);
void* fn_112_12424(void*, int);
void* fn_112_1233C(void*, int);
void* fn_112_12254(void*, int);
}

// Reset the selected mode, then activate each embedded entry.
extern "C" void fn_112_11E24(Byte* object, int kind, soModuleAccesser* accesser) {
    fn_112_12738(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_1250C(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_12424(object + 0xAC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_1233C(object + 0x5C, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_12254(object + 8, i));
}
