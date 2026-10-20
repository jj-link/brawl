#pragma force_active on
extern "C" void* fn_121_2CE0(void* object, short deleting);
extern "C" void* fn_121_2DA0(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_121_2DFC(void* object, short deleting) {
    if (object != 0) {
        fn_121_2CE0(static_cast<unsigned char*>(object) + 0xac, -1);
        fn_121_2DA0(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
