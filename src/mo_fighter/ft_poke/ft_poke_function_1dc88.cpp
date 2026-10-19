#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1DCF4(void*, short);
extern "C" void fn_116_1E0EC(void*, short);

extern "C" void* fn_116_1DC88(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_1DCF4(storage + 0x2D68, -1);
        fn_116_1E0EC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
