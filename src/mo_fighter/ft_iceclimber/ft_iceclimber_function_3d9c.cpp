#pragma force_active on
extern "C" void fn_105_1EEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_3D9C(void* object, short deleting) {
    if (object != 0) {
        fn_105_1EEC(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
