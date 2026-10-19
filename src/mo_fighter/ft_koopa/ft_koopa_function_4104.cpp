#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_33C0(void*, short);
extern "C" void fn_102_4170(void*, short);

extern "C" void* fn_102_4104(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_33C0(storage + 0x3F18, -1);
        fn_102_4170(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
