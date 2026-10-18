#pragma force_active on
extern "C" void* fn_119_385C(void*, short);
extern "C" void* fn_119_38E0(void*, short);
extern "C" void* fn_119_3940(void*, short);
extern "C" void* fn_119_399C(void*, short);
extern "C" void* fn_119_4454(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_37C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* s = static_cast<unsigned char*>(object);
        fn_119_385C(s + 0xE18, -1);
        fn_119_38E0(s + 0xE04, -1);
        fn_119_3940(s + 0x95C, -1);
        fn_119_399C(s + 0xE8, -1);
        fn_119_4454(s + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
