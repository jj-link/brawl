#pragma force_active on
namespace itValueAccesser {
    enum ParamFloat { ParamFloatZero };
}
class BaseItem {
public:
    float getParam(itValueAccesser::ParamFloat);
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

extern "C" float fn_27_B8594(ItemAccessor* __restrict self, itValueAccesser::ParamFloat param, int index) {
    ItemArray* items = self->items;
    return items->at(index)->item->getParam(param);
}
