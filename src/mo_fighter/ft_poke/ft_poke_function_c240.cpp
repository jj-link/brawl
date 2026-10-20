#pragma force_active on
void operator delete(void*);
extern "C" void fn_116_C1E0(void* object, short deleting);
extern "C" void* fn_116_C0B0(void* object, short deleting);

extern "C" void* fn_116_C240(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_C1E0(storage + 0x94, -1);
        if (object != 0) {
            fn_116_C0B0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
