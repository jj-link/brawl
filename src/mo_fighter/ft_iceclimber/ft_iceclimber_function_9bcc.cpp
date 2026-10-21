#pragma force_active on
typedef unsigned long Word;
typedef unsigned char Byte;

extern "C" {
extern Word lbl_105_data_4;

void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
}

extern "C" void* fn_105_9BCC(Byte* fp, void* paramBlock, Word arg3, Word arg4,
                             Word arg5, Word arg6, void* arg7) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5c, 1, &lbl_105_data_4, 0);
    fn_27_9747C(fp + 0x6c, paramBlock, fp, arg3, fp + 0x5c, fp + 0x38,
                arg4, arg7, arg5, 10, arg6, fp + 0x50);
    return fp;
}
