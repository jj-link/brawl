#pragma force_active on
extern "C" void* fn_96_4CE8(void*, short);
extern "C" void* fn_96_4C88(void*, short);
extern "C" void* fn_96_25C08(void*, short);
extern "C" void* fn_96_7D5C(void*, short);
extern "C" void* fn_96_27818(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

void operator delete(void*);

extern "C" void* fn_96_27878(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_4CE8(storage + 0x11C, -1);
        fn_96_4C88(storage + 0x108, -1);
        fn_96_25C08(storage + 0xF4, -1);
        fn_96_7D5C(storage + 0x50, -1);
        fn_96_27818(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
