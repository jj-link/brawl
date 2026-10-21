#pragma force_active on
extern "C" {
extern char lbl_82_data_360[];
void releaseArchive__15stCommonGimmickFv(void*);
void exit__6gfTaskFv(void*);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_82_114(void* self, int flag) {
    if (self) {
        char* p = (char*)self;
        *(void**)(p + 0x3c) = lbl_82_data_360;
        releaseArchive__15stCommonGimmickFv(p);
        void* task = *(void**)(p + 0x1040);
        if (task) {
            exit__6gfTaskFv(task);
        }
        __dt__14snd3DGeneratorFv(p + 0x1034, -1);
        __dt__14snd3DGeneratorFv(p + 0x1028, -1);
        __dt__14snd3DGeneratorFv(p + 0x1018, -1);
        __dt__14snd3DGeneratorFv(p + 0x1008, -1);
        __dt__7stMeleeFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return self;
}
}
