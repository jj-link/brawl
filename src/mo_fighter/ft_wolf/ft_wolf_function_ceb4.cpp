#pragma force_active on
void operator delete(void*);
extern "C" void fn_125_CE54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_CEB4(void* object, short deleting) {
    if (object != 0) {
        fn_125_CE54(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
