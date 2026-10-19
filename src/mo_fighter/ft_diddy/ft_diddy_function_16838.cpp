#pragma force_active on
extern "C" void* fn_115_13870(void* object, short deleting);
extern "C" void fn_115_167C8(void*, short);

extern "C" void* fn_115_16838(void* object, short deleting) {
    if (object != 0) {
        fn_115_13870(static_cast<unsigned char*>(object) + 0x258C, -1);
        fn_115_167C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
