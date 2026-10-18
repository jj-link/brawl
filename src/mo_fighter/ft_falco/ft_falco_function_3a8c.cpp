#pragma force_active on
void operator delete(void*);

extern "C" void fn_108_3AEC(void*, short);

extern "C" void* fn_108_3A8C(void* object, short deleting) {
    if (object != 0) {
        fn_108_3AEC(static_cast<unsigned char*>(object) + 0x38, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
