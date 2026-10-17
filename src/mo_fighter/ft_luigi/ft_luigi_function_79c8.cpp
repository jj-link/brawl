// fn_99_79C8 -- ft_luigi .text [0x79C8, 0x7A94)
//
// Initializes the aggregate at LuigiEventStorage +0xB940 (outer fighter
// +0xBAD4). The sole observed caller is fn_99_70 at .text 0x7E4; fp below
// is this embedded receiver, not the outer fighter base. Initializes +0
// followed by its members at +0x38, +0x50, +0x5c, and +0x6c. The +0x5c
// member receives the address of the externally defined module-local
// .data word lbl_99_data_4. The final twelve-argument setup call forwards
// the caller's arguments, embedded member addresses, and literal 10.
// Returns the embedded receiver pointer.

typedef unsigned long Word;
typedef unsigned char Byte;

// ABI views of the out-of-line sora_melee initializers used below. Their
// storage belongs to the callee objects, not these declaration-only views.
extern "C" {
// .data:0x4 -- defined by the module's auto-linked data unit; this
// translation unit only references it.
extern Word lbl_99_data_4;

void fn_27_CBEC8(void*, int, int);
void fn_27_1986BC(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
}

extern "C" void* fn_99_79C8(Byte* fp, void* paramBlock, Word arg3, Word arg4,
                            Word arg5, Word arg6, void* arg7) {
    fn_27_CBEC8(fp, 1, 0);
    fn_27_1986BC(fp + 0x38, 1, 0);
    fn_27_C9FE4(fp + 0x50, 1, 0);
    fn_27_D37BC(fp + 0x5c, 1, &lbl_99_data_4, 0);
    fn_27_9747C(fp + 0x6c, paramBlock, fp, arg3, fp + 0x5c, fp + 0x38,
                arg4, arg7, arg5, 10, arg6, fp + 0x50);
    return fp;
}
