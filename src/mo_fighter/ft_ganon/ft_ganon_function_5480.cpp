#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_109_54F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_5480(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x138, -1);
        if (object != 0) {
            fn_109_54F8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
