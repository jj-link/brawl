#pragma force_active on
extern "C" {
int fn_113_18B48(void* a);
}

struct FakeStatus {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual int getStatusKind() = 0;
};

extern "C" int fn_113_1A918(void* a, void* b) {
    FakeStatus* status = *(FakeStatus**)((char*)*(void**)((char*)*(void**)((char*)a + 0x60) + 0xd8) + 0x70);
    int kind = status->getStatusKind();
    bool flag;
    switch (kind) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        flag = true;
        break;
    default:
        flag = false;
        break;
    }
    if (flag == 1) return 0;
    if ((*(unsigned int*)((char*)b + 0x6c) & 0x1F) == 0xe) return 0;
    if (fn_113_18B48(a) == 0) {
        if ((*(unsigned int*)((char*)b + 0x6c) & 0x1F) == 5) return 0;
    }
    if (fn_113_18B48(a) == 1) {
        if ((*(unsigned int*)((char*)b + 0x6c) & 0x1F) == 3) return 0;
    }
    if (fn_113_18B48(a) == 2) {
        if ((*(unsigned int*)((char*)b + 0x6c) & 0x1F) == 0x12) return 0;
    }
    return 1;
}
