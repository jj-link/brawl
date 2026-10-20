#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_116_6D54(void*, short);
extern "C" void* fn_116_26070(void*, short);
void operator delete(void*);

extern "C" void* fn_116_25FEC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xd8, -1);
        fn_27_21038(storage + 0xc4, -1);
        fn_116_6D54(storage + 0x88, -1);
        fn_116_26070(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
