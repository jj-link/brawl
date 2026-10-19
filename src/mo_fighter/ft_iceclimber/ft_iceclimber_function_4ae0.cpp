#pragma force_active on
extern "C" void fn_105_3430(void*, short);
extern "C" void fn_105_4B4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4AE0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_3430(storage + 0x1f5c, -1);
        fn_105_4B4C(storage + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
