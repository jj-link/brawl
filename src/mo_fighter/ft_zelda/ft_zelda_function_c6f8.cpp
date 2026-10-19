#pragma force_active on
extern "C" {
void* fn_104_C560(void* object, short deleting);
void __dl__FPv(void* p);
}

extern "C" void* fn_104_C6F8(void* object, short deleting) {
    if (object != 0) {
        fn_104_C560(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
