#pragma force_active on
void operator delete(void*);
extern "C" void fn_113_AC8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_2BC8(void* object, short deleting) {
    if (object != 0) {
        fn_113_AC8(static_cast<unsigned char*>(object) + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
