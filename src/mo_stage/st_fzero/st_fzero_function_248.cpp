#pragma force_active on
extern "C" {
void fn_27_239F6C(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

extern char lbl_61_data_790[];

extern "C" void* fn_61_248(void* self, int flags) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_61_data_790;
        fn_27_239F6C((char*)self + 0xbe4);
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
