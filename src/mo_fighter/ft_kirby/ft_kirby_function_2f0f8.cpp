#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_7A08(void*, short);
extern "C" void* fn_96_7A74(void*, short);
extern "C" void* fn_96_7B00(void*, short);
extern "C" void* fn_96_7B8C(void*, short);
extern "C" void* fn_96_2F188(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_2F0F8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_7A08(storage + 0x4B0, -1);
        fn_96_7A74(storage + 0x384, -1);
        fn_96_7B00(storage + 0x258, -1);
        fn_96_7B8C(storage + 0x12C, -1);
        fn_96_2F188(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
