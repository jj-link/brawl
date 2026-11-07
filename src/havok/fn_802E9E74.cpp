#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
struct Item {
    u8 pad[0x58];
    void* owner;
    u8 pad2[0x34];
    u16 index;
};
struct Manager {
    u8 pad[0x26];
    u8 flags : 2;
    u8 rest : 6;
    u8 pad2[0x11];
    Item** items;
    int count;
};
extern "C" void fn_802E9E74(Manager* m, Item* item) {
    m->items[item->index] = m->items[m->count - 1];
    m->items[item->index]->index = item->index;
    m->count--;
    item->owner = 0;
    item->index = 0xffff;
    m->flags = 1;
}