#pragma force_active on
extern "C" {
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void* memset(void*, int, unsigned long);
char* strcpy(char*, const char*);
extern const float lbl_51_rodata_0[];
extern char lbl_51_data_0[];
}

struct Item {
    char pad0[6];
    unsigned char f6;
    char pad7[0x20 - 7];
    float f20, f24, f28, f2c;
    unsigned char f30, f31, f32, f33;
    char name[0x28];
};

#define V1(n) virtual void u##n();
#define V4(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3)
#define V16(n) V4(n##0) V4(n##1) V4(n##2) V4(n##3)

struct Obj {
    char pad[0x3c];
    V16(a) V16(b) V16(c) V16(d) V16(e) V16(f) V16(g) V16(h)
    V4(i) V4(j) V4(k)
    V1(l)
    virtual void fn(int);
    char pad2[0x430 - 0x40];
    Item* items;
};

extern "C" void fn_51_15F0(Obj* self) {
    char* d;
    const float* r;
    r = lbl_51_rodata_0;
    d = lbl_51_data_0;
    Item* a = (Item*)__nwa__FUlQ25Heaps8HeapType(0x114, 0x11);
    self->items = a;
    if (a) {
        memset(a, 0, 0x5c);
        a->f30 = 0x3c; a->f31 = 0; a->f32 = 0; a->f33 = 1;
        strcpy(a->name, d + 0x560);
        self->items->f6 = 0xff;
        a->f20 = r[0]; a->f24 = r[1];
        a->f28 = r[2]; a->f2c = r[3];
        self->fn(0x22);
        a = self->items + 1;
        memset(a, 0, 0x5c);
        a->f30 = 0x3d; a->f31 = 0; a->f32 = 0; a->f33 = 1;
        strcpy(a->name, d + 0x578);
        self->items->f6 = 0xff;
        a->f20 = r[0]; a->f24 = r[1];
        a->f28 = r[2]; a->f2c = r[3];
        self->fn(0x23);
        a = self->items + 2;
        memset(a, 0, 0x5c);
        a->f30 = 0x3c; a->f31 = 0; a->f32 = 0; a->f33 = 1;
        strcpy(a->name, d + 0x590);
        self->items->f6 = 0xff;
        a->f20 = r[0]; a->f24 = r[4];
        a->f28 = r[2]; a->f2c = r[5];
        self->fn(0x24);
    }
}
