#pragma force_active on
void operator delete(void*);
extern "C" void fn_96_76E8(void* object, short deleting);
extern "C" void fn_96_7610(void* object, short deleting);

extern "C" void* fn_96_7748(void* object, short deleting) {
    if (object != 0) {
        fn_96_76E8(static_cast<unsigned char*>(object) + 0x5B54, -1);
        if (object != 0) {
            fn_96_7610(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
