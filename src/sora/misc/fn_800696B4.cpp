#include <ms/ms_char_writer.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" {
void fn_80070AC8(void*);
void fn_8006CD8C(void*);
void fn_80070D7C(void*, void*);
void fn_80070D6C(void*, int);
void fn_8006B360();

extern char __vt__7Message[];
extern char lbl_804540E0[];
extern float lbl_805A19E8;
extern float lbl_805A19EC;
}

struct Buffer {
    int a, b, c, d, e, f;
    char g;
    char pad19[3];
    char h, i;
    char pad1e[2];
    void* vt;
    int j;
    float k;
    int l;
    char m;
    char pad31[3];
    int n, o;
    char pad3c[8];
    char p;
    char pad45[3];
    unsigned int size;
    unsigned int pos;
    char* data;

    Buffer(unsigned long length, Heaps::HeapType heap) {
        float initial = lbl_805A19EC;
        vt = lbl_804540E0;
        j = 0;
        k = initial;
        l = 0;
        m = 1;
        n = 3;
        o = 0;
        p = 1;
        pos = 0;
        data = (char*)operator new[](length, heap);
        size = length;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        g = 0;
        h = 0;
        i = 0;
        f = 0;
    }
};

extern "C" void* __ct__7MessageFUlQ25Heaps8HeapType(
    void* self, unsigned long size, Heaps::HeapType heap
) {
    char* p = (char*)self;

    fn_80070AC8(self);
    *(void**)(p + 0xa0) = __vt__7Message;
    fn_8006CD8C(p + 0xa4);
    fn_80070D7C(self, p + 0xa4);
    fn_80070D6C(self, 0);
    ((ms::CharWriter*)self)->EnableFixedWidth(true);
    ((ms::CharWriter*)self)->SetFixedWidth(lbl_805A19E8);

    int zero = 0;
    *(int*)(p + 0x1dc) = zero;
    *(int*)(p + 0x1d8) = zero;
    *(Buffer**)(p + 0x1d4) = 0;

    if (size != 0) {
        *(Buffer**)(p + 0x1d4) = new (heap) Buffer(size, heap);
        (*(Buffer**)(p + 0x1d4))->size = size;
        Buffer* q = *(Buffer**)(p + 0x1d4);
        *(Buffer**)(p + 0x1d0) = q;
        *(Buffer**)(p + 0x9c) = q;
        q->pos = 0;
        Buffer* r = *(Buffer**)(p + 0x1d0);
        r->data[r->pos] = 1;
        *(void (**)())(p + 0x1c8) = fn_8006B360;
        *(void (**)())(p + 0x1cc) = fn_8006B360;
    }

    *(char*)(p + 0x1c4) = 1;
    return self;
}
