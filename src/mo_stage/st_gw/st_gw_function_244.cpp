#pragma force_active on
struct cmAIController {
    int pad[2];
    unsigned int flags;
};

class Object_vptr_0 {
public:
    virtual void slot0(int);
};

extern "C" {
extern char lbl_63_data_580[];
extern cmAIController* g_cmAIController;
void __dl__FPv(void*);
void fn_27_239F6C(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);

struct stCommonGimmickLike {
    char pad[0x3C];
    char* vtbl;
    char pad2[0x45C - 0x40];
    Object_vptr_0* obj45C;
    char pad3[0x464 - 0x460];
    void* obj464;
};

stCommonGimmickLike* fn_63_244(stCommonGimmickLike* self, int del) {
    if (self) {
        self->vtbl = lbl_63_data_580;
        cmAIController* ai = g_cmAIController;
        if (ai) {
            ai->flags = ai->flags & 0x00FFFFFF;
        }
        if (self->obj464) {
            __dl__FPv(self->obj464);
        }
        self->obj464 = 0;
        fn_27_239F6C((char*)self + 0x204);
        if (self->obj45C) {
            if (self->obj45C) {
                self->obj45C->slot0(1);
            }
        }
        self->obj45C = 0;
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
