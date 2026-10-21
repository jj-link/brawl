#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_39EC(void*, short);
extern "C" void* fn_123_12644(void*, short);
extern "C" void* fn_123_126D0(void*, short);
extern "C" void* fn_123_1275C(void*, short);
extern "C" void* fn_123_3A58(void*, short);

extern "C" void* fn_123_125B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_39EC(storage + 0x4B0, -1);
        fn_123_12644(storage + 0x384, -1);
        fn_123_126D0(storage + 0x258, -1);
        fn_123_1275C(storage + 0x12C, -1);
        fn_123_3A58(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
