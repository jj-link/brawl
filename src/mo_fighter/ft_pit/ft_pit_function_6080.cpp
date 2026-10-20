#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void fn_112_60F8(void*, short);

extern "C" void* fn_112_6080(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A1FE4(storage + 0x244, -1);
        if (object != 0) {
            fn_112_60F8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
