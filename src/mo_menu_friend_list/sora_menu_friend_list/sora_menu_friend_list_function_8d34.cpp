#pragma force_active on
extern "C" {
extern char lbl_14_data_584[];
extern float lbl_14_rodata_518;
extern int lbl_805A0434;

void fn_14_15E8(void* self, int v);
void fn_14_2498(void* self, int v);
void fn_14_37C8(void* self, int v);
void fn_14_3EC();
void fn_8006BAB0(char* out, char* src, int a, int b);
int fn_8006CEEC(char* p, int n);
int fn_8014B864(int x);
void printf__5MuMsgFUlPCce(void* msg, unsigned long idx, const char* fmt, ...);
unsigned long strlen(const char* s);
char* strcpy(char* d, const char* s);
}

class MuObj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual float s6();
};

extern "C" int fn_14_8D34(char* self) {
    char buf[0x60];
    char* d;
    int flag;

    if (*(unsigned char*)(self + 0x40) == 0) {
        fn_14_3EC();
        flag = fn_8014B864(lbl_805A0434);
    } else {
        flag = 1;
    }

    MuObj* obj = *(MuObj**)(*(char**)(*(char**)(self + 0x4c) + 0x14) + 0xc);
    float f = obj->s6();

    if (f >= lbl_14_rodata_518) {
        d = lbl_14_data_584;
        int i = 0;
        do {
            if (fn_8006CEEC(d, 0x7fff) > 10) {
                buf[0] = 0;
                fn_8006BAB0(buf, d, 0, 10);
                int len = (int)strlen(buf);
                buf[len] = 10;
                strcpy(buf + len + 1, d + len);
            } else {
                strcpy(buf, d);
            }
            printf__5MuMsgFUlPCce(*(void**)(self + 0x24cc), i + 0x26, buf);
            i++;
        } while (i < 4);
        fn_14_2498(self, 0);
    }

    if (flag != 0 && *(int*)(self + 0x2b0) != 4) {
        fn_14_15E8(self, *(int*)(self + 0xc4));
        fn_14_37C8(self, 0);
        return 2;
    }
    return *(int*)(self + 0x24c4);
}
