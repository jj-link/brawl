#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_23A8(void*, short);
extern "C" void* fn_92_2204(void*, short);

extern "C" void* fn_92_233C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_92_23A8(storage + 0x50, -1);
        fn_92_2204(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
