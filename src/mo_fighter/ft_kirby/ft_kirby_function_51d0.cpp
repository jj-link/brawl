#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_96_5158(void*, short);

extern "C" void* fn_96_51D0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11C, -1);
        if (object != 0) {
            fn_96_5158(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
