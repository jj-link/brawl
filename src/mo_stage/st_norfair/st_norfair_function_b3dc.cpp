#pragma force_active on

struct Component {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);

    unsigned int* flags;
    int state;
};

struct ModeWord {
    unsigned int mode : 3;
    unsigned int rest : 29;
};

extern "C" {
void* fn_54_2C48(void*, const char*);
void* __ct__14snd3DGeneratorFv(void*);
void fn_8009ED40(void*, int, int);
void fn_8009F1FC(void*);
void* memset(void*, int, unsigned long);

extern char lbl_54_data_2584[];
extern const float lbl_54_rodata_C8;
extern const float lbl_54_rodata_CC;

void* fn_54_B3DC(char* self, const char* name) {
    fn_54_2C48(self, name);
    *(void**)(self + 0x3c) = lbl_54_data_2584;
    __ct__14snd3DGeneratorFv(self + 0x18c);
    fn_8009ED40(self + 0x194, 0, 1);

    *(int*)(self + 0x15c) = 0;
    *(int*)(self + 0x160) = 0;
    *(int*)(self + 0x164) = 0;
    *(int*)(self + 0x168) = 0;
    *(int*)(self + 0x16c) = 0;
    memset(self + 0x170, 0, 0x10);

    *(float*)(self + 0x180) = lbl_54_rodata_C8;
    *(char*)(self + 0x184) = 1;
    *(float*)(self + 0x188) = lbl_54_rodata_CC;

    Component* sub = (Component*)(self + 0xd0);
    if (!sub)
        return self;

    sub->state = 1;
    sub->set(0, 15);
    sub->flags[1] |= 1;
    sub->flags[1] |= 4;

    fn_8009F1FC(self + 0x194);
    ((ModeWord*)(self + 0x19c))->mode = 1;
    *(int*)(self + 0x218) = -1;
    *(int*)(self + 0x21c) = -1;
    *(int*)(self + 0x220) = -1;
    *(int*)(self + 0x224) = -1;
    return self;
}
}
