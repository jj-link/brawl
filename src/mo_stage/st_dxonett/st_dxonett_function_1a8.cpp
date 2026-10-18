#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern void fn_8009EE60(void*, int);
extern const char lbl_78_data_1D0[];

void* fn_78_1A8(void* this_ptr, int arg2) {
    if (this_ptr) {
        void* ptr = *(void**)((char*)this_ptr + 0x2F8);
        *(void**)((char*)this_ptr + 0x3C) = (void*)lbl_78_data_1D0;
        if (ptr) {
            __dl__FPv(ptr);
        }
        ptr = *(void**)((char*)this_ptr + 0x2FC);
        if (ptr) {
            __dl__FPv(ptr);
        }
        releaseArchive__15stCommonGimmickFv(this_ptr);
        fn_8009EE60((char*)this_ptr + 0x260, -1);
        __dt__7stMeleeFv(this_ptr, 0);
        if (arg2 > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}
}
