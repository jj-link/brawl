#pragma force_active on

extern "C" {
void fn_14_3424(void* self, int a);
void fn_14_2498(void* self, int value);
void fn_14_37C8(void* self, int a);
int fn_14_3D28(int mode, int value, int index);
void fn_14_3D74(void* self, int a);
char* fn_14_F40(char* base, char* dst, int idx);
void fn_8006BAB0(char* dst, char* src, int a, int b);
int fn_8006CEEC(char* s, int n);
int fn_800B5854(void* p, int a, int b, int c, int d);
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
char* strcpy(char* dst, const char* src);
int strlen(const char* s);
}

struct VFace {
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
    virtual void v13(int a, int b);
};

extern "C" void fn_14_878C(char* self) {
    char name[0x54];
    char buf[0x54];

    fn_14_3424(self, 2);
    VFace* o = *(VFace**)(self + 0x204);
    char* t30 = *(char**)(self + 0xC4);
    o->v13(*(int*)((char*)o + 0xE4), *(int*)(t30 + 0x10));
    fn_800B5854(t30, 0, 3, 1, 0);

    for (int i = 0; i < 4; i++) {
        fn_14_F40(self, name, i);
        if (fn_8006CEEC(name, 0x7FFF) > 0xA) {
            buf[0] = 0;
            fn_8006BAB0(buf, name, 0, 0xA);
            int len = strlen(buf);
            char* p = buf;
            p += len;
            *p = 0xA;
            strcpy(p + 1, name + len);
        } else {
            strcpy(buf, name);
        }
        printf__5MuMsgFUlPCce(*(void**)(self + 0x24CC), i + 0x26, buf);
    }

    fn_14_2498(self, 1);
    VFace* o2 = *(VFace**)(self + 0x204);
    o2->v13(*(int*)((char*)o2 + 0xE4), *(int*)(self + 0x1E8));
    fn_800B5854(*(void**)(self + 0xC0), 8, 0x10, 1, 0);
    fn_800B5854(*(void**)(self + 0x8C), 0, 3, 1, 0);
    *(int*)(self + 0x2510) = 0;
    *(int*)(self + 0x2514) = 0;
    *(int*)(self + 0x2518) = 0;
    fn_14_3D74(self, fn_14_3D28(0, 0, 0));
    fn_14_37C8(self, 7);
}
