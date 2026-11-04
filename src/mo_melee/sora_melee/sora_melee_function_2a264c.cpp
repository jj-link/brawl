#pragma force_active on
typedef int s32;

extern "C" void fn_27_2A7970(void* self, s32 item, s32 a, s32 b);
extern "C" void fn_27_2ABD04(void* self, s32 a);
extern "C" void fn_27_2C1890(void* root);
extern const float lbl_27_rodata_5D5C;
extern "C" void* memset(void*, int, unsigned int);

class ItemList {
public:
    virtual void v2();
    virtual s32* at(s32 index);
    virtual void v4();
    virtual s32 size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void clear();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void remove(s32 index);
    char storage[0x34];
};

struct Mgr {
    char pad1[0x6d8];
    ItemList list1;
    char pad2[0x9e0 - 0x6d8 - 0x38];
    ItemList list2;
    char pad3[0xce8 - 0x9e0 - 0x38];
    ItemList list3;
    char pad4[0x10c8 - 0xce8 - 0x38];
    ItemList list4;
    char pad5[0x14b8 - 0x10c8 - 0x38];
    void* root;
    char pad6[0x20 - 8];
};

#define I(o) (*(s32*)((char*)self + (o)))
#define B(o) (*(unsigned char*)((char*)self + (o)))
#define F(o) (*(float*)((char*)self + (o)))
#define A(o) ((char*)self + (o))

extern "C" void fn_27_2A264C(Mgr* self) {
    s32 i = 0;
    while (i < self->list2.size()) {
        s32* p = self->list2.at(i);
        if (*p != 0) {
            self->list2.remove(i);
            fn_27_2A7970(self, *p, 0, 0);
            i--;
        }
        i++;
    }
    i = 0;
    while (i < self->list1.size()) {
        s32* p = self->list1.at(i);
        if (*p != 0) {
            self->list1.remove(i);
            fn_27_2A7970(self, *p, 0, 1);
            i--;
        }
        i++;
    }
    self->list1.clear();
    i = 0;
    while (i < self->list3.size()) {
        s32* p = self->list3.at(i);
        if (*p != 0) {
            self->list3.remove(i);
            fn_27_2A7970(self, *p, 1, 0);
            i--;
        }
        i++;
    }
    self->list3.clear();
    B(0xff4) = 0;
    fn_27_2ABD04(self, 1);
    I(0x10c0) = 0;
    I(0x10bc) = -1;
    I(0x10c4) = 0;
    I(0x1160) = 0;
    I(0x1164) = 0;
    I(0x1168) = 0;
    self->list4.clear();
    I(0x116c) = 0;
    if (I(0x14b8) != 0) {
        fn_27_2C1890(*(void**)A(0x14b8));
    }
    I(0x4c) = 3;
    I(0xc0) = 0;
    I(0xc4) = 0;
    I(0xff0) = 0;
    I(0x147c) = 0;
    I(0x1480) = -1;
    F(0x1484) = lbl_27_rodata_5D5C;
    I(0x1488) = 0;
    I(0x148c) = -1;
    I(0x1490) = -1;
    I(0x1494) = 0;
    I(0x1498) = 0;
    B(0x149c) = 0;
    I(0x50) = 0;
    I(0x54) = 0xff;
    B(0xbc) = 1;
    memset(A(0x11b4), 0, 0x2c8);
    memset(A(0xff8), 0, 0x10);
    memset(A(0x1009), 0, 0xb2);
    B(0x1008) = 0;
}
