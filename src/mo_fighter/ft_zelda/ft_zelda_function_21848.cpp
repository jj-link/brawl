#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_4FAC(void*, short);
extern "C" void* fn_104_218B8(void*, short);

extern "C" void* fn_104_21848(void* object, short deleting) {
    if (object != 0) {
        fn_104_4FAC(static_cast<unsigned char*>(object) + 0x1818, -1);
        fn_104_218B8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
