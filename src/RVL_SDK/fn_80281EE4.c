#pragma force_active on

typedef unsigned int u32;

extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);

extern char lbl_8040F628[];
extern char lbl_8040F668[];
extern char lbl_8040F6A4[];
extern char lbl_80532480[];

void fn_80281EE4(void) {
    fn_8027C808(lbl_80532480, lbl_8040F6A4, 0, 8, 0, 0,
               (u32)lbl_8040F628, 2, (u32)lbl_8040F668, 3, 0);
}

__declspec(section ".ctors") extern void* const fn_80281EE4_ctor = (void*)fn_80281EE4;
