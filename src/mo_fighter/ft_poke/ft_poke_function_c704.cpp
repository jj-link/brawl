#pragma force_active on
void operator delete(void*);
extern "C" void fn_116_C6A4(void* object, short deleting);
extern "C" void fn_116_C56C(void* object, short deleting);

extern "C" void* fn_116_C704(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_C6A4(storage + 0x17C, -1);
        if (object != 0) {
            fn_116_C56C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
