#pragma force_active on
extern "C" void* fn_102_20A0(void* object, short deleting);
extern "C" void* fn_102_2264(void* object, short deleting);
extern "C" void* fn_102_232C(void* object, short deleting);
extern "C" void* fn_102_23B8(void* object, short deleting);
extern "C" void* fn_102_2444(void* object, short deleting);
extern "C" void* fn_102_24D0(void* object, short deleting);
extern "C" void* fn_102_255C(void* object, short deleting);
extern "C" void* fn_102_25E8(void* object, short deleting);
extern "C" void* fn_102_2674(void* object, short deleting);
extern "C" void* fn_102_2700(void* object, short deleting);
extern "C" void* fn_102_278C(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_102_1FC8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_20A0(storage + 0x14D0, -1);
        fn_102_2264(storage + 0x13AC, -1);
        fn_102_232C(storage + 0x1280, -1);
        fn_102_23B8(storage + 0x1154, -1);
        fn_102_2444(storage + 0x1028, -1);
        fn_102_24D0(storage + 0xEFC, -1);
        fn_102_255C(storage + 0xDD0, -1);
        fn_102_25E8(storage + 0xCA4, -1);
        fn_102_2674(storage + 0xB78, -1);
        fn_102_2700(storage + 0xA4C, -1);
        fn_102_278C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}