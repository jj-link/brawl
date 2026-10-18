#pragma force_active on
extern "C" void* fn_126_7C80(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_7CDC(void* object, short deleting) {
    if (object != 0) {
        fn_126_7C80(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
