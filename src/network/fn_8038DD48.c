#pragma force_active on
extern int fn_8038DC08(void);
extern void fn_803621B8(char*, int, int, void*, void*);
extern void fn_8038DA60(void);
extern char lbl_80536500[];
extern char lbl_80490FA8[];
extern int snprintf(char*, int, const char*, ...);

int fn_8038DD48(void* self, void* arg1) {
    int result;
    *(void**)((char*)self + 0x20) = arg1;
    result = fn_8038DC08();
    if (result != 0) {
        return result;
    }
    if (lbl_80536500[0] == 0) {
        snprintf(lbl_80536500, 0x80, lbl_80490FA8, *(int*)self + 4);
    }
    fn_803621B8(lbl_80536500, *(int*)((char*)*(void**)((char*)self + 0x20) + 8), *(int*)((char*)self + 0x18), fn_8038DA60, self);
    return 0;
}
