#pragma force_active on
// fn_120_7600 -- ft_robot .text [0x7600, 0x76CC)
//
// Initializes the effect-work block embedded in the robot fighter's event
// storage.  The receiver (r3) is the embedded block itself, not the outer
// fighter base.  Initializes +0 followed by its members at +0x38, +0x50,
// +0x5C and +0x6C.  The +0x5C member receives the address of the
// externally defined module-local .data word lbl_120_data_4.  The final
// twelve-argument setup call forwards the caller's arguments, the embedded
// member addresses and literal 10.  Returns the block pointer.

typedef unsigned long Word;
typedef unsigned char Byte;

// ABI views of the out-of-line sora_melee initializers used below. Their
// storage belongs to the callee objects, not these declaration-only views.
extern "C" {
// .data:0x4 -- defined by the module's auto-linked data unit; this
// translation unit only references it.
extern Word lbl_120_data_4;

void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
}

extern "C" void* fn_120_7600(Byte* fp, void* paramBlock, Word arg3, Word arg4,
                             Word arg5, Word arg6, void* arg7) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5c, 1, &lbl_120_data_4, 0);
    fn_27_9747C(fp + 0x6c, paramBlock, fp, arg3, fp + 0x5c, fp + 0x38,
                arg4, arg7, arg5, 10, arg6, fp + 0x50);
    return fp;
}
