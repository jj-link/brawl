#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_3F44(void*, short);
extern "C" void* fn_101_1E3D4(void*, short);
extern "C" void* fn_101_3FC4(void*, short);

extern "C" void* fn_101_1E35C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_101_3F44(members + 0x68, memberDeleting);
        fn_101_1E3D4(members + 0x30, memberDeleting);
        fn_101_3FC4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
