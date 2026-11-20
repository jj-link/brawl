#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct A {
    char pad[15];
    u8 spare : 4;
    u8 f8 : 1;
    u8 f4 : 1;
    u8 f2 : 1;
    u8 f1 : 1;
};

struct B {
    char pad[0x54];
    u8 padflag : 3;
    u8 flag : 1;
    u8 rest : 4;
};

struct C {
    char pad[0x2c];
    u8 flag : 1;
    u8 rest : 7;
};

struct Flags {
    u8 active : 1;
    u8 rest : 7;
};

struct Entry {
    A* a;
    B* b;
    C* c;
    u8 d;
    Flags flags;
};

struct List {
    char pad[0x1a];
    u16 count;
    Entry* entries;
};

struct Rect {
    float a, b, c, d, x, y;
};

struct Self {
    char pad[0x18];
    void* owner;
    List* list;
    char pad2[0x350];
    Rect rect;
};

struct Line {
    float x1, y1, x2, y2;
};

struct Vec {
    float x, y;
};

extern "C" void fn_80111968(C*, Line*, A*, int);
extern "C" int fn_800436E8(Rect*, Line*);
extern "C" int fn_800408C4(Line*, float*, Vec*);
extern "C" int fn_80113F88(Entry*, Entry*);
extern "C" int fn_80114024(Entry*, Entry*);
extern "C" int fn_80113EC0(Entry*, Entry*);
extern "C" int fn_80113DF8(Entry*, Entry*);
extern "C" void fn_80137074(void*, Entry*);
extern "C" void fn_80137298(void*, Entry*);

extern "C" void fn_80125E44(Self* self) {
    Entry* entry;
    unsigned int off;
    Rect* rect;
    unsigned int count;
    unsigned int i;
    Line line;
    Vec point;
    Entry copy;

    copy.a = 0;
    copy.b = 0;
    copy.c = 0;
    copy.d = 0;
    copy.flags.active = 0;

    rect = &self->rect;
    i = 0;
    off = 0;
    float x = rect->x;
    count = self->list->count;

    for (; i < count; off += 16, ++i) {
        entry = (Entry*)((char*)self->list->entries + off);
        copy = *entry;

        int valid = copy.a && copy.b && copy.c;

        int ready;
        if (valid && copy.b->flag && copy.c->flag)
            ready = 1;
        else
            ready = 0;

        if (ready && (*(A**)(void*)&copy)->f1) {
            fn_80111968(entry->c, &line, entry->a, 0);

            if (fn_800436E8(rect, &line)) {
                if (line.x1 < x && x < line.x2 &&
                    fn_800408C4(&line, &rect->x, &point) &&
                    rect->y < point.y && point.y < rect->d &&
                    (!fn_80113F88(entry, &copy) || !copy.a->f8) &&
                    (!fn_80114024(entry, &copy) || !copy.a->f4) &&
                    (!fn_80113EC0(entry, &copy) || !copy.a->f8) &&
                    (!fn_80113DF8(entry, &copy) || !copy.a->f4)) {
                    fn_80137074(self->owner, entry);
                }
            } else if (line.x1 < x && x < line.x2 &&
                       fn_800408C4(&line, &rect->x, &point) &&
                       (point.y < rect->y || rect->d < point.y)) {
                fn_80137298(self->owner, entry);
            }
        }
    }
}
