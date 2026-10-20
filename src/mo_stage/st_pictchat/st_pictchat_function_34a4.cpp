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
void fn_73_2C64(void*);
extern char lbl_73_data_3A68[];
extern char lbl_73_data_10B8[];
extern const float lbl_73_rodata_78;
char* strcpy(char*, const char*);

void* fn_73_34A4(char* a) {
    fn_73_2C64(a);
    *(void**)(a + 0x3c) = lbl_73_data_3A68;
    *(int*)(a + 0x158) = 0;
    *(int*)(a + 0x15c) = 0;
    *(char*)(a + 0x160) = 0;
    *(int*)(a + 0x164) = 0;
    *(char*)(a + 0x168) = 0;
    *(char*)(a + 0x169) = 8;
    *(int*)(a + 0x16c) = 0;
    *(int*)(a + 0x170) = 0;
    *(int*)(a + 0x174) = 0;
    *(char*)(a + 0x178) = 0;
    *(char*)(a + 0x179) = 0;
    strcpy(a + 0x17a, lbl_73_data_10B8);
    *(int*)(a + 0x27c) = 0;
    *(char*)(a + 0x280) = 0;
    *(char*)(a + 0x281) = 0;
    *(int*)(a + 0x284) = 0;
    *(char*)(a + 0x288) = 3;
    *(float*)(a + 0x28c) = lbl_73_rodata_78;
    *(float*)(a + 0x290) = lbl_73_rodata_78;

    char* p = a + 0xd0;
    if (!p)
        return a;

    Component* c = (Component*)p;
    c->state = 1;
    c->set(0, 15);
    *(unsigned int*)(c->ptr + 4) |= 1;
    return a;
}
}
