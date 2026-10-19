#pragma force_active on
extern "C" void* fn_104_4D30(void*, short);
extern "C" void* fn_104_5238(void*, short);
void operator delete(void*);

extern "C" void* fn_104_4CC4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_104_4D30(p + 0x3E48, -1);
        fn_104_5238(p + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
