#pragma force_active on
struct TestObj {
    virtual int func0();
    virtual int func1();
    virtual int func2();
    virtual int func3();
};

extern "C" bool fn_27_86AD0(TestObj* obj) {
    return obj->func3() == 0;
}
