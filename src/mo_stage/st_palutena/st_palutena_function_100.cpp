#pragma force_active on
extern "C" {
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern char lbl_67_data_608[];

void* fn_67_100(void* self, int flags) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_67_data_608;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
