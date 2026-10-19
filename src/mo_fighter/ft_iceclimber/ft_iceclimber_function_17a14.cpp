#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_3750(void*, short);
extern "C" void* fn_105_17A84(void*, short);

extern "C" void* fn_105_17A14(void* object, short deleting) {
    if (object != 0) {
        fn_105_3750(static_cast<unsigned char*>(object) + 0x1818, -1);
        fn_105_17A84(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
