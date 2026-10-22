#pragma force_active on

struct QueryObj {
    virtual void n00();
    virtual void n01();
    virtual void n02();
    virtual void n03();
    virtual void n04();
    virtual void n05();
    virtual void n06();
    virtual void n07();
    virtual void n08(int, float, int, int, float, float, int);
};

extern "C" void* fn_103_9190();
extern "C" void fn_27_135848(void*, int, float, int, int, float, float, int);

extern "C" void fn_103_9368(void* self, int a, float b, int c, int d, float e, float f,
                            int g) {
    if (c != 0) {
        QueryObj* q = (QueryObj*)fn_103_9190();
        q->n08(a, b, c, d, e, f, g);
    }
    fn_27_135848(self, a, b, c, d, e, f, g);
}
