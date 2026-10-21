#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_118_6630(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_118_669C(void*, short);
extern "C" void* fn_118_66F8(void*, short);
extern "C" void* fn_118_6754(void*, short);
extern "C" void* fn_118_67B0(void*, short);
extern "C" void* fn_118_680C(void*, short);

extern "C" void* fn_118_657C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_118_6630(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_118_669C(storage + 0x1B8, -1);
        fn_118_66F8(storage + 0x198, -1);
        fn_118_6754(storage + 0x160, -1);
        fn_118_67B0(storage + 0xC4, -1);
        fn_118_680C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
