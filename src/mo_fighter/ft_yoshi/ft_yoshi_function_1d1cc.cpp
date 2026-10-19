#pragma force_active on
extern "C" void* fn_95_1D23C(void*, short);
extern "C" void* fn_95_1D358(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_1D1CC(void* object, short deleting) {
    if (object != 0) {
        fn_95_1D23C(static_cast<unsigned char*>(object) + 0x18AC, -1);
        fn_95_1D358(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
