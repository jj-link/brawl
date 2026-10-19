#pragma force_active on
struct FnObj {
    char pad[0x3C];
    void* vtbl;
};

extern char lbl_49_data_E4[];

extern "C" {
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_49_12C(void* self, int flag) {
    if (self != 0) {
        FnObj* obj = (FnObj*)self;
        obj->vtbl = lbl_49_data_E4;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
