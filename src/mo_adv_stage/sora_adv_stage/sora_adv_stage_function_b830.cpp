#pragma force_active on
typedef unsigned int u32;

struct ListHeader { u32 unk0; u32 count; };

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* getEff(u32 i);
    u32 unk4;
    ListHeader* list;
};

extern "C" Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
extern "C" void createGimmickHitPointEffectArea__15stCommonGimmickFP27grGimmickHitPointEffectData(void*, void*, u32);

extern "C" {
void fn_40_B830(void* self, u32 a, void* p) {
    Container* c;
    u32 idx = 0;
    while ((c = searchContainer__20stDataMultiContainerFUlUl(p, a, idx++)) != 0) {
        for (u32 i = 0; i < c->list->count; i++) {
            void* eff = c->getEff(i);
            createGimmickHitPointEffectArea__15stCommonGimmickFP27grGimmickHitPointEffectData(self, eff, 0);
        }
    }
}
}
