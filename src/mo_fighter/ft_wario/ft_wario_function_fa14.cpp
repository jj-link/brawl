#pragma force_active on
extern "C" void* fn_110_12D48(void*, short);
extern "C" void* fn_110_3DA4(void*, short);
extern "C" void* fn_110_3E54(void*, short);
void operator delete(void*);

extern "C" void* fn_110_FA14(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_110_12D48(storage + 0xE0, -1);
        fn_110_3DA4(storage + 0x30, -1);
        fn_110_3E54(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
