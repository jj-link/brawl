#pragma force_active on
extern "C" void* fn_94_141A0(void* object, short deleting);
extern "C" void fn_94_14DA4(void* object, short kind);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_14124(void* object, short deleting) {
    if (object != 0) {
        fn_94_141A0(static_cast<char*>(object) + 0xFC30, -1);
        if (object != 0) {
            fn_94_14DA4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
