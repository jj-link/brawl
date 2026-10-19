#pragma force_active on
extern "C" {
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern char lbl_76_data_D4[];
}

extern "C" void* fn_76_100(void* self, int shouldFree) {
    if (self) {
        *(char**)((char*)self + 0x3C) = lbl_76_data_D4;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (shouldFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
