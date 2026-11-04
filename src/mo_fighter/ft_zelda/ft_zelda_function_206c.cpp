#pragma force_active on

extern "C" void* fn_104_2144(void*, short);
extern "C" void* fn_104_2308(void*, short);
extern "C" void* fn_104_23D0(void*, short);
extern "C" void* fn_104_245C(void*, short);
extern "C" void* fn_104_24E8(void*, short);
extern "C" void* fn_104_2574(void*, short);
extern "C" void* fn_104_2600(void*, short);
extern "C" void* fn_104_268C(void*, short);
extern "C" void* fn_104_2718(void*, short);
extern "C" void* fn_104_27A4(void*, short);
extern "C" void* fn_104_2830(void*, short);
void operator delete(void*);

extern "C" void* fn_104_206C(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_104_2144(storage + 0x1498, flag);
        fn_104_2308(storage + 0x1374, flag);
        fn_104_23D0(storage + 0x1248, flag);
        fn_104_245C(storage + 0x111C, flag);
        fn_104_24E8(storage + 0xFF0, flag);
        fn_104_2574(storage + 0xEC4, flag);
        fn_104_2600(storage + 0xD98, flag);
        fn_104_268C(storage + 0xC6C, flag);
        fn_104_2718(storage + 0xB40, flag);
        fn_104_27A4(storage + 0xA14, flag);
        fn_104_2830(object, flag);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
