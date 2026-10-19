#pragma force_active on
extern "C" void* fn_108_47F4(void*, short);
extern "C" void* fn_108_5148(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_4778(void* object, short deleting) {
    if (object != 0) {
        fn_108_47F4(static_cast<char*>(object) + 0x10000 - 0x7588, -1);
        if (object != 0) {
            fn_108_5148(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
