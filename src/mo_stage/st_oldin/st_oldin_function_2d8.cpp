#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void fn_8009EE60(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
}

extern char lbl_53_data_378[];

extern "C" void* fn_53_2D8(void* self, int param) {
    if (self) {
        *(void**)((char*)self + 0x3c) = &lbl_53_data_378;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__14snd3DGeneratorFv((char*)self + 0x5fc, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x5e4, -1);
        __dt__14snd3DGeneratorFv((char*)self + 0x5c8, -1);
        fn_8009EE60((char*)self + 0x544, -1);
        fn_8009EE60((char*)self + 0x4c0, -1);
        fn_8009EE60((char*)self + 0x42c, -1);
        fn_8009EE60((char*)self + 0x2e0, -1);
        __dt__7stMeleeFv(self, 0);
        if (param > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
