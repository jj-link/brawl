#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_1F20(void*, short);
extern "C" void* fn_116_3C44(void*, short);

extern "C" void* fn_116_55E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_1F20(storage + 0x20, 0);
        fn_116_3C44(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
