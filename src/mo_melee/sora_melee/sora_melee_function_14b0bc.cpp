
#include <ft/ft_manager.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(int); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual float slot16(int, int, int);
};
struct FtManagerFlags6E {
 char pad[0x6E];
 unsigned char b0:1; unsigned char b1:1; unsigned char b2:1; unsigned char b3:1;
};
extern "C" {
 extern const float lbl_27_rodata_18C0;
 extern int lbl_27_bss_1B18;
 float fn_27_8C02C(void*, void*, int);
 float fn_27_1125C8(void*);
 float fn_27_1125E0(void*);
 float fn_27_112604(void*);
 float fn_27_1125F8(void*);
 float fn_27_112628(void*);
 float fn_27_11261C(void*);
 float fn_27_1120CC(void*);
 float fn_27_112114(void*);
 float fn_27_112BF8(void*);
 float fn_27_145578(void*, int);
}
extern "C" float fn_27_14B0BC(void* p1, void* p2, int p3, int p4) {
 if (p3 <= 0xBB7) return fn_27_8C02C(p1,p2,p3);
 if (p3 > 0xDAC) {
  if (p3 < 0xDB5) {
   Object_vptr_0* m = *(Object_vptr_0**)(*(unsigned char**)((unsigned char*)p2 + 0xd8) + 0x64);
   int id = m->slot4(0x10000000);
   switch (p3) {
   case 0xDAE: return fn_27_1125C8(g_ftManager->getOwner(id));
   case 0xDAF: return fn_27_1125E0(g_ftManager->getOwner(id));
   case 0xDB0: { ftManager* mgr = g_ftManager; float f = fn_27_112604(mgr->getOwner(id)); float r = fn_27_1125F8(mgr->getOwner(id)); r *= f; return r; }
   case 0xDB1: { ftManager* mgr = g_ftManager; float f = fn_27_112628(mgr->getOwner(id)); float r = fn_27_11261C(mgr->getOwner(id)); r *= f; return r; }
   case 0xDB2: { ftManager* mgr = g_ftManager; if ((bool)((FtManagerFlags6E*)mgr)->b3 == true) return fn_27_1120CC(mgr->getOwner(id)); return lbl_27_rodata_18C0; }
   case 0xDB3: return fn_27_112114(g_ftManager->getOwner(id));
   case 0xDB4: return fn_27_112BF8(g_ftManager->getOwner(id));
   }
  }
 } else {
  if (p3 < 0xC2C) {
   unsigned char* mods = *(unsigned char**)((unsigned char*)p2 + 0xd8);
   Object_vptr_0* o = *(Object_vptr_0**)(mods + 0xc4);
   return o->slot16(lbl_27_bss_1B18, p3, p4);
  }
  return fn_27_145578(&g_ftCommonDataAccesser, lbl_27_bss_1B18);
 }
 return lbl_27_rodata_18C0;
}