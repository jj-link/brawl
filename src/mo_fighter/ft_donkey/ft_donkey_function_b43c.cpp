#pragma force_active on
void operator delete(void*);
extern "C" void* fn_92_B3DC(void* object, short deleting);
extern "C" void fn_92_B2A8(void* object, short deleting);

extern "C" void* fn_92_B43C(void* object, short deleting) {
    if (object != 0) {
        fn_92_B3DC((unsigned char*)object + 0x134, -1);
        if (object != 0) {
            fn_92_B2A8(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
