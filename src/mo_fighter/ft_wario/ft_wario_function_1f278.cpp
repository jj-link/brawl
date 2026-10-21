#pragma force_active on
extern "C" void fn_27_13604C(void* self, void* sender, int arg2, void* arg3);

struct FtObj {
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08();
    virtual void n09();
    virtual void n10();
    virtual void n11();
    virtual void n12();
    virtual void n13();
    virtual void n14();
    virtual void n15();
    virtual void n16();
    virtual void n17();
    virtual void n18(int id, float scale);
    virtual int n19(int id);
};

struct FtMidB {
    unsigned char pad[0x64];
    FtObj* obj;
};

struct FtOuterA {
    unsigned char pad[0xD8];
    FtMidB* mid;
};

extern "C" {
void fn_110_1F278(void* self, void* sender, int arg2, void* arg3) {
    FtOuterA* a = static_cast<FtOuterA*>(arg3);
    FtObj* obj = a->mid->obj;
    if (obj->n19(0x1200003D) != 0) {
        char* s = static_cast<char*>(self);
        void* p1 = *reinterpret_cast<void**>(s + 0xB24C);
        void* p2 = *reinterpret_cast<void**>(static_cast<char*>(p1) + 0x8C);
        float scale = *reinterpret_cast<float*>(static_cast<char*>(sender) + 4) *
                      *reinterpret_cast<float*>(static_cast<char*>(p2) + 8);
        obj->n18(0x11000013, scale);
    }
    fn_27_13604C(self, sender, arg2, arg3);
}
}
