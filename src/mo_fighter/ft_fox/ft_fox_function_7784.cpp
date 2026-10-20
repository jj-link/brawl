#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_47CCC(void*, short);
extern "C" void* fn_27_19958C(void*, short);
extern "C" void* fn_27_19FCBC(void*, short);
extern "C" void* fn_27_19DF08(void*, short);

extern "C" void* fn_97_7784(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0x964, -1);
        fn_27_47CCC(storage + 0x954, -1);
        fn_27_19958C(storage + 0x7E0, -1);
        fn_27_19FCBC(storage + 0x5AC, -1);
        fn_27_19DF08(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
