#pragma force_active on
extern "C" {
void* fn_109_2154(void* object, short deleting);
void* fn_109_21F0(void* ptr, short size);
void* fn_109_2230(void* object, short deleting);
void* fn_27_C7770(void* object, short deleting);
}

extern "C" void* fn_109_269C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_109_2154(static_cast<char*>(object) + 0xDC, memberDeleting);
        fn_109_21F0(static_cast<char*>(object) + 0xC0, memberDeleting);
        fn_109_2230(static_cast<char*>(object) + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
