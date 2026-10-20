#pragma force_active on
extern "C" void* fn_93_D4BC(void* object, short deleting);
extern "C" void* fn_93_D388(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_93_D51C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_93_D4BC(storage + 0x134, -1);
        if (object != 0) {
            fn_93_D388(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
