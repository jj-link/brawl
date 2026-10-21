#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void* object, short deleting);
extern "C" void* fn_108_7A64(void* object, short deleting);
extern "C" void* fn_27_21038(void* object, short deleting);
extern "C" void* fn_108_7AD0(void* object, short deleting);
extern "C" void* fn_108_7B2C(void* object, short deleting);
extern "C" void* fn_108_43A8(void* object, short deleting);
extern "C" void* fn_108_7B88(void* object, short deleting);
extern "C" void* fn_108_6274(void* object, short deleting);

extern "C" void* fn_108_79B0(void* object, short deleting) {
    if (object != 0) {
        char* p = static_cast<char*>(object);
        short d = -1;
        fn_27_13C90(p + 0x224, d);
        fn_108_7A64(p + 0x1E8, d);
        fn_27_21038(p + 0x1D8, d);
        fn_108_7AD0(p + 0x1B8, d);
        fn_108_7B2C(p + 0x198, d);
        fn_108_43A8(p + 0x160, d);
        fn_108_7B88(p + 0xC4, d);
        fn_108_6274(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
