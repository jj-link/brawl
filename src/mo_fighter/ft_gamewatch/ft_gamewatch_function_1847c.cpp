#pragma force_active on
void operator delete(void*);
extern "C" void* fn_107_3A20(void*, short);
extern "C" void* fn_107_1850C(void*, short);
extern "C" void* fn_107_18598(void*, short);
extern "C" void* fn_107_18624(void*, short);
extern "C" void* fn_107_50A0(void*, short);

extern "C" void* fn_107_1847C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_3A20(storage + 0x4B0, -1);
        fn_107_1850C(storage + 0x384, -1);
        fn_107_18598(storage + 0x258, -1);
        fn_107_18624(storage + 0x12C, -1);
        fn_107_50A0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
