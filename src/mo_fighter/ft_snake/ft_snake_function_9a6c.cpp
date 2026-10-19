#pragma force_active on
extern "C" void* fn_122_9AD8(void*, short);
extern "C" void* fn_122_43D4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9A6C(void* object, short deleting) {
    if (object != 0) {
        fn_122_9AD8(static_cast<char*>(object) + 0x24, -1);
        fn_122_43D4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
