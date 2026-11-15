#pragma force_active on
#define V1(n) virtual void d##n();
struct Pad8 { char p[8]; };
struct MObj : Pad8 { V1(0) V1(1) V1(2) V1(3) virtual void* get(); };
struct ValueNode {
    virtual void v0();
    virtual void v1();
    virtual int getValue();
};
struct ChainNode {
    virtual void c0();
    virtual void c1();
    virtual ValueNode* getNode();
};
extern "C" {
extern unsigned char lbl_104_data_2628[], lbl_104_data_2EDC[];
extern unsigned char lbl_104_data_2DC8[], lbl_104_data_2DF4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_33BEF4(void*, int, int, int, int);

int fn_104_1B6E8(void* self, char* arg) {
    void* fighter = __dynamic_cast(*(void**)(arg + 8), 0x3c, lbl_104_data_2628, lbl_104_data_2EDC, short(1));
    char** acc = *(char***)(arg + 0xd8);
    MObj* m = (MObj*)acc[0];
    int team = *(int*)(*(char**)(arg + 8) + 0x28);
    fn_27_33BEF4(self, team,
        fn_27_14DB04(__dynamic_cast(m->get(), 0, lbl_104_data_2DC8, lbl_104_data_2DF4, short(1))),
        ((ChainNode*)acc[6])->getNode()->getValue(), 0x39);
    return 1;
}
}
