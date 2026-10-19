#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_240C(void* object, short shouldDelete);
extern "C" void* fn_110_2268(void* p1, short p2);

extern "C" void* fn_110_23A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_240C(storage + 0x50, -1);
        fn_110_2268(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
