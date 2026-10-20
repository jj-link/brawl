#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_12268(void* object, short deleting);
extern "C" void fn_96_12134(void* object, short deleting);

extern "C" void* fn_96_122C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_12268(storage + 0x1C8, -1);
        if (object != 0) {
            fn_96_12134(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
