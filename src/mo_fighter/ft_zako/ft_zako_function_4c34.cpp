#pragma force_active on
extern "C" void* fn_126_3370(void* object, short deleting);
extern "C" void* fn_126_4CAC(void* object, short deleting);
extern "C" void* fn_27_CD934(void* object, short deleting);

extern "C" void* fn_126_4C34(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_3370(storage + 0xac, -1);
        fn_126_4CAC(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
