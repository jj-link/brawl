#include <ms/ms_message.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern char lbl_804540E0[];
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
        vt = lbl_804540E0;
        j = 0;
        k = 1.0f;
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
bool Message::allocMsgBuf(u32 size, u32 count, HeapType heap) {
    Buffer*** buffers = (Buffer***)((char*)this + 0x1d8);
    *buffers = (Buffer**)gfHeapManager::alloc(heap, count * 4);
    for (int i = 0; i < (int)count; i++) {
        Buffer* p = new (heap) Buffer(size, heap);
        p->size = size;
        (*buffers)[i] = p;
    }
    *(u32*)((char*)this + 0x1dc) = count;
    return true;
}