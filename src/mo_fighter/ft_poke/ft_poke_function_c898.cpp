#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_C838(void* object, short deleting);
extern "C" void fn_116_C704(void* object, short deleting);

extern "C" void* fn_116_C898(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_C838(storage + 0x1C8, -1);
        if (object != 0) {
            fn_116_C704(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
