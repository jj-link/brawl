#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_125_73A8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_733C(void* object, short deleting) {
    if (object != 0) {
        short releasing = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0x14, releasing);
        fn_125_73A8(object, releasing);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
