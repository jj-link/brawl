#pragma force_active on
extern "C" void* fn_122_1F14(void*, short);
extern "C" void* fn_122_4040(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_3FD4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_1F14(storage + 0x20, 0);
        fn_122_4040(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
