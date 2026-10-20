#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_94_52F0(void*, short);

extern "C" void* fn_94_5278(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x4B8, -1);
        if (object != 0) {
            fn_94_52F0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
