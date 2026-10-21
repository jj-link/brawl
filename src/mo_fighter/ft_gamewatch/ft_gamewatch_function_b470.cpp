#pragma force_active on
extern "C" void fn_27_131CD0(void*, int, int, int);

struct V1 {
    virtual ~V1() = 0;
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual int getStatus() = 0; // 0x48
};

struct V2 {
    virtual ~V2() = 0;
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void offFlag(int) = 0; // 0x54
};

extern "C" void fn_107_B470(void* a0, int a1, int a2, void* a3) {
    fn_27_131CD0(a0, a1, a2, reinterpret_cast<int>(a3));
    if (a1 != 2) {
        V1* o1 = *reinterpret_cast<V1**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(a3) + 0xd8)) + 0x70);
        if (o1->getStatus() != 0x114) {
            void* base = *reinterpret_cast<void**>(reinterpret_cast<char*>(a0) + 0x60);
            V2* o2 = *reinterpret_cast<V2**>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(base) + 0xd8)) + 0x64);
            o2->offFlag(0x1200003e);
        }
    }
}
