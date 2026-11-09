#pragma force_active on
extern "C" void* fn_115_2104(void*, short);
extern "C" void* fn_115_22C8(void*, short);
extern "C" void* fn_115_2390(void*, short);
extern "C" void* fn_115_241C(void*, short);
extern "C" void* fn_115_24A8(void*, short);
extern "C" void* fn_115_2534(void*, short);
extern "C" void* fn_115_25C0(void*, short);
extern "C" void* fn_115_264C(void*, short);
extern "C" void* fn_115_26D8(void*, short);
extern "C" void* fn_115_2764(void*, short);
extern "C" void* fn_115_27F0(void*, short);
void operator delete(void*);

extern "C" void* fn_115_202C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_2104(storage + 0x1530, memberDeleting);
        fn_115_22C8(storage + 0x140C, memberDeleting);
        fn_115_2390(storage + 0x12E0, memberDeleting);
        fn_115_241C(storage + 0x11B4, memberDeleting);
        fn_115_24A8(storage + 0x1088, memberDeleting);
        fn_115_2534(storage + 0xF5C, memberDeleting);
        fn_115_25C0(storage + 0xE30, memberDeleting);
        fn_115_264C(storage + 0xD04, memberDeleting);
        fn_115_26D8(storage + 0xBD8, memberDeleting);
        fn_115_2764(storage + 0xAAC, memberDeleting);
        fn_115_27F0(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
