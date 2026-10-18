#pragma force_active on
extern "C" void* fn_98_35F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_4EA4(void* object, short deleting) {
    if (object) {
        fn_98_35F0(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
