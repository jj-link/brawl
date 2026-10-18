#pragma force_active on
extern "C" void fn_27_325E98(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_33DC(void* object, short deleting) {
    if (object) {
        fn_27_325E98(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
