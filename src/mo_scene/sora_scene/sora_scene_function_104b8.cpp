#pragma force_active on
extern "C" void __dl__FPv(void*);

struct Cnt {
    virtual unsigned int vft8();
    virtual void vftC();
    virtual void* vft10();
    virtual void vft14();
    virtual void vft18();
    virtual void vft1C();
    virtual void* vft20();
    void* m4;
    void* m8;
    void* mC;
    void* m10;
};

extern "C" void fn_1_104B8(Cnt* cnt) {
    unsigned int count = cnt->vft8();
    cnt->vftC();
    for (unsigned int i = 0; i < count; i++) {
        void* p = cnt->vft10();
        cnt->vft20();
        if (p != 0) {
            __dl__FPv(p);
        }
    }
    cnt->m4 = 0;
    cnt->m8 = 0;
    cnt->mC = 0;
    cnt->m10 = 0;
}
