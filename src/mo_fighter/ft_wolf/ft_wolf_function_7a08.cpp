#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_125_7ABC(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_125_7B28(void*, short);
extern "C" void* fn_125_7B84(void*, short);
extern "C" void* fn_125_4400(void*, short);
extern "C" void* fn_125_7BE0(void*, short);
extern "C" void* fn_125_62CC(void*, short);

extern "C" void* fn_125_7A08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_125_7ABC(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_125_7B28(storage + 0x1B8, -1);
        fn_125_7B84(storage + 0x198, -1);
        fn_125_4400(storage + 0x160, -1);
        fn_125_7BE0(storage + 0xC4, -1);
        fn_125_62CC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
