#pragma force_active on
extern "C" {
void* fn_93_9124(void*, short);
void* fn_93_90B8(void*, short);
void* fn_93_8FD0(void*, short);
void* fn_93_8F44(void*, short);
void* fn_93_8EB8(void*, short);
void* fn_93_8E2C(void*, short);
void* fn_93_8DA0(void*, short);
void* fn_93_8D14(void*, short);
void* fn_93_8C88(void*, short);
void* fn_93_8BFC(void*, short);
void* fn_93_8B64(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_929C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_93_9124(storage + 0x1498, destroy);
        fn_93_90B8(storage + 0x1374, destroy);
        fn_93_8FD0(storage + 0x1248, destroy);
        fn_93_8F44(storage + 0x111C, destroy);
        fn_93_8EB8(storage + 0xFF0, destroy);
        fn_93_8E2C(storage + 0xEC4, destroy);
        fn_93_8DA0(storage + 0xD98, destroy);
        fn_93_8D14(storage + 0xC6C, destroy);
        fn_93_8C88(storage + 0xB40, destroy);
        fn_93_8BFC(storage + 0xA14, destroy);
        fn_93_8B64(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
