#pragma force_active on
extern "C" void* fn_102_1990(void*, short);
extern "C" void* fn_102_1D70(void*, short);
extern "C" void* fn_102_1E0C(void*, short);
extern "C" void* fn_102_1F44(void*, short);
extern "C" void* fn_27_125E20(void*, short);

void operator delete(void*);

extern "C" void* fn_102_18F0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_1990(members + 0x140c4, memberDeleting);
        fn_102_1D70(members + 0x13c0c, memberDeleting);
        fn_102_1E0C(members + 0x13bd0, memberDeleting);
        fn_102_1F44(members + 0x194, memberDeleting);
        fn_27_125E20(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
