#pragma force_active on
extern "C" {
void* fn_100_3898(void*, short);
void* fn_100_1270C(void*, short);
void* fn_100_12798(void*, short);
void* fn_100_12824(void*, short);
void* fn_100_128B0(void*, short);
}

extern "C" void* fn_100_1267C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_100_3898(storage + 0x4B0, destroy);
        fn_100_1270C(storage + 0x384, destroy);
        fn_100_12798(storage + 0x258, destroy);
        fn_100_12824(storage + 0x12C, destroy);
        fn_100_128B0(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
