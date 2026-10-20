#pragma force_active on
extern "C" void* fn_104_4CC4(void*, short);
extern "C" void* fn_104_5304(void*, short);
void operator delete(void*);

extern "C" void* fn_104_4C4C(void* object, short deleting) {
    if (object != 0) {
        fn_104_4CC4(static_cast<unsigned char*>(object) + 0x3E74, -1);
        if (object != 0) {
            fn_104_5304(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
