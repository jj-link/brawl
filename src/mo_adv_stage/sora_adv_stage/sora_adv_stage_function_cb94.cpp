#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Sub {
    u32 pad;
    u32 count;
};

class Cont {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* get(u32 idx);
    u32 pad;
    Sub* sub;
};

extern "C" {
void* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void createGimmickFrameTrigger__15stCommonGimmickFP25grGimmickFrameTriggerData(void*, void*, void*);
}

extern "C" void fn_40_CB94(void* self, u32 a, void* b) {
    Cont* c;
    u32 i = 0;
    while ((c = (Cont*)searchContainer__20stDataMultiContainerFUlUl(b, a, i++)) != 0) {
        for (u32 j = 0; j < c->sub->count; j++) {
            void* obj = c->get(j);
            createGimmickFrameTrigger__15stCommonGimmickFP25grGimmickFrameTriggerData(
                self, obj, *(void**)((u8*)self + 0x1a0));
        }
    }
}
