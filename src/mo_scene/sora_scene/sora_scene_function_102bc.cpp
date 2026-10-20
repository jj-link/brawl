#pragma force_active on
typedef unsigned long u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_4CF0[];
extern "C" char lbl_1_data_4D20[];

template<class T, int H>
struct adList {
    static void* __vt[];
};

struct SceneObject {
    const char* name;
    void* vtable;
    u32 state;
    u32 unused;
    void* listVtable;
    u32 start;
    u32 end;
    u32 current;
    u32 count;
};

extern "C" SceneObject* fn_1_102BC() {
    SceneObject* p = static_cast<SceneObject*>(
        __nw__FUlQ25Heaps8HeapType(0x24, 2));
    if (p) {
        p->name = lbl_1_data_4CF0;
        p->vtable = lbl_1_data_4D20;
        p->state = 0;
        p->listVtable = adList<unsigned long, 42>::__vt;
        p->start = 0;
        p->end = 0;
        p->current = 0;
        p->count = 0;
    }
    return p;
}
