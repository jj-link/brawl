#pragma force_active on
void operator delete(void*);

extern "C" void fn_110_355C(void*, short);

extern "C" void* fn_110_34FC(void* object, short deleting) {
    if (object != 0) {
        fn_110_355C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
