#pragma force_active on
// fn_104_93B0 -- ft_zelda .text [0x93B0, 0x9478)
//
// Initializes the embedded effect-work block at fp. Initializes +0, then the
// members at +0x38, +0x50, +0x5c, and +0x6c. The +0x5c member receives the
// address of the externally defined module-local .data word lbl_104_data_4.
// The final twelve-argument setup call forwards the caller's arguments,
// embedded member addresses, and literal 10. Returns the embedded pointer.

typedef unsigned long Word;
typedef unsigned char Byte;

extern "C" {
// .data:0x4 -- defined by the module's auto-linked data unit; this
// translation unit only references it.
extern Word lbl_104_data_4;

void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
}

extern "C" void* fn_104_93B0(Byte* fp, void* paramBlock, Word arg3, Word arg4,
                             Word arg5, Word arg6, void* arg7) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5c, 1, &lbl_104_data_4, 0);
    fn_27_9747C(fp + 0x6c, paramBlock, fp, arg3, fp + 0x5c, fp + 0x38,
                arg4, arg7, arg5, 10, arg6, fp + 0x50);
    return fp;
}
