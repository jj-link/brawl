#pragma force_active on
extern "C" void fn_107_4CC0(void*, short);
extern "C" void fn_107_5254(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_4C44(void* object, short deleting) {
    if (object != 0) {
        fn_107_4CC0(static_cast<unsigned char*>(object) + 0xACF8, -1);
        if (object != 0) {
            fn_107_5254(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
