#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_109_61F0(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_109_625C(void*, short);
extern "C" void* fn_109_62B8(void*, short);
extern "C" void* fn_109_4300(void*, short);
extern "C" void* fn_109_6314(void*, short);
extern "C" void* fn_109_6370(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_613C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_109_61F0(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_109_625C(storage + 0x1B8, -1);
        fn_109_62B8(storage + 0x198, -1);
        fn_109_4300(storage + 0x160, -1);
        fn_109_6314(storage + 0xC4, -1);
        fn_109_6370(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
