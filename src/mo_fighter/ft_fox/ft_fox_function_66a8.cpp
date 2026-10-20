#pragma force_active on
void operator delete(void*);
extern "C" void* fn_97_3EC8(void*, short);
extern "C" void* fn_97_6720(void*, short);
extern "C" void* fn_27_19E99C(void*, short);

extern "C" void* fn_97_66A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_97_3EC8(storage + 0x85c, -1);
        fn_97_6720(storage + 0x19c, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
