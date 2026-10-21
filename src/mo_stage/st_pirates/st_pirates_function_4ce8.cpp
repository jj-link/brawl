#pragma force_active on

struct Component {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);
    char* ptr;
    int state;
};

extern "C" {
void* fn_52_35D0(void*, const char*);
void* __ct__14snd3DGeneratorFv(void*);
extern char lbl_52_data_1638[];
extern const float lbl_52_rodata_E8;

void* fn_52_4CE8(char* a, const char* name) {
    fn_52_35D0(a, name);
    *(void**)(a + 0x3c) = lbl_52_data_1638;
    __ct__14snd3DGeneratorFv(a + 0x18c);

    *(char*)(a + 0x150) = 0;
    *(float*)(a + 0x154) = lbl_52_rodata_E8;
    *(char*)(a + 0x160) = 0;
    *(char*)(a + 0x161) = 0;
    *(int*)(a + 0x164) = 0;
    *(int*)(a + 0x168) = 0;
    *(int*)(a + 0x16c) = 0;
    *(int*)(a + 0x170) = 0;
    *(char*)(a + 0x174) = 0;
    *(int*)(a + 0x178) = 0;
    *(char*)(a + 0x17c) = 0x14;
    *(float*)(a + 0x180) = lbl_52_rodata_E8;
    *(char*)(a + 0x184) = 0;
    *(char*)(a + 0x185) = 0;
    *(int*)(a + 0x188) = 0;

    char* p = a + 0xd0;
    if (!p)
        return a;

    Component* c = (Component*)p;
    c->state = 1;
    c->set(0, 15);
    *(unsigned int*)(c->ptr + 4) |= 8;

    *(int*)(a + 0x194) = -1;
    *(char*)(a + 0x198) = 0;
    *(int*)(a + 0x19c) = 0;
    *(char*)(a + 0x1a0) = 0;
    return a;
}
}
