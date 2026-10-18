#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_CA88(void*, short);

extern "C" void* fn_108_CAE4(void* object, short deleting) {
    if (object != 0) {
        fn_108_CA88(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
