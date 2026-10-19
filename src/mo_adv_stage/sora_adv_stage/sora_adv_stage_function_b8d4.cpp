#pragma force_active on
typedef unsigned long u32;

struct grGimmickWaterData;

struct Counts {
    u32 pad;
    u32 count;
};

struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual grGimmickWaterData* get(u32);
    u32 pad;
    Counts* counts;
};

extern "C" {

Container* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void createGimmickWaterArea__15stCommonGimmickFP18grGimmickWaterData(
    void*, grGimmickWaterData*, int);

void fn_40_B8D4(void* stage, u32 kind, void* multi) {
    Container* container;
    u32 n = 0;
    u32 i;

    while ((container = searchContainer__20stDataMultiContainerFUlUl(
                multi, kind, n++)) != 0) {
        for (i = 0; i < container->counts->count; i++) {
            createGimmickWaterArea__15stCommonGimmickFP18grGimmickWaterData(
                stage, container->get(i), 0);
        }
    }
}

}
