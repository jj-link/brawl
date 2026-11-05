#pragma force_active on
struct Item { char pad[0x80]; float value; };
struct List { Item** items; int count; char pad[0x4d]; unsigned char flag; };
struct Pair { List* first; List* second; };
struct Object { char pad[0x28]; List* list; Pair* pair; };
inline void set(List* list, int index, float value) {
    if (!list->flag && index == list->count - 1 && list->flag && index != 0)
        list->items[index]->value = value;
}
extern "C" void fn_27_11930(Object* self, int index, float value) {
    if (self->list) {
        set(self->list, index, value);
    } else {
        Pair* pair = self->pair;
        if (pair) {
            set(pair->first, index, value);
            set(pair->second, pair->first->count - 1 - index, value);
        }
    }
}