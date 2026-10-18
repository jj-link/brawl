#pragma force_active on
extern "C" void* fn_122_426C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_420C(void* object, short deleting) {
    if (object != 0) {
        fn_122_426C(static_cast<unsigned char*>(object) + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
