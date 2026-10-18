#pragma force_active on
extern "C" void* fn_27_1A1FE4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_7028(void* object, int deleting) {
    if (object) {
        if (object) fn_27_1A1FE4(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) __dl__FPv(object);
    }
    return object;
}
