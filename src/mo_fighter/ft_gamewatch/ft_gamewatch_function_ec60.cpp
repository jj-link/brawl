#pragma force_active on
extern "C" void fn_107_EC00(void* object, short deleting);
extern "C" void fn_107_EACC(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_EC60(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_EC00(storage + 0x1C8, -1);
        if (object != 0) {
            fn_107_EACC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
