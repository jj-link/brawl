#pragma force_active on
void operator delete(void*);
extern "C" void fn_94_5638(void* object, short flag);
extern "C" void* fn_27_1A1FE4(void* object, short flag);

extern "C" void* fn_94_55C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, -1);
        if (object != 0) {
            fn_94_5638(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
