#pragma force_active on
extern "C" void* fn_109_3D70(void* object, short deleting);
extern "C" void* fn_109_10A18(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_109_109A0(void* object, short deleting) {
    if (object != 0) {
        fn_109_3D70(static_cast<unsigned char*>(object) + 0x8C, -1);
        fn_109_10A18(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
