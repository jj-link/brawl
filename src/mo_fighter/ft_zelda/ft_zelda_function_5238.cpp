#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_4D30(void*, short);
extern "C" void* fn_104_52A4(void*, short);

extern "C" void* fn_104_5238(void* object, short deleting) {
    if (object != 0) {
        fn_104_4D30(static_cast<char*>(object) + 0x1f28, -1);
        fn_104_52A4(static_cast<char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
