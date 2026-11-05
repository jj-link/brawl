#include <types.h>
#pragma force_active on

struct Entry { u16 a, b; s16 nextA, nextB; char pad[8]; };
struct State { char pad[4]; s16 value; char rest[22]; };
extern "C" State lbl_8049E6B8[];

struct Class_8045DD44_base {
    u16 field0, count;
    char pad[8];
    Entry* entries;
    char pad10[0x18];
};
class Class_8045DD44 : public Class_8045DD44_base {
public:
    virtual void fn_801385F0();
    virtual void fn_80138630();
    virtual void fn_80138668();
    virtual void fn_801386A0();
    virtual void fn_80138738();
    virtual void fn_80138CB4();
    virtual void fn_80139220();
    virtual u16 fn_80138ED8(u16, u16);
};

extern "C" void fn_80138CB4(Class_8045DD44* self) {
    int x, y;
    for (int i = 0; i < self->count; ++i) {
        if (self->entries[i].nextA == -1) {
            x = self->entries[i].a;
            y = lbl_8049E6B8[i].value;
            for (int j = 0; j < self->count; ++j) {
                if (i != j) {
                    if (self->fn_80138ED8(x, self->entries[j].a) == 1) {
                        y = (s16)i;
                        self->entries[i].nextA = j;
                        self->entries[j].nextA = i;
                        lbl_8049E6B8[j].value = i;
                    }
                    if (self->fn_80138ED8(x, self->entries[j].b) == 1) {
                        self->entries[i].nextA = j;
                        self->entries[j].nextB = i;
                        lbl_8049E6B8[j].value = y;
                    }
                }
            }
        }
        if (self->entries[i].nextB == -1) {
            x = self->entries[i].b;
            y = lbl_8049E6B8[i].value;
            for (int j = 0; j < self->count; ++j) {
                if (i != j) {
                    if (self->fn_80138ED8(x, self->entries[j].a) == 1) {
                        self->entries[i].nextB = j;
                        self->entries[j].nextA = i;
                        lbl_8049E6B8[j].value = y;
                    }
                    if (self->fn_80138ED8(x, self->entries[j].b) == 1) {
                        y = (s16)i;
                        self->entries[i].nextB = j;
                        self->entries[j].nextB = i;
                        lbl_8049E6B8[j].value = i;
                    }
                }
            }
        }
    }
}