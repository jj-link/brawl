#pragma force_active on
extern "C" {
extern char lbl_52_data_484[];
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__14snd3DGeneratorFv(void*, int);
extern void __dt__7stMeleeFv(void*, int);
extern void __dl__FPv(void*);

void* fn_52_218(void* self, int del) {
    if (self != 0) {
        int v = *(int*)((char*)self + 0x600);
        *(char**)((char*)self + 0x3C) = lbl_52_data_484;
        if (v != 0) {
            __dl__FPv((void*)v);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__14snd3DGeneratorFv((char*)self + 0x5F4, -1);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
