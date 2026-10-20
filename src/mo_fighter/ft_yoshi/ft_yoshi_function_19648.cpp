#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_95_5800(void*, short);
extern "C" void* fn_95_47CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_19648(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(reinterpret_cast<unsigned char*>(object) + 0xd8, -1);
        fn_27_21038(reinterpret_cast<unsigned char*>(object) + 0xc4, -1);
        fn_95_5800(reinterpret_cast<unsigned char*>(object) + 0x88, -1);
        fn_95_47CC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
