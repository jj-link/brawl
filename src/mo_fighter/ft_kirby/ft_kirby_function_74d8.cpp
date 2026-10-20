#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_7478(void* object, short deleting);
extern "C" void* fn_96_73A8(void* object, short deleting);

extern "C" void* fn_96_74D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_7478(storage + 0x2DAC, -1);
        if (object != 0) {
            fn_96_73A8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
