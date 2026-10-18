#pragma force_active on
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_146B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A241C(storage + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
