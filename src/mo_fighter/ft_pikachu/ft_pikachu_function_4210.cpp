#pragma force_active on
extern "C" void* fn_27_1A2B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_4210(void* object, short deleting) {
    if (object) {
        fn_27_1A2B08(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
