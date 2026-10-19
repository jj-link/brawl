#pragma force_active on
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void* fn_92_19C8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_9558(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x12588, -1);
        fn_92_19C8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
