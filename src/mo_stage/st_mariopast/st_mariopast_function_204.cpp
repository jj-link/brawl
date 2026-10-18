#pragma force_active on
extern "C" {
void fn_27_239F6C(void*);
void __dla__FPv(void*);
void* memset(void*, int, unsigned long);
void __dt__9gfArchiveFv(void*, int);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern char lbl_48_data_1C4[];
extern char* g_cmAIController;

char* fn_48_204(char* self, int doDelete) {
    if (self != 0) {
        *(char**)(self + 0x3c) = lbl_48_data_1C4;
        char* ai = g_cmAIController;
        if (ai != 0) {
            *(unsigned int*)(ai + 8) &= 0x00FFFFFF;
        }
        char* p = self + 0x2E0;
        for (int i = 0; i < 2; i++) {
            fn_27_239F6C(p);
            p += 0x10;
        }
        char* blk = *(char**)(self + 0x2CC);
        if (blk != 0) {
            if (blk != 0) {
                __dla__FPv(blk - 0x10);
            }
            *(char**)(self + 0x2CC) = 0;
        }
        memset(self + 0x2C8, 0, 0x18);
        char* arc = *(char**)(self + 0x1D8);
        if (arc != 0) {
            __dt__9gfArchiveFv(arc, 1);
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
