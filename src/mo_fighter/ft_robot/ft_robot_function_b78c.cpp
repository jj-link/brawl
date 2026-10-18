#pragma force_active on
void operator delete(void*);
extern "C" void fn_120_B72C(void*, short);

extern "C" void* fn_120_B78C(void* object, short deleting) {
    if (object != 0) {
        fn_120_B72C(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
