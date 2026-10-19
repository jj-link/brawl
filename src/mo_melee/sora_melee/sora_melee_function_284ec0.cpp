#pragma force_active on
struct BaseItem;

extern "C" void* getInstance__9itManagerFv();
extern "C" void removeItem__9itManagerFP8BaseItem(void* self, BaseItem* item);

extern "C" void fn_27_284EC0(BaseItem* item) {
    removeItem__9itManagerFP8BaseItem(getInstance__9itManagerFv(), item);
}
