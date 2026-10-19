#pragma force_active on
extern "C" void* fn_121_1A0C(void*, short);
extern "C" void* fn_121_1A68(void*, short);
void operator delete(void*);

extern "C" void* fn_121_41B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_1A0C(storage + 0x14, 0);
        fn_121_1A68(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
