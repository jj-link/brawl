#pragma force_active on
extern "C" void* fn_93_2CE0(void*, short);
extern "C" void* fn_93_2DA0(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_2DFC(void* object, short deleting) {
    if (object != 0) {
        fn_93_2CE0(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_93_2DA0(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
