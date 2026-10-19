#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_2308(void*, short);
extern "C" void fn_116_2164(void*, short);

extern "C" void* fn_116_229C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_2308(storage + 0x50, -1);
        fn_116_2164(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
