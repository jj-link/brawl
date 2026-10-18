#pragma force_active on
void operator delete(void*);
extern "C" void* fn_118_B9D0(void*, short);

extern "C" void* fn_118_BA30(void* object, short deleting) {
    if (object != 0) {
        fn_118_B9D0(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
