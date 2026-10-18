#pragma force_active on
void operator delete(void*);

extern "C" void fn_116_1E33C(void*, short);
extern "C" void* fn_116_1E2DC(void* object, short deleting) {
    if (object != 0) {
        fn_116_1E33C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
