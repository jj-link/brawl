#pragma force_active on
extern "C" {
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
extern void* lbl_1_bss_48;

int fn_1_84C8(void* self) {
    exit__6gfTaskFv(*(void**)((char*)self + 8));
    *(void**)((char*)self + 8) = 0;
    __dt__9gfArchiveFv(lbl_1_bss_48, 1);
    return 0;
}
}
