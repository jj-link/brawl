#include <mu/menu.h>
#include <string.h>
#pragma force_active on

struct Holder { char pad[0x360]; unsigned char flag; };
struct Object {
    char pad0[0x48];
    unsigned char flags;
    char pad49[0xB];
    unsigned char a, b, c, d;
    char pad58[0x24];
    unsigned char entries[99];
    char padDF;
    int count;
    int index;
    int values[7];
    Holder* holder;
};
extern "C" void fn_8010CCE0(Holder*, int, int, int, float);
extern "C" void fn_8010CA94(Holder*, int, void*);
extern "C" void fn_8010CC80(Holder*);
extern "C" void fn_8010CCA0(Holder*, int);
extern "C" void fn_8010CA20(Holder*, int);

extern "C" int fn_80107A70(Object* self, int unused, int flag) {
    unsigned char temp[100] = {};
    if (!self->holder) return 0x3e;
    for (int i = 0; i < 16; i++) {
        if ((self->flags >> 5) & 1) {
            self->a++;
            if (self->a == 16) {
                self->a = 0;
                self->flags &= ~0x20;
            }
            int kind = muMenu::exchangeGmCharacterKind2MuStockchkind(self->entries[0]);
            float frame = (float)(muMenu::exchangeGmCharacterKind2Something(kind) * 10 + 1);
            if (self->holder)
                fn_8010CCE0(self->holder, self->a, self->values[self->b], self->c, frame);
        }
        if ((self->flags >> 4) & 1) {
            self->d++;
            if (self->d == 10) {
                self->d = 0;
                self->flags &= ~0x10;
                if (self->holder)
                    fn_8010CA94(self->holder, self->count, self->entries);
            }
            if (self->d != 0 && self->d < 10 && self->holder)
                fn_8010CC80(self->holder);
            if (self->holder)
                fn_8010CCA0(self->holder, self->d);
        }
    }
    for (int i = 0; i < self->count; i++) temp[i] = self->entries[i+1];
    memset(self->entries, 0, 99);
    for (int i = 0; i < self->count; i++) self->entries[i] = temp[i];
    if (self->count >= 0 && flag) self->flags |= 0x30;
    if (self->holder && flag) self->holder->flag = 1;
    int result;
    if (self->count <= 0) result = 0x3e;
    else result = self->entries[self->index];
    if (result != 0x3e) {
        self->index++;
        if (self->index >= 99) self->index = 0;
        self->count--;
    }
    if (self->count == 0 && self->holder) fn_8010CA20(self->holder, 0);
    return result;
}