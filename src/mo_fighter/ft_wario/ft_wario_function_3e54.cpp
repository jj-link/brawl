#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_2024(void*, short);
extern "C" void* fn_110_3EC0(void*, short);

extern "C" void* fn_110_3E54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_2024(storage + 0x20, 0);
        fn_110_3EC0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
