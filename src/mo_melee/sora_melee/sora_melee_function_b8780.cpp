#pragma force_active on
struct BaseItem;

extern "C" void* getInstance__9itManagerFv();
extern "C" void removeItem__9itManagerFP8BaseItem(void* self, BaseItem* item);

extern "C" int fn_27_B8780(void*, BaseItem* item) {
    removeItem__9itManagerFP8BaseItem(getInstance__9itManagerFv(), item);
    return 1;
}
