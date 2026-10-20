#pragma force_active on
struct Item {
    unsigned char pad[0x54];
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char rest : 4;
};

struct Stage {
    unsigned char pad[0x1A4];
    Item** items;
};

extern "C" void fn_63_4D18(Stage* self) {
    if (self->items == 0)
        return;

    for (int i = 0; i < 20; ++i) {
        Item* p = self->items[i];
        p->b7 = 0;
        p->b4 = p->b7;
        p->b6 = p->b4;
    }
}
