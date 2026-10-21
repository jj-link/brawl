#pragma force_active on
typedef unsigned long Word;
typedef unsigned char Byte;

extern "C" {
void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
extern Word lbl_103_data_4;
}

extern "C" void* fn_103_8B48(Byte* fp, void* arg1, Word arg2, Word arg3,
                             Word arg4, Word arg5, void* arg6) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5c, 1, &lbl_103_data_4, 0);
    fn_27_9747C(fp + 0x6c, arg1, fp, arg2, fp + 0x5c, fp + 0x38,
                arg3, arg6, arg4, 10, arg5, fp + 0x50);
    return fp;
}
