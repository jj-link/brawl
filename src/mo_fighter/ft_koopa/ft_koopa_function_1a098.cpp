#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_1A128(void*, short);
extern "C" void* fn_102_1A194(void*, short);
extern "C" void* fn_102_1A220(void*, short);
extern "C" void* fn_102_1A2AC(void*, short);
extern "C" void* fn_102_1A338(void*, short);

extern "C" void* fn_102_1A098(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_1A128(storage + 0x4B0, -1);
        fn_102_1A194(storage + 0x384, -1);
        fn_102_1A220(storage + 0x258, -1);
        fn_102_1A2AC(storage + 0x12C, -1);
        fn_102_1A338(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
