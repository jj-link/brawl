#pragma force_active on

struct Node {
    void* vtable;
    unsigned short size;
    unsigned short refs;
};

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Node* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80486058[];

extern "C" {
void fn_8027BDFC(void) {
    Node* node = lbl_805A0EB8->alloc(8, 0x16);
    node->size = 8;
    if (node != 0) {
        node->refs = 1;
        node->vtable = lbl_80486058;
    }
}
}
