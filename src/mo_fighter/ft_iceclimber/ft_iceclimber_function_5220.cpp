#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A20EC(void*, short);
extern "C" void* fn_105_3D5C(void* ptr, short flag);

extern "C" void* fn_105_5220(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_105_3D5C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
