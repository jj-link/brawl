#pragma force_active on

extern "C" {
void* fn_27_A78FC(void*, short);
void* fn_27_CB5CC(void*, short);
void* fn_27_A3704(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_41_22FC0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_A78FC(members + 0x48c, memberDeleting);
        fn_27_CB5CC(members + 0x60, memberDeleting);
        fn_27_A3704(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
