#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3D98(void* object, short deleting);
extern "C" void* fn_108_62EC(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_108_6274(void* object, short deleting) {
    if (object != 0) {
        fn_108_3D98(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_108_62EC(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
