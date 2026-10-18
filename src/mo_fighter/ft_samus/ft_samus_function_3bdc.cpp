#pragma force_active on
void operator delete(void*);

extern "C" void fn_27_2F3818(void*, short);

extern "C" void* fn_94_3BDC(void* object, short deleting) {
    if (object != 0) {
        fn_27_2F3818(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
