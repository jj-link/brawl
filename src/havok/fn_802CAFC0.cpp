#pragma force_active on

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* entry, int off);
};

extern "C" void fn_802CAFC0(unsigned char* arg0, unsigned char* arg1, int arg2) {
    int n = arg2;
    unsigned char* p = arg1;
    while (--n >= 0) {
        int idx = *(signed char*)(*(unsigned char**)p + 4);
        int idx2 = *(signed char*)(*(unsigned char**)(p + 4) + 4);
        int off = idx << 5;
        Sub* obj = *(Sub**)(arg0 + off + idx2 * 4);
        obj->v3(p, off);
        p += 8;
    }
}
