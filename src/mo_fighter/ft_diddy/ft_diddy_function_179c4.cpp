#pragma force_active on
extern "C" void fn_115_17658(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_179C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_115_17658(members + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
