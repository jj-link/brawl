#pragma force_active on
void operator delete(void*);

extern "C" void fn_95_D9B0(void*, short);

extern "C" void* fn_95_DA10(void* object, short deleting) {
    if (object != 0) {
        fn_95_D9B0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
