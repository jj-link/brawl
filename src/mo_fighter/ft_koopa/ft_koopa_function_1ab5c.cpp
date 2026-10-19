#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_1ABC8(void* object, short deleting);
extern "C" void* fn_102_3D8C(void* object, short deleting);

extern "C" void* fn_102_1AB5C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_1ABC8(storage + 0x24, -1);
        fn_102_3D8C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
