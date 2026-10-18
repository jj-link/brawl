#pragma force_active on
extern "C" {
void* fn_27_6880C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_98_46B0(void* object, short deleting) {
    if (object) {
        fn_27_6880C(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
