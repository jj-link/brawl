#pragma force_active on
extern "C" {

struct Obj524 {
    unsigned char pad[0x604];
    unsigned char state;
};
struct ItMgr {
    unsigned char pad[0x524];
    Obj524* ptr;
};

struct MeleeObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    unsigned char padX[0x188];
    int unk18C;
};

struct A {
    unsigned char pad[0x20];
    unsigned char flag;
};
struct WeaponMgr : A {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
};

extern ItMgr* lbl_27_bss_6A34;
extern MeleeObj* lbl_27_bss_5B98;
extern char lbl_40_data_1944[];
extern void* lbl_41_bss_30;

ItMgr* getInstance__9itManagerFv(ItMgr*);
void fn_27_2A7D3C(void*);
void* getInstance__9emManagerFv();
void removeEnemyAll__9emManagerFv(void*);
WeaponMgr* getInstance__15emWeaponManagerFv();
int fn_40_B48(char*, ...);

void fn_40_A7C(ItMgr* arg0) {
    if (lbl_27_bss_6A34 != 0) {
        fn_27_2A7D3C(getInstance__9itManagerFv(arg0));
    }
    Obj524* p = arg0->ptr;
    if (p->state != 3 && p->state != 4) {
        if (lbl_41_bss_30 != 0) {
            removeEnemyAll__9emManagerFv(getInstance__9emManagerFv());
        }
        MeleeObj* obj = lbl_27_bss_5B98;
        if (obj != 0) {
            obj->v8();
            obj->unk18C = 0;
            fn_40_B48(lbl_40_data_1944);
        }
        WeaponMgr* mgr = getInstance__15emWeaponManagerFv();
        mgr->w2();
        mgr->flag = 1;
    }
}

}
