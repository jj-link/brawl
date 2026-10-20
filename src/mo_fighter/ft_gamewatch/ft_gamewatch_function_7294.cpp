#pragma force_active on
void operator delete(void*);
extern "C" void fn_107_730C(void* object, short flag);
extern "C" void* fn_27_1A15B8(void*, short);

extern "C" void* fn_107_7294(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A15B8(storage + 0x11C, -1);
        if (object != 0) {
            fn_107_730C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
