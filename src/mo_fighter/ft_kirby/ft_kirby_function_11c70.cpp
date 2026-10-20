#pragma force_active on
void operator delete(void*);
extern "C" void* fn_96_11C10(void* object, short deleting);
extern "C" void* fn_96_11AE0(void* object, short deleting);

extern "C" void* fn_96_11C70(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_96_11C10(storage + 0x94, -1);
        if (object != 0) {
            fn_96_11AE0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
