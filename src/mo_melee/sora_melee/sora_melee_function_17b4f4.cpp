#pragma force_active on
extern "C" {
void fn_27_17C5E0(void* a, void* b, void* c);
void fn_27_17BE54(void* a, void* b, void* c);
void fn_27_17CCEC(void* a, void* b, void* c);
void fn_27_17DA08(void* a, void* b, void* c);

class SubObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int target(int a, int b);
};

void fn_27_17B4F4(int arg0, void* arg1, int arg2) {
    char* ctx = *(char**)((char*)arg1 + 0xD8);
    SubObj* obj = *(SubObj**)(ctx + 0x64);
    int result = obj->target(0x20000000, arg2);
    switch (result) {
        case 0x2c:
            fn_27_17C5E0((void*)arg0, arg1, (void*)arg2);
            break;
        case 0x3d:
            fn_27_17BE54((void*)arg0, arg1, (void*)arg2);
            break;
        case 0x18:
            fn_27_17CCEC((void*)arg0, arg1, (void*)arg2);
            break;
        case 0xd:
            fn_27_17DA08((void*)arg0, arg1, (void*)arg2);
            break;
    }
}
}