#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_100_20CC(void*, short);
void* fn_100_2290(void*, short);
void* fn_100_2358(void*, short);
void* fn_100_23E4(void*, short);
void* fn_100_2470(void*, short);
void* fn_100_24FC(void*, short);
void* fn_100_2588(void*, short);
void* fn_100_2614(void*, short);
void* fn_100_26A0(void*, short);
void* fn_100_272C(void*, short);
void* fn_100_27B8(void*, short);
}

extern "C" void* fn_100_1FF4(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_20CC(storage + 0x14C8, destroy);
        fn_100_2290(storage + 0x13A4, destroy);
        fn_100_2358(storage + 0x1278, destroy);
        fn_100_23E4(storage + 0x114C, destroy);
        fn_100_2470(storage + 0x1020, destroy);
        fn_100_24FC(storage + 0xEF4, destroy);
        fn_100_2588(storage + 0xDC8, destroy);
        fn_100_2614(storage + 0xC9C, destroy);
        fn_100_26A0(storage + 0xB70, destroy);
        fn_100_272C(storage + 0xA44, destroy);
        fn_100_27B8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
