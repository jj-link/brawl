#pragma force_active on
extern "C" void* fn_102_20A0(void* object, short deleting);
extern "C" void* fn_102_2264(void* object, short deleting);
extern "C" void* fn_102_10F3C(void* object, short deleting);
extern "C" void* fn_102_10FC8(void* object, short deleting);
extern "C" void* fn_102_11054(void* object, short deleting);
extern "C" void* fn_102_110E0(void* object, short deleting);
extern "C" void* fn_102_1116C(void* object, short deleting);
extern "C" void* fn_102_111F8(void* object, short deleting);
extern "C" void* fn_102_11284(void* object, short deleting);
extern "C" void* fn_102_11310(void* object, short deleting);
extern "C" void* fn_102_1139C(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_102_10E64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_20A0(storage + 0x14D8, -1);
        fn_102_2264(storage + 0x13B4, -1);
        fn_102_10F3C(storage + 0x1288, -1);
        fn_102_10FC8(storage + 0x115C, -1);
        fn_102_11054(storage + 0x1030, -1);
        fn_102_110E0(storage + 0xF04, -1);
        fn_102_1116C(storage + 0xDD8, -1);
        fn_102_111F8(storage + 0xCAC, -1);
        fn_102_11284(storage + 0xB80, -1);
        fn_102_11310(storage + 0xA54, -1);
        fn_102_1139C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}