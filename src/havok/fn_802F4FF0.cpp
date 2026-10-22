#pragma force_active on
class Item {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
struct Obj {
    char pad[0x120];
    Item** items;
    int count;
};
extern "C" void fn_802F4FF0(Obj* self, int arg) {
    for (int i = self->count - 1; i >= 0; --i) {
        Item* item = self->items[i];
        if (item) item->f2(arg);
    }
    int j;
    int i = self->count - 1;
    int off = i * 4;
    for (; i >= 0; off -= 4, --i) {
        if (*(Item**)((char*)self->items + off) == 0) {
            j = i;
            --self->count;
            unsigned so = (unsigned)j * 4;
            for (; j < self->count; ++j, so += 4) {
                Item** p = (Item**)((char*)self->items + so);
                p[0] = p[1];
            }
        }
    }
}
