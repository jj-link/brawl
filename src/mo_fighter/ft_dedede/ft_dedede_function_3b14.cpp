#pragma force_active on
extern "C" {
void* fn_117_3B84(void*, short);
void* fn_117_3BE4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_117_3B14(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_3B84(static_cast<unsigned char*>(object) + 0x30000 - 0x33E8,
                    memberDeleting);
        fn_117_3BE4(storage + 4, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
