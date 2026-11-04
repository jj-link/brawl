#pragma force_active on
extern "C" void fn_14_83C0(void*, unsigned int, float, float);
extern "C" void fn_14_8690(void*, int, int);
extern "C" int fn_800B5854(void*, int, int, int, int);

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void call(void*, int);
    char pad[0xE4 - 4];
    void* arg;
};

extern "C" void fn_14_9484(char* self) {
    Object* obj = *(Object**)(self + 0x204);
    obj->call(obj->arg, *(int*)(self + 0x1EC));
    int v = *(int*)(self + 0x2A0C);
    float f = (float)v;
    *(int*)(self + 0x2A0C) = v;
    *(float*)(self + 0x2A08) = f;
    fn_14_83C0(self, (unsigned int)v ^ 0x80000000u, (float)v, f);
    fn_14_8690(self, *(int*)(self + 0x2A10), *(int*)(self + 0x2A14));
    fn_800B5854(*(void**)(self + 0xC8), 0, 1, 1, 0);
    fn_800B5854(*(void**)(self + 0xC0), 7, 0x10, 1, 0);
}
