#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_110_4698(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_1C6C0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x9C, -1);
        fn_27_21038(storage + 0x88, -1);
        fn_110_4698(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
