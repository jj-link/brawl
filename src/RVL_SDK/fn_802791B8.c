#include <types.h>
#pragma force_active on

extern void fn_8015C144(void*, void*);
extern void* fn_8015C1B0(void*, void*);
extern void fn_80204E6C(int, void*);
extern void __dl__FPv(void*);
extern int lbl_80485FAC[];

typedef struct {
    void* vtbl;
    int unk4;
    void* m_list;
    int unkC;
    int unk10;
    int unk14;
} Obj;

void* fn_802791B8(void* arg0, s32 arg1) {
    Obj* obj;
    void* curr;
    obj = (Obj*)arg0;
    if (obj != NULL) {
        obj->vtbl = lbl_80485FAC;
        curr = fn_8015C1B0(&obj->m_list, NULL);
        while (curr != NULL) {
            fn_8015C144(&obj->m_list, curr);
            if (obj->unk14 != 0) {
                fn_80204E6C(obj->unk14, curr);
            } else {
                __dl__FPv(curr);
            }
            curr = fn_8015C1B0(&obj->m_list, NULL);
        }
        if (arg1 > 0) {
            __dl__FPv(obj);
        }
    }
    return arg0;
}
