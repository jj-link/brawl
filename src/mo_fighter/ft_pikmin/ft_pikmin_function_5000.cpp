#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void*, short);
extern "C" void fn_113_5078(void*, short);

extern "C" void* fn_113_5000(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_113_5078(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
