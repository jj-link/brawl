#pragma force_active on
extern "C" {
void* fn_107_2130(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_107_29E8(void*, short);
void __dl__FPv(void*);

void* fn_107_20AC(void* unk, short deleting) {
    if (unk) {
        short memberDeleting = -1;
        fn_107_2130((char*)unk + 0x1DFCC, memberDeleting);
        fn_27_C74E8((char*)unk + 0x1DFBC, memberDeleting);
        fn_107_29E8(unk, 0);
        if (deleting > 0) __dl__FPv(unk);
    }
    return unk;
}
}
