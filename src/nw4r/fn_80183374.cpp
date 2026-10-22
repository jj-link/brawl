#pragma force_active on
extern "C" void* fn_8018BC7C(void* self, unsigned int key);

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int, int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20(int, int, int);
};

extern "C" void fn_80183374(char* self, int arg1, int arg2, int arg3) {
    int* cur;
    char* p = (char*)fn_8018BC7C(self + 0x1c, arg1);
    if (p != 0) {
        p[0xe] = (char)(arg2 == 0);
    }
    VObj* o = *(VObj**)(self + 0x28);
    if (o != 0) {
        o->v7(arg1, arg2);
    }
    if (arg3 != 0) {
        char* head = self + 0x14;
        cur = *(int**)head;
        while (cur != (int*)head) {
            VObj* obj = (VObj*)((char*)cur - 4);
            obj->v20(arg1, arg2, arg3);
            cur = (int*)*cur;
        }
    }
}
