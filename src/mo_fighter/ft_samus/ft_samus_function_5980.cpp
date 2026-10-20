#pragma force_active on
extern "C" void fn_94_59F8(void* object, short flag);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);

extern "C" void* fn_94_5980(void* object, short deleteFlag) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xB4, -1);
        if (object != 0) {
            fn_94_59F8(object, 0);
        }
        if (deleteFlag > 0) {
            operator delete(object);
        }
    }
    return object;
}
