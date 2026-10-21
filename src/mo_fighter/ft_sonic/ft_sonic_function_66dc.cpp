#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_123_6790(void*, short);
extern "C" void* fn_123_67FC(void*, short);
extern "C" void* fn_123_6858(void*, short);
extern "C" void* fn_123_5038(void*, short);
extern "C" void* fn_123_68B4(void*, short);
extern "C" void* fn_123_6910(void*, short);

extern "C" void* fn_123_66DC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_123_6790(storage + 0x1e8, -1);
        fn_27_21038(storage + 0x1d8, -1);
        fn_123_67FC(storage + 0x1b8, -1);
        fn_123_6858(storage + 0x198, -1);
        fn_123_5038(storage + 0x160, -1);
        fn_123_68B4(storage + 0xc4, -1);
        fn_123_6910(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
