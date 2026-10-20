#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_7A08(void*, short);
extern "C" void* fn_96_27BB8(void*, short);
extern "C" void* fn_96_27B2C(void*, short);
extern "C" void* fn_96_27AA0(void*, short);
extern "C" void* fn_96_25984(void*, short);

extern "C" void* fn_96_27C44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_7A08(storage + 0x4B0, -1);
        fn_96_27BB8(storage + 0x384, -1);
        fn_96_27B2C(storage + 0x258, -1);
        fn_96_27AA0(storage + 0x12C, -1);
        fn_96_25984(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
