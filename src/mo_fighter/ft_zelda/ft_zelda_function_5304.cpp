#pragma force_active on
extern "C" void* fn_104_5374(void*, short);
extern "C" void* fn_104_56F0(void*, short);

void operator delete(void*);

extern "C" void* fn_104_5304(void* object, short deleting) {
    if (object != 0) {
        fn_104_5374(static_cast<unsigned char*>(object) + 0x1F40, -1);
        fn_104_56F0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
