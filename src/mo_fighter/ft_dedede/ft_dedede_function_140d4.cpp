#pragma force_active on
extern "C" void* fn_27_6880C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_140D4(void* object, short deleting) {
    if (object != 0) {
        fn_27_6880C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
