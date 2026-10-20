#pragma force_active on
extern "C" void* fn_109_3D70(void*, short);
extern "C" void* fn_109_4E08(void*, short);
extern "C" void* fn_27_19E99C(void*, short);
void operator delete(void*);

extern "C" void* fn_109_4D90(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_109_3D70(storage + 0x85C, -1);
        fn_109_4E08(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
