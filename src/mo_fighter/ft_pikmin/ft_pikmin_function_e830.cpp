#pragma force_active on
void operator delete(void*);

extern "C" void fn_113_E7D4(void*, short);

extern "C" void* fn_113_E830(void* object, short deleting) {
    if (object != 0) {
        fn_113_E7D4(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
