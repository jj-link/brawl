#pragma force_active on
#pragma opt_propagation off

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
    virtual void call(int, int);
    char pad[0xE4 - 4];
    int fE4;
};

extern "C" {
int isLoadFinishMenuSound__6muMenuFv(void*);
void* fn_80015DB4(void*, int, int, int, unsigned short);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void fn_12_25C(void*, void*, int, void*);
void fn_12_34C(void*, int);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
VObj* fn_1_6424();
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern int g_gfApplication;
extern char lbl_12_data_60[];
extern char lbl_12_data_90[];
extern char lbl_12_data_24[];
extern char lbl_12_rodata_38[];

int fn_12_764(char* self) {
    int ret;
    if (isLoadFinishMenuSound__6muMenuFv(self) == 0) {
        ret = *(int*)(self + 0x44);
        return ret;
    }
    int res = (int)fn_80015DB4(*(void**)(self + 0x12c), 0, 1, 0x14, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(&res);
    *(int*)(self + 0x4c) = res;
    *(int*)(self + 0x54) = (int)fn_80015DB4(*(void**)(self + 0x12c), 0, 1, 0x6E, 0xFFFE);
    fn_12_25C(self, lbl_12_rodata_38, 1, self + 0x4c);
    fn_12_34C(self, *(int*)(self + 0x54));
    endKeepScreen__17gfKeepFrameBufferFv((void*)(g_gfApplication + 0xD0));
    char* t = *(char**)(self + 0x40);
    int r30 = *(int*)(t + 0x10);
    char* m = (char*)getInstance__14gfSceneManagerFv();
    __dynamic_cast(*(void**)(m + 4), 4, lbl_12_data_60, lbl_12_data_90, 0);
    VObj* o = fn_1_6424();
    o->call(o->fE4, r30);

    int p1 = 1;
    p1 *= 100000000;
    int v1 = *(int*)(self + 0x58);
    int a1 = (v1 > -99999999) ? v1 : -99999999;
    printf__5MuMsgFUlPCce(*(void**)(self + 0x50), 0U, lbl_12_data_24, (a1 < p1 - 1) ? a1 : p1 - 1);

    int p2 = 1;
    p2 *= 10000;
    int v2 = *(int*)(self + 0x60);
    int a2 = (v2 > -9999) ? v2 : -9999;
    printf__5MuMsgFUlPCce(*(void**)(self + 0x50), 1U, lbl_12_data_24, (a2 < p2 - 1) ? a2 : p2 - 1);

    int v3 = -*(int*)(self + 0x64);
    int p3 = 1;
    p3 *= 1000;
    int a3 = (v3 > -999) ? v3 : -999;
    printf__5MuMsgFUlPCce(*(void**)(self + 0x50), 2U, lbl_12_data_24, (a3 < p3 - 1) ? a3 : p3 - 1);

    if (*(int*)(self + 0x64) > *(int*)(self + 0x60) || *(unsigned char*)(self + 0x68) != 0) {
        ret = 5;
    } else {
        ret = 1;
    }
    return ret;
}
}
