#pragma force_active on
#include <types.h>
#include <ut/ut_list.h>

struct SoNode {
    SoNode* next;
    u32 pad4;
    u32 pad8;
    struct SoData* data;
};

struct SoData {
    u8 pad[0x30];
    u32 flags;
};

class SoFlagSource {
public:
    virtual void f2();
    virtual SoData* getData();
};

class SoOwner {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual int query(int id);
};

extern "C" int fn_27_6A87C(SoOwner* self, int id, int bitIndex) {
    if (id >= 0) {
        SoFlagSource* src = *(SoFlagSource**)((u8*)self + 0x48);
        SoData* data = src->getData();
        u32 bit = 1U << bitIndex;
        return ((data->flags >> 8) & bit) != 0;
    }
    if (self->query(-1)) {
        utList* list = (utList*)((u8*)self + 0x20);
        SoNode* node = (SoNode*)list->getNode(0);
        u32 bit = 1U << bitIndex;
        while (node != 0) {
            if ((node->data->flags >> 8) & bit) {
                return 1;
            }
            node = node->next;
        }
    }
    return 0;
}
