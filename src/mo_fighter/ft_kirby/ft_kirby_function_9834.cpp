#pragma force_active on
typedef unsigned long Word;
typedef unsigned char Byte;

extern "C" {
extern Word lbl_96_data_4;

void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);

void* fn_96_9834(Byte* fp, void* paramBlock, Word effectA, Word effectB,
                 Word effectC, Word effectD, void* singletons) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5C, 1, &lbl_96_data_4, 0);
    fn_27_9747C(fp + 0x6C, paramBlock, fp, effectA, fp + 0x5C,
                fp + 0x38, effectB, singletons, effectC, 10, effectD, fp + 0x50);
    return fp;
}
}
