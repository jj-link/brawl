#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_2208(void*, short);
extern "C" void* fn_102_212C(void*, short);

extern "C" void* fn_102_1A128(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_2208(storage + 0x50, -1);
        fn_102_212C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
