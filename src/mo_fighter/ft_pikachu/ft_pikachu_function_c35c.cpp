#pragma force_active on
extern "C" {
void* fn_98_C2FC(void*, short);
void* fn_98_C1C8(void*, short);
}

extern "C" void* fn_98_C35C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_C2FC(object + 0x204, memberDeleting);
        if (object) fn_98_C1C8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
