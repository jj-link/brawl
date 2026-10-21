#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_94_6680(void*, short);
extern "C" void* fn_94_66EC(void*, short);
extern "C" void* fn_94_6748(void*, short);
extern "C" void* fn_94_4CC4(void*, short);
extern "C" void* fn_94_67A4(void*, short);
extern "C" void* fn_94_6800(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_1659C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_13C90(storage + 0x224, -1);
        fn_94_6680(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_94_66EC(storage + 0x1B8, -1);
        fn_94_6748(storage + 0x198, -1);
        fn_94_4CC4(storage + 0x160, -1);
        fn_94_67A4(storage + 0xC4, -1);
        fn_94_6800(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
