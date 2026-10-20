#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1CFC(void* member, short deleteFlag);
extern "C" void* fn_105_666C(void* object, short deleting);

extern "C" void* fn_105_65F4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC(static_cast<unsigned char*>(object) + 0x524, -1);
        if (object != 0) {
            fn_105_666C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
