#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_93_3D80(void*, short);

extern "C" void* fn_93_3DC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0x14, -1);
        fn_93_3D80(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
