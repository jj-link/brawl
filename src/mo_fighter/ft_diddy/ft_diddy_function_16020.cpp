#pragma force_active on
void operator delete(void*);

extern "C" void fn_115_3A2C(void*, short);

extern "C" void* fn_115_16020(void* object, short deleting) {
    if (object != 0) {
        fn_115_3A2C(static_cast<unsigned char*>(object) + 0x38, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
