#pragma force_active on
extern "C" {
int sprintf(char*, const char*, ...);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setLoop__16gfModelAnimationFd(void*, int);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;
extern unsigned char lbl_8059E3E8[0x8];
}

struct VtBase {
    char _[0x3c];
};

class Derived : public VtBase {
public:
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual float v28();
    virtual void v29();
    virtual void v30();
};

extern "C" void fn_800F6594(Derived* self) {
    char buf[0x40];
    char* s = (char*)self;
    char* a = *(char**)(s + 0x9C);
    char* b = *(char**)(a + 0x8);
    int off = *(int*)(b + 0x3C);
    char* p = off != 0 ? b + off : 0;
    sprintf(buf, (const char*)lbl_8059E3E8, p, 3);
    changeAnimN__8MuObjectFPCc(*(void**)(s + 0x9C), buf);
    setLoop__16gfModelAnimationFd(*(void**)(*(char**)(s + 0x9C) + 0x14), 0);
    float r = self->v28();
    setUpdateRate__16gfModelAnimationFf(*(void**)(*(char**)(s + 0x9C) + 0x14), r);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0xEA, -1, 0, 0, -1);
}
