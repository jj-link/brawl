#pragma force_active on
extern "C" void fn_27_4E038(void*, short);
extern "C" void fn_27_4CAA0(void*, short);
extern "C" void fn_27_CD4A4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_4754(void* object, short deleting) {
    if (object != 0) {
        fn_27_4E038(static_cast<unsigned char*>(object) + 0xF0, -1);
        fn_27_4CAA0(static_cast<unsigned char*>(object) + 0x6C, -1);
        fn_27_CD4A4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
