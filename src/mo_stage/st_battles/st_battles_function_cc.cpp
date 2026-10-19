#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern unsigned char lbl_42_data_68[];

void* fn_42_CC(void* self, int deleteFlag) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_42_data_68;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
