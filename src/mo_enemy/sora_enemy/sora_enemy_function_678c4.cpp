#pragma force_active on
extern "C" extern unsigned char lbl_41_data_1E858[];
extern "C" extern unsigned char lbl_41_data_3E50[];
extern "C" void fn_41_2D038(void* self, int idx, short value, void* msg, void* data);

struct VSub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual short f7();
};

extern "C" void* fn_41_678C4(void* self, unsigned char* obj)
{
    int msg[4];
    VSub* sub;
    short result;
    int val;

    *(void**)self = lbl_41_data_1E858;
    val = *(int*)(*(unsigned char**)(obj + 0xD8) + 0xC0);
    msg[0] = 1;
    msg[1] = 0x3B;
    msg[2] = (int)&msg[0];
    msg[3] = val;

    sub = (VSub*)(*(unsigned char**)(*(unsigned char**)(obj + 0xD8) + 0x80) + 8);
    result = sub->f7();

    fn_41_2D038((unsigned char*)self + 4, 0, result, &msg[2], lbl_41_data_3E50);
    return self;
}
