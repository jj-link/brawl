#pragma force_active on
extern "C" void fn_104_C488(void* object, short deleting);
extern "C" void fn_104_C358(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C4E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_C488(storage + 0x94, -1);
        if (object != 0) {
            fn_104_C358(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
