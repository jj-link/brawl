#pragma force_active on
struct soObjHead {
    unsigned int head;
};

struct soVirtObj : public soObjHead {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(unsigned int arg);
    virtual void vf5();
    virtual void vf6();
};

struct soNode {
    soNode* next;
    unsigned int pad[5];
    soVirtObj* objA;
    void* objB;
};

extern "C" void fn_27_263A48(void* self, unsigned int arg);

extern "C" void fn_27_232CD0(unsigned char* self, unsigned int arg) {
    soNode* node = *(soNode**)(self + 0x40);
    for (; node != 0; node = node->next) {
        if (node->objA != 0) {
            node->objA->vf4(arg);
        } else if (node->objB != 0) {
            fn_27_263A48(node->objB, arg);
        }
    }
}
