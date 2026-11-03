#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_95_2254(void*, short);
void* fn_95_2418(void*, short);
void* fn_95_24E0(void*, short);
void* fn_95_256C(void*, short);
void* fn_95_25F8(void*, short);
void* fn_95_2684(void*, short);
void* fn_95_2710(void*, short);
void* fn_95_279C(void*, short);
void* fn_95_2828(void*, short);
void* fn_95_28B4(void*, short);
void* fn_95_2940(void*, short);
void* fn_95_217C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_95_2254(storage + 0x14E0, destroy);
        fn_95_2418(storage + 0x13BC, destroy);
        fn_95_24E0(storage + 0x1290, destroy);
        fn_95_256C(storage + 0x1164, destroy);
        fn_95_25F8(storage + 0x1038, destroy);
        fn_95_2684(storage + 0xF0C, destroy);
        fn_95_2710(storage + 0xDE0, destroy);
        fn_95_279C(storage + 0xCB4, destroy);
        fn_95_2828(storage + 0xB88, destroy);
        fn_95_28B4(storage + 0xA5C, destroy);
        fn_95_2940(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}