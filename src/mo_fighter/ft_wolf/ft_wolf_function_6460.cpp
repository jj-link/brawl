#pragma force_active on
extern "C" void* fn_125_B6F8(void*, short);
extern "C" void* fn_125_61F0(void*, short);
extern "C" void* fn_125_6260(void*, short);

extern "C" void* fn_125_6460(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_B6F8(storage + 0xE0, -1);
        fn_125_61F0(storage + 0x30, -1);
        fn_125_6260(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
