#pragma force_active on
extern "C" void* fn_109_3D70(void* object, short deleting);
extern "C" void* fn_109_63E8(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_109_6370(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_3D70(storage + 0xAC, -1);
        fn_109_63E8(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
