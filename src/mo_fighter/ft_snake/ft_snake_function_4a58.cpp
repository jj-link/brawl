#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_122_4AD0(void*, short);

extern "C" void* fn_122_4A58(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<unsigned char*>(object) + 0x9C, -1);
        fn_27_21038(static_cast<unsigned char*>(object) + 0x88, -1);
        fn_122_4AD0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
