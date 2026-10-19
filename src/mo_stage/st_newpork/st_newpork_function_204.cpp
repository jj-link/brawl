#pragma force_active on
extern "C" {
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern void fn_8009EE60(void*, int);
extern void __dl__FPv(void*);
extern const char lbl_69_data_328[];

void* fn_69_204(void* this_ptr, int arg2) {
    if (this_ptr) {
        *(void**)((char*)this_ptr + 0x3C) = (void*)lbl_69_data_328;
        releaseArchive__15stCommonGimmickFv(this_ptr);
        fn_8009EE60((char*)this_ptr + 0x2BC, -1);
        __dt__7stMeleeFv(this_ptr, 0);
        if (arg2 > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}
}
