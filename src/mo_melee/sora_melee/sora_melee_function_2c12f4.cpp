#pragma force_active on

#include <types.h>
#include <it/it_manager.h>

struct Entry {
    void* value;
};

struct Class_90D8_base {
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual Entry* fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0(int);
};

class EntryList {
public:
    virtual void fn_27_7B274();
    virtual Entry* fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0(int);
};

struct Object_vptr_10_base {
    char pad[0x10];
};

class Object_vptr_10 : public Object_vptr_10_base {
public:
    virtual void slot0(int);
};

struct Object {
    char pad[4];
    s32 enabled;
    EntryList entries;
};

struct Item {
    u32 kind;
    char pad0[4];
    u8 flag;
    char pad1[3];
    s32 counter;
};

extern "C" bool fn_27_2C2C18(void*);

extern "C" void fn_27_2C12F4(Object* self, u32 event, s32 decrement) {
    if (event == 0x1388 || (event > 0x1389 && event < 0x1390)) {
        return;
    }

    if (self->enabled == 0) {
        return;
    }

    u32 kind = event;
    s32 mode = *(s32*)((u8*)itManager::getInstance() + 0x50);

    switch (mode) {
    case 3: {
        s32 var;
        if (kind >= 1 && kind <= 0x5B && (kind & 1) == 1) {
            switch (kind - 0x33) {
            case 0:
            case 2:
            case 4:
            case 6:
            case 8:
            case 0x10:
            case 0x12:
            case 0x14:
            case 0x1E:
                var = 0;
                break;
            default:
                var = 1;
                break;
            }
        } else {
            var = 0;
        }

        if (var != 0) {
            kind = (u32)-0x10;
        }
        break;
    }

    case 2: {
        s32 var;
        if (kind >= 0x147 && kind <= 0x187) {
            if (kind == 0x155 || kind == 0x183) {
                var = 0;
            } else {
                var = 1;
            }
        } else {
            var = 0;
        }

        if (var != 0) {
            kind = (u32)-0xF;
        }
        break;
    }
    }

    for (s32 index = 0; index < self->entries.fn_27_7AB50(); ++index) {
        Entry* entry = self->entries.fn_27_7AC18(index);
        Item* item = (Item*)entry->value;

        if (item != 0 && kind == item->kind) {
            if (decrement != 0) {
                if (item->counter > 0) {
                    item->counter--;
                    if (item->counter > 0) {
                        return;
                    }
                }
            }

            if (item->flag != 0) {
                return;
            }

            if (fn_27_2C2C18(item)) {
                if (item != 0) {
                    ((Object_vptr_10*)item)->slot0(1);
                }
                self->entries.fn_27_7B0B0(index);
                return;
            }

            item->flag = 1;
            return;
        }
    }
}
