#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3708(void*, short);
extern "C" void* fn_108_3774(void*, short);
extern "C" void* fn_108_3800(void*, short);
extern "C" void* fn_108_388C(void*, short);
extern "C" void* fn_108_10164(void*, short);

extern "C" void* fn_108_100D4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_3708(storage + 0x4B0, -1);
        fn_108_3774(storage + 0x384, -1);
        fn_108_3800(storage + 0x258, -1);
        fn_108_388C(storage + 0x12C, -1);
        fn_108_10164(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
