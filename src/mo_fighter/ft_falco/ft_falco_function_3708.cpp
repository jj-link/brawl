#pragma force_active on
void operator delete(void*);

extern "C" void* fn_108_2290(void*, short);
extern "C" void* fn_108_21B4(void*, short);

extern "C" void* fn_108_3708(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_2290(storage + 0x50, -1);
        fn_108_21B4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
