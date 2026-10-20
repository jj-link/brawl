#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3D98(void* object, short deleting);
extern "C" void* fn_27_D2AA4(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_108_4404(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_3D98(storage + 0x6C, -1);
        if (storage + 0x20 != 0) {
            if (storage + 0x20 != 0) {
                if (storage + 0x20 != 0) {
                    fn_27_D2AA4(storage + 0x20, -1);
                }
            }
        }
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
