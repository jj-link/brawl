#pragma force_active on
extern "C" void fn_27_A97AC(void* obj);

class fnFrameObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setFrame(int frame);
    char pad1[0x1E - 4];
    unsigned char m_flag;
    char pad2[0x24 - 0x1F];
    char* m_base;
    char pad3[0x2C - 0x28];
    int m_count;
};

extern "C" void fn_27_A9DE0(fnFrameObj* self) {
    if (self->m_flag == 1) {
        self->setFrame(-2);
        self->m_flag = 0;
    }
    int off;
    int i;
    i = 0;
    off = 0;
    for (; i < self->m_count; i++) {
        fn_27_A97AC(self->m_base + off);
        off += 0x18;
    }
}
