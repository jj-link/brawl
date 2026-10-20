#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_B650(void*, short);
extern "C" void* fn_108_6198(void*, short);
extern "C" void* fn_108_6208(void*, short);

extern "C" void* fn_108_6408(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_B650(storage + 0xE0, -1);
        fn_108_6198(storage + 0x30, -1);
        fn_108_6208(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
