#pragma force_active on
extern "C" void* fn_27_1F1B8(void*, short);
extern "C" void* fn_96_35B4(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_96_3558(void*, short);
extern "C" void* fn_96_34FC(void*, short);
extern "C" void* fn_96_3238(void*, short);
extern "C" void* fn_96_34A0(void*, short);
extern "C" void* fn_96_3428(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_3620(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1F1B8(storage + 0x224, -1);
        fn_96_35B4(storage + 0x1E8, -1);
        fn_27_21038(storage + 0x1D8, -1);
        fn_96_3558(storage + 0x1B8, -1);
        fn_96_34FC(storage + 0x198, -1);
        fn_96_3238(storage + 0x160, -1);
        fn_96_34A0(storage + 0xC4, -1);
        fn_96_3428(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
