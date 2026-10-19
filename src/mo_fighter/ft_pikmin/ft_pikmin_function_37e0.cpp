#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2068(void*, short);
extern "C" void* fn_113_384C(void*, short);

extern "C" void* fn_113_37E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2068(storage + 0x3354, -1);
        fn_113_384C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
