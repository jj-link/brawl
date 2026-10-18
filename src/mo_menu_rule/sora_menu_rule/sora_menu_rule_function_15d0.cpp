#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Direction {
    u16 target;
    u8 enabled;
    u8 padding;
};

struct RuleEntry {
    Direction directions[4];
};

struct MenuItem {
    u8 data[0xA8];
};

struct MenuRule {
    u8 padding000[0x42];
    u16 current;
    u8 padding044[4];
    MenuItem items[9];
    u8 padding630[0xC];
    RuleEntry* entries;
    u8 padding640[0x28];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void change();
};

extern "C" void fn_800BA364(MenuItem*, u32);

extern "C" int fn_18_15D0(MenuRule* self, u32 input)
{
    int changed = 0;
    u16 next;

    if (input & 1) {
        changed = 1;
        next = self->entries[self->current].directions[0].target;
    } else if (input & 2) {
        changed = 1;
        next = self->entries[self->current].directions[1].target;
    } else if (input & 4) {
        changed = 1;
        next = self->entries[self->current].directions[2].target;
    } else if (input & 8) {
        changed = 1;
        next = self->entries[self->current].directions[3].target;
    }

    if (changed) {
        if (next != self->current) {
            self->change();

            MenuItem* item;
            u32 flags = 0;
            self->current = next;

            if (self->entries[next].directions[0].enabled)
                flags |= 8;
            if (self->entries[next].directions[1].enabled)
                flags |= 4;
            if (self->entries[next].directions[2].enabled)
                flags |= 1;
            if (self->entries[next].directions[3].enabled)
                flags |= 2;

            item = self->items;
            for (u32 i = 0; i < 9; ++i, ++item) {
                fn_800BA364(item, flags);
            }
        } else {
            changed = 0;
        }
    }

    return changed;
}
