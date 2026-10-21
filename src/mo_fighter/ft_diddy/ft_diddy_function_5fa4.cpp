#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_115_6058(void*, short);
extern "C" void* fn_115_60C4(void*, short);
extern "C" void* fn_115_6120(void*, short);
extern "C" void* fn_115_617C(void*, short);
extern "C" void* fn_115_61D8(void*, short);
extern "C" void* fn_115_6234(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_5FA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_13C90(storage + 0x224, destroy);
        fn_115_6058(storage + 0x1e8, destroy);
        fn_27_21038(storage + 0x1d8, destroy);
        fn_115_60C4(storage + 0x1b8, destroy);
        fn_115_6120(storage + 0x198, destroy);
        fn_115_617C(storage + 0x160, destroy);
        fn_115_61D8(storage + 0xc4, destroy);
        fn_115_6234(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
