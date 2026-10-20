#pragma force_active on
extern "C" {
void* fn_121_1311C(void* ptr, short count);
void* fn_121_1315C(void* object, short deleting);
void* fn_121_130A8(void* object, short deleting);
void operator delete(void*);
}

extern "C" void* fn_121_131BC(void* object, short deleting) {
    if (object != 0) {
        fn_121_1311C(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_121_1315C(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_121_130A8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
