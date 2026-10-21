#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_110_6730(void*, short);
extern "C" void* fn_110_679C(void*, short);
extern "C" void* fn_110_67F8(void*, short);
extern "C" void* fn_110_6854(void*, short);
extern "C" void* fn_110_68B0(void*, short);
extern "C" void* fn_110_690C(void*, short);

extern "C" void* fn_110_667C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(storage + 0x224, memberDeleting);
        fn_110_6730(storage + 0x1E8, memberDeleting);
        fn_27_21038(storage + 0x1D8, memberDeleting);
        fn_110_679C(storage + 0x1B8, memberDeleting);
        fn_110_67F8(storage + 0x198, memberDeleting);
        fn_110_6854(storage + 0x160, memberDeleting);
        fn_110_68B0(storage + 0xC4, memberDeleting);
        fn_110_690C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
