#pragma force_active on
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_4742C(void*, short);
extern "C" void* fn_27_CB800(void*, short);
extern "C" void* fn_27_19FB24(void*, short);
extern "C" void* fn_27_19E398(void*, short);

extern "C" void* fn_93_35C4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_48BE8(storage + 0x354, -1);
        fn_27_4742C(storage + 0x344, -1);
        fn_27_CB800(storage + 0x248, -1);
        fn_27_19FB24(storage + 0xcc, -1);
        fn_27_19E398(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
