#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_4FAB4(void*);
extern "C" void fn_27_4FF88(void*, void*, int);
extern "C" void* fn_8015C1B0(void*, void*);
extern void* lbl_27_bss_B8;
extern const float lbl_27_rodata_47C;
extern const float lbl_27_rodata_480;

struct ListHead {
    void* first;
    void* last;
};

struct Entry {
    char pad[0x1c];
    ListHead m_list;
    char pad2[0x34];
    float f58, f5c, f60, f64, f68, f6c;
};

class Array {
public:
    virtual void* m0();
    virtual Entry* at(int);
    virtual void* m2();
    virtual int size();
};

struct NodeBase {
    char pad[0x24];
    unsigned char type;
    char pad2[0xb];
};

class Node : public NodeBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void update(float*);
};

struct Self {
    int field0;
    char pad[4];
    Array* entries;
};

extern "C" void fn_27_36A8C(Self* self) {
    if (lbl_27_bss_B8 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x1508, 2);
        if (p != 0) {
            p = fn_27_4FAB4(p);
        }
        lbl_27_bss_B8 = p;
    }
    fn_27_4FF88(lbl_27_bss_B8, self, self->field0);
    int count = self->entries->size();
    for (int i = 0; i < count; i++) {
        Node* node = 0;
        Entry* entry = self->entries->at(i);
        entry->f60 = lbl_27_rodata_47C;
        float* p58 = &entry->f58;
        entry->f5c = lbl_27_rodata_47C;
        entry->f58 = lbl_27_rodata_47C;
        entry->f6c = lbl_27_rodata_480;
        entry->f68 = lbl_27_rodata_480;
        entry->f64 = lbl_27_rodata_480;
        Entry* e2 = self->entries->at(i);
        ListHead* list = &e2->m_list;
        while ((node = (Node*)fn_8015C1B0(list, node)) != 0) {
            if (node->type == 1) {
                node->update(p58);
            }
        }
    }
}