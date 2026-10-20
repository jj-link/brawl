#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_48BE8(void*, short);
extern "C" void fn_27_47CCC(void*, short);
extern "C" void fn_27_199724(void*, short);
extern "C" void fn_27_19FE54(void*, short);
extern "C" void fn_27_19DCC0(void*, short);

extern "C" void* fn_112_6CC4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0xA34, -1);
        fn_27_47CCC(storage + 0xA24, -1);
        fn_27_199724(storage + 0x838, -1);
        fn_27_19FE54(storage + 0x54C, -1);
        fn_27_19DCC0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
