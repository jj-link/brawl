#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_115_C74C(void* object, short deleting);
extern "C" void* fn_115_C618(void* object, short deleting);

extern "C" void* fn_115_C7AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_C74C(storage + 0x204, -1);
        if (object != 0) {
            fn_115_C618(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
