#pragma force_active on
extern "C" void* fn_121_9124(void*, short);
extern "C" void* fn_121_90B8(void*, short);
extern "C" void* fn_121_8FD0(void*, short);
extern "C" void* fn_121_8F44(void*, short);
extern "C" void* fn_121_8EB8(void*, short);
extern "C" void* fn_121_8E2C(void*, short);
extern "C" void* fn_121_8DA0(void*, short);
extern "C" void* fn_121_8D14(void*, short);
extern "C" void* fn_121_8C88(void*, short);
extern "C" void* fn_121_8BFC(void*, short);
extern "C" void* fn_121_8B64(void*, short);
void operator delete(void*);

extern "C" void* fn_121_929C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_121_9124(storage + 0x1498, destroy);
        fn_121_90B8(storage + 0x1374, destroy);
        fn_121_8FD0(storage + 0x1248, destroy);
        fn_121_8F44(storage + 0x111C, destroy);
        fn_121_8EB8(storage + 0xFF0, destroy);
        fn_121_8E2C(storage + 0xEC4, destroy);
        fn_121_8DA0(storage + 0xD98, destroy);
        fn_121_8D14(storage + 0xC6C, destroy);
        fn_121_8C88(storage + 0xB40, destroy);
        fn_121_8BFC(storage + 0xA14, destroy);
        fn_121_8B64(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
