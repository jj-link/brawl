#pragma force_active on
extern "C" void* fn_113_14640(void*, short);
extern "C" void* fn_113_2948(void*, short);
extern "C" void* fn_113_146CC(void*, short);
extern "C" void* fn_113_14744(void*, short);
extern "C" void* fn_113_147BC(void*, short);
extern "C" void* fn_113_14834(void*, short);

extern "C" void* fn_113_145A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_14640(storage + 0x58C, -1);
        fn_113_2948(storage + 0x490, -1);
        fn_113_146CC(storage + 0x374, -1);
        fn_113_14744(storage + 0x258, -1);
        fn_113_147BC(storage + 0x13C, -1);
        fn_113_14834(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
