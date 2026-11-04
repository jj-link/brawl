#pragma force_active on
extern "C" {
extern int g_muWifiInterfaceTask;
extern const float lbl_10_rodata_6A8;
extern const unsigned char lbl_10_rodata_768[];
extern char lbl_10_data_BA8[];

void fn_800FD96C(int, int);
int fn_800C9F14(int, int);
unsigned char fn_10_11EA8(void*, void*);
void fn_10_12C40(void*, int, unsigned char, int);
int fn_800B5854(void*, int, int, int, int);
void setFrameVisible__8MuObjectFf(void*, float);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);

class VObj {
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
    virtual void v11(int, int);
    virtual void v12();
    virtual void v13(int);
};

extern "C" void fn_10_19374(char* self, int arg1) {
    char* p;
    const unsigned char* rec = lbl_10_rodata_768 + arg1 * 3;
    unsigned int flag = (rec[0] == 0);
    if (flag != (unsigned char)self[0x424]) {
        if (flag != 0) {
            fn_800FD96C(*(int*)(self + 0x41c), 0);
        } else {
            *(int*)(self + 0x420) = fn_800C9F14(g_muWifiInterfaceTask, *(int*)(self + 0x1b0));
            unsigned char t = fn_10_11EA8(self, self + 0x435);
            self[0x434] = t;
            fn_10_12C40(self, *(int*)(self + 0x420), t, 1);
        }
        self[0x424] = flag;
        if (flag != 0) {
            setFrameVisible__8MuObjectFf(*(void**)(self + 0x144), lbl_10_rodata_6A8);
            printf__5MuMsgFUlPCce(*(void**)(self + 0x40c), 0x1d, lbl_10_data_BA8);
            printf__5MuMsgFUlPCce(*(void**)(self + 0x40c), 0x1e, lbl_10_data_BA8);
        }
    }
    int frame = rec[1];
    setFrameVisible__8MuObjectFf(*(void**)(self + 0x148), (float)frame);
    VObj* obj = *(VObj**)(self + 0xac);
    p = *(char**)(self + 0x14c);
    unsigned char flag2 = rec[2];
    obj->v13(*(int*)(p + 0x10));
    if (flag2 != 0) {
        fn_800B5854(p, flag2 != 1, 0x12, 1, 0);
        VObj* o2 = *(VObj**)(self + 0xac);
        o2->v11(*(int*)((char*)o2 + 0xe4), *(int*)(p + 0x10));
    }
    *(int*)(self + 0x430) = arg1;
}
}
