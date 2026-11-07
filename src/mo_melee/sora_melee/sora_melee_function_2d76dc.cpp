#pragma force_active on
struct Entry { float x, y; int value; };
struct Class_A2F8_base { int count; Entry entries[64]; char pad[0x180]; };
class Class_A2F8 : public Class_A2F8_base {
public:
    virtual void fn_27_7C818();
};
struct Vec { float x, y; };
extern "C" int fn_27_2D76DC(Class_A2F8* self, int value, Vec* pos) {
    if (value && self->count < 64) {
        Entry* entry = self->entries;
        int i;
        for (i = 0; i < 64; i++, entry++) {
            if (!entry->value) {
                entry->value = value;
                float y, x;
                x = pos->x;
                y = pos->y;
                entry->x = x;
                entry->y = y;
                self->count++;
                break;
            }
        }
        if (i < 64) {
            self->fn_27_7C818();
            return i;
        }
    }
    return -1;
}