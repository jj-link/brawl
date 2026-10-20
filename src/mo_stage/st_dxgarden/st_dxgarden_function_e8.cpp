#pragma force_active on
extern "C" {
extern char lbl_77_data_1B8[];
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);

void* fn_77_E8(void* self, int arg) {
    if (self) {
        void* ptr = *(void**)((char*)self + 0x1F8);
        *(void**)((char*)self + 0x3C) = lbl_77_data_1B8;
        if (ptr) {
            __dl__FPv(ptr);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
