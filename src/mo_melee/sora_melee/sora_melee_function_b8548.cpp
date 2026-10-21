#pragma force_active on
namespace itValueAccesser {
    enum ParamInt { ParamIntZero };
}
class BaseItem {
public:
    int getParam(itValueAccesser::ParamInt);
};
struct ItemEntry {
    void* unknown;
    BaseItem* item;
};
class ItemArray {
public:
    virtual void unused();
    virtual ItemEntry* at(int index);
};
struct ItemAccessor {
    char padding[0x38];
    ItemArray* items;
};
extern "C" int fn_27_B8548(ItemAccessor* __restrict self, itValueAccesser::ParamInt param, int index) {
    ItemArray* items = self->items;
    return items->at(index)->item->getParam(param);
}
