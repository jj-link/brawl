#pragma force_active on
extern "C" {
extern char lbl_116_data_6960[];
extern char lbl_116_data_2D00[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

class Class_7624 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_101BC();
    virtual void fn_116_11518();
    virtual void fn_116_11510();
    virtual int fn_116_11508(int);
    virtual void fn_116_11500(int, int);
    virtual void fn_116_114F8();
    virtual void fn_116_114F0();
    virtual void fn_116_114E8();
    virtual void fn_116_114E0();
    virtual void fn_116_114D8();
    virtual void fn_116_114D0();
    virtual void fn_116_114C8();
    virtual void fn_116_114C0();
    virtual void fn_116_11470();
    virtual void fn_116_114B8();
    virtual void fn_116_114A8();
    virtual void fn_116_11498();
    virtual void fn_116_11488(int);
};

extern "C" void fn_116_13C10(void*, void* accesser) {
    void* obj = __dynamic_cast(*(void**)((char*)accesser + 8), 0x3C, lbl_116_data_6960, lbl_116_data_2D00, 1);
    int val = (*(Class_7624**)(*(char**)((char*)accesser + 0xd8) + 0x64))->fn_116_11508(0x20000001);
    int divisor = *(int*)(*(char**)((char*)obj + 0x18e8) + 0x10);
    if ((val + 1) % divisor == 0) {
        (*(Class_7624**)(*(char**)((char*)accesser + 0xd8) + 0x64))->fn_116_11488(0x22000000);
    }
    (*(Class_7624**)(*(char**)((char*)accesser + 0xd8) + 0x64))->fn_116_11500(val + 1, 0x20000001);
    obj = *(void**)((char*)obj + 0x18e8);
    int val2 = (*(Class_7624**)(*(char**)((char*)accesser + 0xd8) + 0x64))->fn_116_11508(0x20000000);
    if (val2 >= *(int*)((char*)obj + 0xc)) {
        (*(Class_7624**)(*(char**)((char*)accesser + 0xd8) + 0x64))->fn_116_11488(0x22000001);
    }
}