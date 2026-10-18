#pragma force_active on
extern "C" void fn_105_10124(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_10180(void* object, short deleting) {
    if (object) {
        fn_105_10124(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
