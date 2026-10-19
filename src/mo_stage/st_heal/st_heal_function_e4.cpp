#pragma force_active on
extern "C" {
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern void __dl__FPv(void*);
extern unsigned char lbl_87_data_110[];
}

extern "C" void* fn_87_E4(void* self, int doFree) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_87_data_110;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (doFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
