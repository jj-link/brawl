#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_95_68C4(void*, short);

extern "C" void* fn_95_684C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* self = static_cast<unsigned char*>(object);
        fn_27_1A15B8(self + 0x2fc, -1);
        if (object != 0) {
            fn_95_68C4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
