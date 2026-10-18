#pragma force_active on
void operator delete(void*);
extern "C" void fn_96_7418(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_7478(void* object, short deleting) {
    if (object != 0) {
        fn_96_7418(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
