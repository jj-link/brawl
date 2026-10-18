#pragma force_active on
extern "C" void fn_94_D11C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_D17C(void* object, short deleting) {
    if (object != 0) {
        fn_94_D11C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
