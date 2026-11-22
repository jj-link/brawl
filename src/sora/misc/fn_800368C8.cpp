#include <gf/gf_pad_system.h>
#include <gf/gf_shutdown_manager.h>
#include <gf/gf_camera.h>
#include <string.h>
#pragma force_active on

extern "C" {
void fn_8003675C(int, int);
void fn_801D6E14(OSAlarm*, int);
unsigned char fn_8020FC24();
void fn_8025BF24(void*);
int fn_801E9BDC();
void fn_801D8690(const char*, int, const char*, ...);

extern char lbl_804232A0[];
extern OSAlarm lbl_80495418[];
extern char HomeBtnIcon[];
extern char lbl_804231E0[];
extern char lbl_804231F0[];
extern const float lbl_805A16A0;
extern const float lbl_805A16A8;
extern const float lbl_805A16AC;
extern const float lbl_805A16B0;
extern const float lbl_805A1678;
}

struct Bits { unsigned char a; unsigned char bits : 5; unsigned char rest : 3; };

struct WideBits { unsigned char a; unsigned char wide : 1; unsigned char rest : 7; };
struct CallbackPair : gfCallBack, gfReturnStatusCallback {};

struct Object {
    int a0;
    void* a4;
    int a8;
    void* ac;
    char a10[0x44];
    float a54;
    float a58;
    int a5c;
    char a60[4];
    float a64;
    float a68;
    int a6c;
    char a70[4];
    float a74;
    float a78;
    int a7c;
    char a80[4];
    float a84;
    float a88;
    int a8c;
    int a90;
    void* a94;
    int a98;
    int a9c;
    char aa0[4];
    float aa4;
    float aa8;
    int aac;
    unsigned int ab0;
    int ab4;
    char ab8;
    char ab9[3];
    int abc;
    char ac0;
    char ac1;
};

extern "C" Object* fn_800368C8(Object* arg) {
    int i;
    gfShutdownManager* manager;
    Object* p = arg;
    p->a0 = 0;
    p->ab0 &= 0x00ffffff;
    p->a8 = 0;
    ((Bits*)&p->ab0)->bits = 0;
    p->a4 = lbl_804232A0;
    p->ac = lbl_804232A0 + 16;
    p->a90 = 0;
    p->a98 = 0;
    p->a9c = 0;
    p->aa4 = lbl_805A16A0;
    p->aa8 = lbl_805A16A0;
    p->aac = 0;
    p->ab0 &= 0xfff80fff;
    p->ab4 = 100;
    p->ab8 = 0;
    p->abc = 0;
    p->ac0 = 0;
    p->ac1 = 0;

    g_gfPadSystem->setConnectCallback((int)fn_8003675C);

    for (i = 0; i < 4; ++i) {
        OSCreateAlarm(&lbl_80495418[i]);
        fn_801D6E14(&lbl_80495418[i], i);
    }

    p->a5c = 0;
    p->a54 = lbl_805A1678;
    p->a58 = lbl_805A1678;
    p->a64 = lbl_805A1678;
    p->a68 = lbl_805A1678;
    p->a6c = 0;
    p->a74 = lbl_805A1678;
    p->a78 = lbl_805A1678;
    p->a7c = 0;
    p->a84 = lbl_805A1678;
    p->a88 = lbl_805A1678;
    p->a8c = 0;

    memset(p->a10, 0, 0x40);
    *(int*)((char*)p + 0x2c) = fn_8020FC24();
    *(int*)((char*)p + 0x24) = 0;
    *(int*)((char*)p + 0x28) = 0;
    *(int*)((char*)p + 0x30) = 0;
    *(float*)((char*)p + 0x44) = lbl_805A16A8;
    *(float*)((char*)p + 0x48) = lbl_805A16A0;
    *(float*)((char*)p + 0x40) = lbl_805A16A0;
    *(int*)((char*)p + 0x34) = 0;
    p->a94 = HomeBtnIcon;

    fn_8025BF24(HomeBtnIcon);
    ((WideBits*)&p->ab0)->wide = *(float*)((char*)gfCameraManager::getManager() + 0x738) >
                lbl_805A16AC;

    if (!((WideBits*)&p->ab0)->wide) {
        *(float*)((char*)p + 0x44) = lbl_805A16A0;
        *(float*)((char*)p + 0x48) = lbl_805A16A0;
    } else {
        *(float*)((char*)p + 0x44) = lbl_805A16A8;
        *(float*)((char*)p + 0x48) = lbl_805A16A0;
    }

    switch (fn_801E9BDC()) {
    case 1:
        *(float*)((char*)p + 0x40) = lbl_805A16B0;
        break;
    case 0:
    case 2:
    case 5:
        *(float*)((char*)p + 0x40) = lbl_805A16A0;
        break;
    default:
        fn_801D8690(lbl_804231E0, 0x1c8, lbl_804231F0);
        break;
    }

    manager = &g_gfShutdownManager;
    manager->unk4.add((gfCallBack*)p);
    manager->unk8.add((CallbackPair*)p);
    return p;
}
