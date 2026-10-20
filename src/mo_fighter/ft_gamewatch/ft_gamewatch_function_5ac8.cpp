#pragma force_active on
extern "C" void* fn_107_5B40(void* object, short deleting);
extern "C" void* fn_107_5DF4(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_5AC8(void* object, short deleting) {
    if (object != 0) {
        fn_107_5B40(static_cast<char*>(object) + 0x4A18, -1);
        if (object != 0) {
            fn_107_5DF4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
