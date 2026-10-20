#pragma force_active on
extern "C" {
extern const char lbl_57_data_234[];
void releaseArchive__15stCommonGimmickFv(void*);
void fn_8009EE60(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);

void* fn_57_298(char* self, int flags) {
    if (self) {
        *(const char**)(self + 0x3C) = lbl_57_data_234;
        releaseArchive__15stCommonGimmickFv(self);
        fn_8009EE60(self + 0x3F4, -1);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
