#pragma force_active on
namespace Heaps {
enum HeapType { HEAP_DEFAULT = 0 };
}

class gmSysSave {
public:
    void *create(Heaps::HeapType type);
};

extern "C" void *__nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void **g_GameGlobal;
extern char lbl_8042E8D8[];
extern gmSysSave *lbl_8059CE48;
extern void *lbl_805A00FC;

void *gmSysSave::create(Heaps::HeapType type) {
    unsigned char *gg = (unsigned char *)*g_GameGlobal;
    gg[0x28] |= 0x20;
    lbl_8059CE48 = this;
    int *p = (int *)__nw__FUlQ25Heaps8HeapType(0x14, (int)this);
    if (p != 0) {
        p[0] = 0;
        p[1] = (int)lbl_8042E8D8;
        p[2] = -1;
        p[3] = 0;
        ((unsigned char *)p)[0x10] = 0;
    }
    lbl_805A00FC = (void *)p;
    p[2] = 0;
    p[3] = 0;
    return lbl_805A00FC;
}
