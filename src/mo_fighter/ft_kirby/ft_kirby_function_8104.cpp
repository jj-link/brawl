#pragma force_active on
void operator delete(void*);
extern "C" void fn_96_80A4(void* object, short deleting);
extern "C" void fn_96_7748(void* object, short deleting);

extern "C" void* fn_96_8104(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_80A4(storage + 0x7228, -1);
        if (object != 0) {
            fn_96_7748(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
