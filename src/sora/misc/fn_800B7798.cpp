#pragma force_active on

struct MuFrameNode {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(float);
    virtual float vf6(void*, float);
};

struct MuFrame {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(int, int);
};

struct MuNode {
    char pad[0xc];
    MuFrameNode* frameNode;
};

struct MuObject {
    char pad[0x10];
    MuFrame* frame;
    MuNode* node;
    void setFrameNode(float f);
};

void MuObject::setFrameNode(float f) {
    if (this->node->frameNode->vf6(this->node, f) != f) {
        MuFrame* frame = this->frame;
        frame->vf6(2, 0);
        frame->vf6(5, 0);
    }
    this->node->frameNode->vf5(f);
}
