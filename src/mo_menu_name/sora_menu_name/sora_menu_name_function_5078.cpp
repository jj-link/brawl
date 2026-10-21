#pragma force_active on

extern "C" char* g_gfPadSystem;

class Node {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f14(int);
    virtual void f15(void*);
};

extern "C" int fn_16_5078(char* self) {
    unsigned char* pad = (unsigned char*)g_gfPadSystem;
    if (!((pad[0x34] >> 6) & 1)) {
        return *(int*)(self + 0x9C);
    }
    if (*(int*)(self + 0x400) >= 4) {
        Node* r31 = *(Node**)(self + 0x94);
        int n;
        while ((n = *(int*)((char*)r31 + 0xE4)) != 0) {
            if (n != 0) {
                r31->f14(n - 1);
            }
        }
        Node* r3 = *(Node**)(self + 0xA8);
        r3->f15(*(void**)(self + 0x94));
        return 2;
    }
    *(int*)(self + 0xA4) = 0xC;
    return 0xB;
}
