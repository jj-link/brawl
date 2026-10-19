#pragma force_active on
extern "C" {
extern char lbl_47_data_2C8[];
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_47_184(void* self, int flag) {
    if (self != 0) {
        *(char**)((char*)self + 0x3C) = lbl_47_data_2C8;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
