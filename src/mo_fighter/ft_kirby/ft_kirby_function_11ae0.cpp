#pragma force_active on
extern "C" void* fn_96_11A80(void*, short);
extern "C" void* fn_96_11960(void*, short);
void operator delete(void*);

extern "C" void* fn_96_11AE0(void* object, short deleting) {
    if (object != 0) {
        fn_96_11A80(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_96_11960(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
