#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_C9CC(void* object, short deleting);
extern "C" void fn_116_C898(void* object, short deleting);

extern "C" void* fn_116_CA2C(void* object, short deleting) {
    if (object != 0) {
        fn_116_C9CC(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_116_C898(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
