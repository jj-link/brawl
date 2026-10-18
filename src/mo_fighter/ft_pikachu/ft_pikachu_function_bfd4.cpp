#pragma force_active on
extern "C" {
void* fn_98_BF74(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_BFD4(void* object, short deleting) {
    if (object) {
        fn_98_BF74(static_cast<char*>(object) + 8, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
