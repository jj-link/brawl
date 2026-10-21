#pragma force_active on
extern "C" {
extern char lbl_46_data_8EC[];
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__14snd3DGeneratorFv(void*, int);
extern void __dt__7stMeleeFv(void*, int);
extern void __dl__FPv(void*);

void* fn_46_280(void* self, int del) {
    if (self != 0) {
        void* ptr = *(void**)((char*)self + 0x760);
        *(char**)((char*)self + 0x3C) = lbl_46_data_8EC;
        if (ptr != 0) {
            __dl__FPv(ptr);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__14snd3DGeneratorFv((char*)self + 0x224, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x21C, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x214, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x20C, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x204, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x1FC, -1);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
