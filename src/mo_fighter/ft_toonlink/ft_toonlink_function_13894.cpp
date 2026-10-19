#pragma force_active on
extern "C" void* fn_121_12A04(void* object, short deleting);
extern "C" void fn_121_1380C(void*, short);

extern "C" void* fn_121_13894(void* object, short deleting) {
    if (object != 0) {
        fn_121_12A04(static_cast<unsigned char*>(object) + 0x20E8, -1);
        fn_121_1380C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
