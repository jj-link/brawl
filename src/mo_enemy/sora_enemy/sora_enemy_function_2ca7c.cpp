#include <em/em_weapon_manager.h>
#include <em/arman/wnem_proc_arman.h>
#include <em/rayquaza/wnem_proc_rayquaza.h>
#include <em/taboo/wnem_proc_taboo.h>

#pragma force_active on

typedef void (*WeaponProc)();

extern "C" {
void fn_41_2C284(emWeaponManager*, WeaponProc, int);
void fn_41_2CA6C();
void fn_41_4198C();
void fn_41_41E1C();
void fn_41_41A04();
void fn_41_44B80();
void fn_41_44C40();
void fn_41_44D80();
void fn_41_44E90();
void fn_41_44F14();
void fn_41_3DEF8();
void fn_41_3DFB8();
void fn_41_45388();
void fn_41_456F4();
void fn_41_45844();
void fn_41_45918();
void fn_41_45A28();
void fn_41_45C28();
void fn_41_45CD4();
void fn_41_45D84();
void fn_41_45E94();
void fn_41_46474();
void fn_41_46584();
void fn_41_46664();
void fn_41_46740();
void fn_41_46850();
void fn_41_46908();
void fn_41_46B8C();
void fn_41_46CBC();
void fn_41_46DCC();
void fn_41_46DF4();
void fn_41_46FF0();
void fn_41_470B0();
void fn_41_472C0();
void fn_41_4447C();
void fn_41_447BC();
void fn_41_445F4();
void fn_41_4497C();
void fn_41_4C934();
void fn_41_6427C();
void fn_41_64300();
void fn_41_64430();
void fn_41_64560();
void fn_41_645D0();
void fn_41_6B5F4();
void fn_41_6B66C();
void fn_41_5C4C8();
void fn_41_5C580();
void fn_41_5C658();
void fn_41_5C714();
void fn_41_42268();
void fn_41_47FB4();
void fn_41_48038();
void fn_41_48204();
}

extern "C" void fn_41_2CA7C() {
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_2CA6C, 0x0);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_4198C, 0x1);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_41E1C, 0x3);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_41A04, 0x2);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_44B80, 0x4);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_44C40, 0x5);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_44D80, 0x6);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_44E90, 0x7);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_44F14, 0x8);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_3DEF8, 0x9);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_3DFB8, 0xA);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemArmanProc::ArmEnter, 0xB);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemArmanProc::ArmExit, 0xC);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemArmanProc::ArmIdol, 0xD);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemArmanProc::ArmDead, 0xE);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45388, 0x19);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_456F4, 0x1A);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45844, 0x1B);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45918, 0xF);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45A28, 0x10);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45C28, 0x11);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45CD4, 0x12);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45D84, 0x13);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_45E94, 0x14);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46474, 0x15);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46584, 0x16);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46664, 0x17);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46740, 0x18);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46850, 0x28);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46908, 0x29);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46B8C, 0x2A);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46CBC, 0x2B);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46DCC, 0x2C);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46DF4, 0x2D);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_46FF0, 0x2E);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_470B0, 0x2F);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_472C0, 0x30);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_4447C, 0x31);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_447BC, 0x35);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_445F4, 0x32);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_4497C, 0x34);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_4C934, 0x1C);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemRayquazaProc::LightBallFly, 0x1D);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemRayquazaProc::LightBallLanding, 0x1E);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemRayquazaProc::LightBallDisappear, 0x1F);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemTabooProc::BodySplitBulletFly, 0x20);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemTabooProc::BodySplitBulletExplosion, 0x21);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemTabooProc::CometBulletFly, 0x22);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)wnemTabooProc::CometBulletExplosion, 0x23);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_6427C, 0x24);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_64300, 0x25);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_64430, 0x43);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_64560, 0x26);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_645D0, 0x27);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_6B5F4, 0x37);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_6B66C, 0x38);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_5C4C8, 0x39);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_5C580, 0x3A);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_5C658, 0x3B);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_5C714, 0x3C);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_42268, 0x3D);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_47FB4, 0x3E);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_48038, 0x3F);
    fn_41_2C284(emWeaponManager::getInstance(), (WeaponProc)fn_41_48204, 0x40);
}
