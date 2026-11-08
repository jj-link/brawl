#pragma force_active on
extern "C" void* fn_104_2144(void*, short);
extern "C" void* fn_104_2308(void*, short);
extern "C" void* fn_104_1745C(void*, short);
extern "C" void* fn_104_174E8(void*, short);
extern "C" void* fn_104_17574(void*, short);
extern "C" void* fn_104_17600(void*, short);
extern "C" void* fn_104_1768C(void*, short);
extern "C" void* fn_104_17718(void*, short);
extern "C" void* fn_104_177A4(void*, short);
extern "C" void* fn_104_17830(void*, short);
extern "C" void* fn_104_178BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_17384(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short flag = -1;
        fn_104_2144(storage + 0x14B0, flag);
        fn_104_2308(storage + 0x138C, flag);
        fn_104_1745C(storage + 0x1260, flag);
        fn_104_174E8(storage + 0x1134, flag);
        fn_104_17574(storage + 0x1008, flag);
        fn_104_17600(storage + 0xEDC, flag);
        fn_104_1768C(storage + 0xDB0, flag);
        fn_104_17718(storage + 0xC84, flag);
        fn_104_177A4(storage + 0xB58, flag);
        fn_104_17830(storage + 0xA2C, flag);
        fn_104_178BC(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
