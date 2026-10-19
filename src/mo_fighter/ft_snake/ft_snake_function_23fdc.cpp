#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_2404C(void*, short);
extern "C" void* fn_122_240DC(void*, short);

extern "C" void* fn_122_23FDC(void* object, short deleting) {
    if (object != 0) {
        fn_122_2404C(static_cast<unsigned char*>(object) + 0x1e00, -1);
        fn_122_240DC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
