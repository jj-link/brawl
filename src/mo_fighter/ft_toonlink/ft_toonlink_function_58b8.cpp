#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_1A68(void* slot, short destroying);
extern "C" void* fn_121_5924(void* object, short deleting);

extern "C" void* fn_121_58B8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_1A68(storage + 0x20, 0);
        fn_121_5924(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
