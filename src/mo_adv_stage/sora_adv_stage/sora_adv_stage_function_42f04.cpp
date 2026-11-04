#pragma force_active on
#include <stl/bitset>

extern "C" {
extern char __files[];
extern char lbl_40_data_17D98[];
extern short lbl_40_data_17DC0[];
extern int lbl_40_rodata_A58[42];
int fn_803F86E4(void*, const char*, ...);
void fn_803FC984();
void fn_8006BCA8(char*, const void*);
}

struct BitReference {
    const unsigned int* words;
    unsigned int index;
    BitReference(const unsigned int* w, unsigned int i) : words(w), index(i) {}
    operator bool() const {
        unsigned int i = index;
        if (i >= 51) {
            fn_803F86E4(__files + 0xA0, lbl_40_data_17D98);
            fn_803FC984();
        }
        return (words[i >> 5] & (1 << (i & 31))) != 0;
    }
};
struct Bits {
    unsigned int words[2];
    BitReference operator[](unsigned int i) const { return BitReference(words, i); }
};
typedef unsigned long long Pair;
struct Entry { int a; int used; char pad[12]; };
struct GameData {
    Entry entries[34];
    float value;
    int pad2AC;
    int selected;
    char pad2B4[0x5FC-0x2B4];
    unsigned char kind;
    char pad5FD[0x6CC-0x5FD];
    unsigned int mode;
    char pad6D0[0x4898-0x6D0];
    Bits bits;
    char pad48A0[0x4900-0x48A0];
    Pair pair;
};
struct Save {
    char pad[12];
    unsigned char enabled;
    char padD;
    char name[18];
    GameData data;
};
struct Menu {
    unsigned char enabled:1;
    unsigned char mode:1;
    unsigned char rest:6;
    unsigned char kind;
    char name[21];
    unsigned char list[42];
    unsigned char count;
    short id;
    short selected;
    short mapped;
    int value;
    int pad4C;
    Pair pair;
};
struct IdList { int values[42]; };
extern "C" void fn_40_42F04(Menu* self, short id, Save* save) {
    self->id = id;
    if (!save) {
        self->enabled = false;
        return;
    }
    IdList ids = *(const IdList*)lbl_40_rodata_A58;
    GameData* data = &save->data;
    self->enabled = save->enabled != 0;
    if (self->enabled) {
        self->kind = data->kind;
        self->pair = data->pair;
        int value = (int)data->value;
        self->count = 42;
        self->value = value;
        self->mode = data->mode;
        self->count = 0;
        for (int i=0; i<42; ++i) {
            int kind = ids.values[i];
            bool usable;
            if (i == 26) {
                usable = data->bits[29] || data->bits[31];
                if (!usable) usable = data->bits[33];
            } else {
                usable = kind >= 0;
                if (usable) usable = data->bits[kind];
            }
            if (usable) {
                int other = -1;
                switch (kind) {
                case 15: other = 14; break;
                case 4: other = 3; break;
                }
                bool hasOther = other >= 0;
                if (hasOther) hasOther = data->bits[other];
                if (hasOther) usable = false;
                if (usable) {
                    unsigned char count = self->count;
                    self->list[count] = i;
                    self->count = count + 1;
                }
            }
        }
        fn_8006BCA8(self->name, save->name);
        int selected = 0;
        for (int i=0; i<34; ++i) {
            if (data->entries[i].used) selected = i;
        }
        if (self->mode) selected = data->selected;
        self->selected = selected;
        self->mapped = lbl_40_data_17DC0[(short)selected];
    }
}
