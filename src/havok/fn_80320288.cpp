#pragma force_active on
struct Item { char data[0x50]; };
struct Pool {
    char pad[0xc];
    int freeCount;
    int usedCount;
    char pad2[0xdcc];
    Item* freeItems[100];
    Item items[1];
};
struct Array { Item** data; int size; };
extern "C" void fn_80320288(Pool* pool, Array* out, int count) {
    int i = pool->freeCount - 1;
    for (; count != 0 && i >= 0; --count) {
        out->data[out->size++] = pool->freeItems[i];
        --i;
        --pool->freeCount;
    }
    for (int i = 0; i < count; ++i) {
        out->data[out->size++] = &pool->items[pool->usedCount++];
    }
}