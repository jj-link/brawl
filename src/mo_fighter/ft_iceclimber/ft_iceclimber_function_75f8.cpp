#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_47CCC(void*, short);
extern "C" void* fn_27_CB800(void*, short);
extern "C" void* fn_27_19FB24(void*, short);
extern "C" void* fn_27_19E5E0(void*, short);

extern "C" void* fn_105_75F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0xA14, -1);
        fn_27_47CCC(storage + 0xA04, -1);
        fn_27_CB800(storage + 0x908, -1);
        fn_27_19FB24(storage + 0x78C, -1);
        fn_27_19E5E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
