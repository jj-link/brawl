#pragma force_active on
extern "C" {
extern void __dla__FPv(void*);
extern void __dl__FPv(void*);
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern unsigned char lbl_50_data_4B0[];

void* fn_50_168(void* self, int deleteFlag) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x3F4);
        *(void**)((char*)self + 0x3C) = lbl_50_data_4B0;
        if (ptr != 0) {
            __dla__FPv(ptr);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
