#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    u32 id;
    void* a;
    void* b;
    u8 byte;
    u8 flag;
};

struct Owner {
    u8 pad[0x7d];
    u8 count;
    u8 pad2[0x164 - 0x7e];
    u32 cur;
    u8 pad3[0x174 - 0x168];
    Entry e[1];
};

struct Seg { u8 d[24]; };

extern "C" void fn_801371D8(Owner*, Entry*);
extern "C" void fn_80111968(void*, Seg*, void*, int);
extern "C" int fn_80041978(int, Seg*);

extern "C" void fn_801373E8(Owner* self, int arg) {
    Seg s;
    u32 i = 0;
    for (;;) {
        if (!(i < self->count)) break;
        int v2 = 0;
        int v1 = 0;
        Entry l;
        {
            Entry* src = (Entry*)((char*)self + i * 0x10 + 0x174);
            l.id = src->id;
            l.a = src->a;
            l.b = src->b;
            l.byte = src->byte;
            l.flag = src->flag;
        }
        if (l.id && l.a) v1 = 1;
        if (v1 && l.b) v2 = 1;
        int en;
        if (v2 && ((((u8*)l.a)[0x54] >> 4) & 1) && ((((u8*)l.b)[0x2C] >> 7) & 1))
            en = 1;
        else
            en = 0;
        if (!en) {
            int v = 0;
            if (l.id && l.a && l.b) v = 1;
            if (v) {
                fn_801371D8(self, &l);
            } else {
                i++;
            }
        } else {
            int same = 0;
            if (l.id == self->cur) same = 1;
            if (same) {
                i++;
            } else {
                fn_80111968(l.b, &s, (void*)l.id, 0);
                if (fn_80041978(arg, &s) == 0)
                    fn_801371D8(self, &l);
                else {
                    i++;
                }
            }
        }
    }
}
