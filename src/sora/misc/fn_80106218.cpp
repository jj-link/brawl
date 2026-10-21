#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
unsigned long getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(int);
char* strcat(char*, const char*);
extern char lbl_8059E5E8[8];
}

namespace Heaps {
enum HeapType { Heap = 0x2A };
}

void* operator new(unsigned long, Heaps::HeapType);
inline void* operator new(unsigned long, void* p) { return p; }

struct Entry {
    unsigned short a, b;
    int c, d, e, f, g;
    char name[0x84];
    void* buffer;

    Entry() {
        a = 0;
        b = 0;
        c = 0;
        d = -1;
        e = 0;
        f = 0;
        g = 0;
        name[0] = 0;
        strcat(name, lbl_8059E5E8);

        int heap = 0x29;
        if (getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(0x29) < 0x400000)
            heap = 0x2B;
        buffer = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(heap, 0x400000);
    }
};

struct Manager {
    int a;
    int count;
    Entry* entries;
    int d;

    Manager(int arg, int n) {
        a = arg;
        count = n;
        entries = (Entry*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2A, n * 0xA0);
        d = 0;
        for (int i = 0; i < count; ++i)
            new (entries + i) Entry;
    }
};

extern Manager* lbl_805A0318;

extern "C" Manager* fn_80106218(int a, int count) {
    Manager* obj = new (Heaps::Heap) Manager(a, count);
    lbl_805A0318 = obj;
    return obj;
}
