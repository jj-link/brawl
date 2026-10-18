#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A241C(void*, short);
extern "C" void* fn_92_3D80(void*, short);
extern "C" void fn_92_1FC0(void*, short);
extern "C" void* fn_92_3DC0(void*, short);

extern "C" void* fn_92_3CE4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x30 != 0) {
            fn_27_1A241C(storage + 0x40, -1);
            fn_92_3D80(storage + 0x30, 0);
        }
        if (object != 0) {
            fn_92_1FC0(storage + 0x20, 0);
            fn_92_3DC0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
