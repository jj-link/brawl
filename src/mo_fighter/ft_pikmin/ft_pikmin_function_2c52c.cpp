#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2948(void*, short);
extern "C" void* fn_113_2C5BC(void*, short);
extern "C" void* fn_113_2C648(void*, short);
extern "C" void* fn_113_2C6D4(void*, short);
extern "C" void* fn_113_2C760(void*, short);

extern "C" void* fn_113_2C52C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2948(storage + 0x4B0, -1);
        fn_113_2C5BC(storage + 0x384, -1);
        fn_113_2C648(storage + 0x258, -1);
        fn_113_2C6D4(storage + 0x12C, -1);
        fn_113_2C760(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
