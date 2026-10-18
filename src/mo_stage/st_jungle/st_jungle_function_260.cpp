#pragma force_active on
struct cmAIController {
    int pad[2];
    unsigned int flags;
};

struct stConfigLike {
    char pad[0x3C];
    char* vtbl;
    char pad2[0x430 - 0x40];
    void* member;
};

extern "C" {
extern char lbl_51_data_640[];
extern cmAIController* g_cmAIController;
void __dla__FPv(void*);
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);

stConfigLike* fn_51_260(stConfigLike* self, int del) {
    if (self) {
        self->vtbl = lbl_51_data_640;
        cmAIController* ai = g_cmAIController;
        if (ai) {
            ai->flags = ai->flags & 0x00FFFFFF;
        }
        if (self->member) {
            __dla__FPv(self->member);
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
