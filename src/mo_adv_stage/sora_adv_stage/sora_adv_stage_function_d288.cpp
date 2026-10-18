#pragma force_active on
typedef unsigned int u32;

struct grGimmickCatapultData;
struct gfArchive;

struct Container;
struct ContainerSub {
    u32 pad0;
    u32 count;
};

struct Container {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual grGimmickCatapultData* getData(u32 idx);
    u32 pad4;
    ContainerSub* sub;
};

struct stCommonGimmick {
    char pad[0x1a0];
    gfArchive* archive;
    void createGimmickCatapult(grGimmickCatapultData* data, gfArchive* arc);
};

extern "C" Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);

extern "C" void fn_40_D288(stCommonGimmick* self, u32 id, void* container) {
    Container* c;
    u32 idx = 0;
    while ((c = searchContainer__20stDataMultiContainerFUlUl(container, id, idx++)) != 0) {
        for (u32 i = 0; i < c->sub->count; i++) {
            grGimmickCatapultData* d = c->getData(i);
            self->createGimmickCatapult(d, self->archive);
        }
    }
}
