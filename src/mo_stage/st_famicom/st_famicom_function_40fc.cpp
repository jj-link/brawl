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

extern "C" {
void* fn_68_2398(void*, const char*);
void* __ct__14snd3DGeneratorFv(void*);
void* memset(void*, int, unsigned long);

extern char lbl_68_data_1208[];
extern const float lbl_68_rodata_88;

void* fn_68_40FC(char* self, const char* name) {
    fn_68_2398(self, name);
    *(void**)(self + 0x3c) = lbl_68_data_1208;
    __ct__14snd3DGeneratorFv(self + 0x1a4);

    *(int*)(self + 0x15c) = 0;
    *(float*)(self + 0x158) = lbl_68_rodata_88;
    *(int*)(self + 0x160) = 0;
    *(char*)(self + 0x164) = 0;
    *(int*)(self + 0x168) = 0;
    *(int*)(self + 0x16c) = 0;
    memset(self + 0x170, 0, 0x1c);

    Component* sub = (Component*)(self + 0xd0);
    *(char*)(self + 0x18c) = 0;
    *(int*)(self + 0x190) = 0;
    *(int*)(self + 0x194) = 0;
    *(int*)(self + 0x198) = 0;
    *(int*)(self + 0x19c) = 0;
    *(int*)(self + 0x1a0) = 0;

    if (!sub)
        return self;

    sub->state = 1;
    sub->set(0, 15);
    sub->flags[1] |= 1;
    sub->flags[1] |= 4;
    return self;
}
}
