#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_121_2F88(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_121_2F2C(void*, short);
extern "C" void* fn_121_2ED0(void*, short);
extern "C" void* fn_121_2C0C(void*, short);
extern "C" void* fn_121_2E74(void*, short);
extern "C" void* fn_121_2DFC(void*, short);

extern "C" void* fn_121_2FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_121_2F88(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_121_2F2C(storage + 0x1B8, -1);
        fn_121_2ED0(storage + 0x198, -1);
        fn_121_2C0C(storage + 0x160, -1);
        fn_121_2E74(storage + 0xC4, -1);
        fn_121_2DFC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
