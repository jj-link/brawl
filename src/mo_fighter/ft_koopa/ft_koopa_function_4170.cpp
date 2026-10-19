#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_33C0(void*, short);
extern "C" void* fn_102_41DC(void*, short);

extern "C" void* fn_102_4170(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_33C0(storage + 0x1F90, -1);
        fn_102_41DC(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
