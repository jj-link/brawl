#pragma force_active on
extern "C" {
extern unsigned char lbl_72_data_1D8[];
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_72_1A0(void* self, int flags) {
    if (self != 0) {
        *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(self) + 0x3c) = lbl_72_data_1D8;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
