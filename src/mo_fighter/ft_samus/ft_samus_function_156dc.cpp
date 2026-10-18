#pragma force_active on
extern "C" void* fn_94_1573C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_156DC(void* object, short deleting) {
    if (object != 0) {
        fn_94_1573C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
