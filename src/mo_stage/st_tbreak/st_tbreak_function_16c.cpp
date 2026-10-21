#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
extern char lbl_89_data_8E0[];

char* fn_89_16C(char* self, int doDelete) {
    if (self != 0) {
        *(void**)(self + 0x3C) = lbl_89_data_8E0;
        char* p = self;
        for (int i = 0; i < 4; i++) {
            void* entry = *(void**)(p + 0x2F8);
            if (entry != 0) {
                __dl__FPv(entry);
            }
            p += 4;
        }
        void* blk = *(void**)(self + 0x348);
        if (blk != 0) {
            __dl__FPv(blk);
        }
        void* arc = *(void**)(self + 0x33C);
        if (arc != 0) {
            __dl__FPv(arc);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
