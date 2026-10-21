#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_102_5A94(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_102_5B00(void*, short);
extern "C" void* fn_102_5B5C(void*, short);
extern "C" void* fn_102_5BB8(void*, short);
extern "C" void* fn_102_5C14(void*, short);
extern "C" void* fn_102_5C70(void*, short);

extern "C" void* fn_102_59E0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_102_5A94(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_102_5B00(storage + 0x1B8, -1);
        fn_102_5B5C(storage + 0x198, -1);
        fn_102_5BB8(storage + 0x160, -1);
        fn_102_5C14(storage + 0xC4, -1);
        fn_102_5C70(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
