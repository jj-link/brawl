#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_98_418C(void*, short);
void* fn_98_4210(void*, short);
void* fn_27_1A2D10(void*, short);
void* fn_98_4270(void*, short);
void* fn_98_4398(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_98_40E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_98_418C(members + 0x110, memberDeleting);
        fn_98_4210(members + 0xFC, memberDeleting);
        void* p = members + 0xEC;
        if (p != 0) {
            fn_27_1A2D10(p, memberDeleting);
        }
        fn_98_4270(members + 0x48, memberDeleting);
        fn_98_4398(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
