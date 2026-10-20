#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_420C(void*, short);
extern "C" void* fn_122_906C(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_122_8FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_420C(storage + 0x85C, -1);
        fn_122_906C(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
