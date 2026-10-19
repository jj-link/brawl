#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_129B8(void*, short);
extern "C" void fn_93_137C0(void*, short);

extern "C" void* fn_93_13848(void* object, short deleting) {
    if (object != 0) {
        fn_93_129B8(static_cast<unsigned char*>(object) + 0x20E8, -1);
        fn_93_137C0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
