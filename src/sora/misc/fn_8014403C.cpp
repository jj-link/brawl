#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);
extern "C" const float lbl_805A2B50;

struct Entry {
    unsigned char flags : 8;
    unsigned char a;
    unsigned char b;
    unsigned char pad47;
    float value;
    unsigned short c;
    char pad4e[6];
    unsigned short d;
    char pad56[2];
    unsigned int e;
    unsigned int f;
    char buffer[0xe30];
    char padEnd[4];
};

struct Flags {
    unsigned char a : 2;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 2;
    unsigned char e : 1;
    unsigned char f : 1;
};

struct Object {
    char pad0[0x18];
    unsigned int a;
    unsigned int b;
    char pad20[0x14];
    unsigned char c;
    char pad35[9];
    Flags flags;
    char pad3f[5];
    Entry entries[4];
};

extern "C" void fn_8014403C(Object* self) {
    float value = lbl_805A2B50;
    unsigned int i = 0;
    do {
        Entry* entry = &self->entries[(unsigned char)i];
        entry->flags = 0;
        entry->a = 0;
        entry->b = 0;
        entry->value = value;
        entry->c = 0;
        entry->d = 0;
        entry->f = 0;
        entry->e = 0;
        memset(entry->buffer, 0, 0xe30);
        ++i;
    } while (i < 4u);

    char* base = (char*)self;
    char* first = base + 0x3994;
    *(unsigned int*)(base + 0x3988) = 0;
    *(unsigned int*)(base + 0x3984) = 0;
    *(void**)(base + 0x398c) = first;
    *(void**)(base + 0x3998) = first + 0x390;
    *(void**)(base + 0x3d28) = first + 0x720;
    *(void**)(base + 0x40b8) = first + 0xab0;
    *(unsigned int*)(base + 0x4448) = 0;
    self->a = 0;
    self->c = 0;
    self->b = 0;
    self->flags.b = 0;
    self->flags.d = 0;
    self->flags.a = 0;
    self->flags.e = 0;
}
