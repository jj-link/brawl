#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_123_5038(void*, short);
extern "C" void* fn_123_45A0(void*, short);

extern "C" void* fn_123_14D44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0xd8, -1);
        fn_27_21038(storage + 0xc4, -1);
        fn_123_5038(storage + 0x88, -1);
        fn_123_45A0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
