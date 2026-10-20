#pragma force_active on
void operator delete(void*);
extern "C" void* fn_109_10794(void* slot, short destroy);
extern "C" void* fn_109_107D4(void* object, short deleting);
extern "C" void* fn_109_10834(void* object, short deleting);

extern "C" void* fn_109_1071C(void* object, short deleting) {
    if (object != 0) {
        fn_109_10794(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_109_107D4(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_109_10834(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
