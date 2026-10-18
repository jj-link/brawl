#pragma force_active on
extern "C" void* fn_98_B6E0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_B740(void* object, short deleting) {
    if (object) {
        fn_98_B6E0(static_cast<char*>(object) + 4, short(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
