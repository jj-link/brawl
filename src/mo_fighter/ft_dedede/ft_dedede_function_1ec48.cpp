#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_198F74(void*, short);
void* fn_27_199318(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
}

extern "C" void* fn_117_1EC48(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_198F74(members + 0xd8, memberDeleting);
        fn_27_199318(members + 0x6c, memberDeleting);
        fn_27_A78FC(members + 0x50, memberDeleting);
        fn_27_A3704(members + 0x4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
