#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned int, unsigned int);
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(unsigned int, void*);
};

extern "C" void fn_27_155DC8(void* unused, void* arg1, void* arg2) {
    (*(Inner**)(*(unsigned char**)((unsigned char*)arg1 + 0xd8) + 0x64))->v5(*(unsigned int*)((unsigned char*)arg2 + 0x4), 0x10000015);
    (*(Inner**)(*(unsigned char**)((unsigned char*)arg1 + 0xd8) + 0x64))->v5(*(unsigned int*)((unsigned char*)arg2 + 0x8), 0x10000016);
    (*(Inner**)(*(unsigned char**)((unsigned char*)arg1 + 0xd8) + 0x64))->v5(*(unsigned short*)((unsigned char*)arg2 + 0x2), 0x10000017);
    (*(Outer**)(*(unsigned char**)((unsigned char*)arg1 + 0xd8) + 0x70))->v3(0x93, arg1);
}
