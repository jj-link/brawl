#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_F910(void*, short);
extern "C" void* fn_96_5F44(void*, short);
extern "C" void* fn_96_5E78(void*, short);

extern "C" void* fn_96_5FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_F910(storage + 0xE0, -1);
        fn_96_5F44(storage + 0x30, -1);
        fn_96_5E78(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
