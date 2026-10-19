#pragma force_active on
extern char lbl_43_data_1F4[];

extern "C" {
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_43_178(void* self, int del) {
    if (self) {
        *(char**)((char*)self + 0x3c) = lbl_43_data_1F4;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
