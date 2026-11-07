#pragma force_active on

struct Component {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void set(int, int);
    virtual void init();
    unsigned int* flags;
    int state;
};

extern "C" void fn_63_2B6C(void*);
extern "C" void* memset(void*, int, unsigned long);
extern "C" char lbl_63_data_2A00[];
extern "C" const float lbl_63_rodata_A8;

extern "C" void* fn_63_642C(char* self) {
    fn_63_2B6C(self);
    *(void**)(self + 0x3c) = lbl_63_data_2A00;
    *(int*)(self + 0x174) = 0;
    *(char*)(self + 0x178) = 4;
    memset(self + 0x180, 0, 0x50);
    memset(self + 0x1d4, 0, 0x30);
    memset(self + 0x204, 0, 0x30);
    memset(self + 0x234, 0, 0xc);
    *(int*)(self + 0x240) = 0;
    *(float*)(self + 0x244) = lbl_63_rodata_A8;
    *(float*)(self + 0x248) = lbl_63_rodata_A8;
    *(float*)(self + 0x24c) = lbl_63_rodata_A8;
    *(float*)(self + 0x250) = lbl_63_rodata_A8;
    *(float*)(self + 0x254) = lbl_63_rodata_A8;
    *(float*)(self + 0x258) = lbl_63_rodata_A8;
    *(float*)(self + 0x25c) = lbl_63_rodata_A8;
    *(float*)(self + 0x260) = lbl_63_rodata_A8;
    *(float*)(self + 0x264) = lbl_63_rodata_A8;
    *(float*)(self + 0x268) = lbl_63_rodata_A8;
    *(float*)(self + 0x26c) = lbl_63_rodata_A8;
    *(float*)(self + 0x270) = lbl_63_rodata_A8;
    *(char*)(self + 0x274) = 0;
    *(int*)(self + 0x278) = -1;
    *(char*)(self + 0x27c) = 0;
    *(char*)(self + 0x27d) = 0;
    *(char*)(self + 0x27e) = 0;
    *(int*)(self + 0x280) = 0;
    *(int*)(self + 0x284) = 0;
    *(int*)(self + 0x288) = 0;
    *(int*)(self + 0x28c) = 0;
    *(int*)(self + 0x290) = 0;
    *(int*)(self + 0x294) = -1;
    *(int*)(self + 0x298) = -1;
    *(int*)(self + 0x29c) = -1;
    *(int*)(self + 0x2a0) = -1;
    Component* c = (Component*)(self + 0xd0);
    if (!c) return self;
    c->init();
    c->state = 2;
    c->set(0, 15);
    c->flags[1] |= 4;
    c->flags[0x84 / 4] |= 1;
    c->flags[0x84 / 4] |= 2;
    c->flags[0x84 / 4] |= 4;
    return self;
}
