#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_17DB0(void*, short);
extern "C" void fn_104_3C90(void*, short);

extern "C" void* fn_104_17D40(void* object, short deleting) {
    if (object != 0) {
        fn_104_17DB0(static_cast<unsigned char*>(object) + 0x8, -1);
        fn_104_3C90(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
