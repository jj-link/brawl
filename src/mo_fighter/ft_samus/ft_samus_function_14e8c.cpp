#pragma force_active on
extern "C" void* fn_94_14EEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_14E8C(void* object, short deleting) {
    if (object != 0) {
        fn_94_14EEC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
