#pragma force_active on
extern "C" void* fn_96_4CE8(void* object, short deleting);
extern "C" void* fn_96_4C88(void* object, short deleting);
extern "C" void* fn_27_1A2D10(void* object, short deleting);
extern "C" void* fn_96_7D5C(void* object, short deleting);
extern "C" void* fn_96_8C1C(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_96_8B78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_4CE8(storage + 0x110, -1);
        fn_96_4C88(storage + 0xFC, -1);
        if (storage + 0xEC != 0) {
            fn_27_1A2D10(storage + 0xEC, -1);
        }
        fn_96_7D5C(storage + 0x48, -1);
        fn_96_8C1C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
