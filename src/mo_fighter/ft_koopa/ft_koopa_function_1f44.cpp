#pragma force_active on
extern "C" {
void* fn_102_1FC8(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_102_2880(void*, short);
void __dl__FPv(void*);

void* fn_102_1F44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_102_1FC8(members + 0x12440, memberDeleting);
        fn_27_C74E8(members + 0x12430, memberDeleting);
        fn_102_2880(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
}
