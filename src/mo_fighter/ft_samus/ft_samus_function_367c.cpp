#pragma force_active on
extern "C" void fn_27_2E92A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_367C(void* object, short deleting) {
    if (object != 0) {
        fn_27_2E92A0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
