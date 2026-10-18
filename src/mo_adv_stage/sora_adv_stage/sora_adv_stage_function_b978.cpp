#pragma force_active on
struct GimmickList {
    int m0;
    unsigned long count; // offset 0x4
};

class GimmickNode {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3(unsigned long idx); // slot 5 (after 2 implicit dtor slots), offset 0x14
    int m4;
    GimmickList* m8; // offset 0x8
};

extern "C" {
GimmickNode* searchContainer__20stDataMultiContainerFUlUl(void* container, unsigned long a, unsigned long b);
void createGimmickBeltConveyor2__15stCommonGimmickFP25grGimmickBeltConveyorData(void* self, void* data, int flag);

void fn_40_B978(void* a, unsigned long b, void* c) {
    GimmickNode* node;
    for (unsigned long idx = 0; (node = searchContainer__20stDataMultiContainerFUlUl(c, b, idx++)) != 0; ) {
        for (unsigned long i = 0; i < node->m8->count; i++) {
            void* data = node->vf3(i);
            createGimmickBeltConveyor2__15stCommonGimmickFP25grGimmickBeltConveyorData(a, data, 0);
        }
    }
}
}
