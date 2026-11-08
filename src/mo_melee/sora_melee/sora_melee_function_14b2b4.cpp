#pragma force_active on
#include <types.h>
#include <ft/ft_manager.h>
#include <ft/ft_owner.h>
extern "C" s32 fn_27_8C064(u32,u32,u32);
extern "C" s32 fn_27_112BB0(void*);
extern "C" void* fn_27_112BE0(void*);
extern "C" u8 fn_27_10B118(void*, s32);
extern "C" u32 fn_27_145598(void*,s32);
extern "C" u32 fn_27_14DF14(void*,s32,s32);
extern s32 lbl_27_bss_1B18;
extern u32 lbl_27_bss_466C[3];
class VFunc18 { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual s32 call(u32); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual s32 call44(s32,s32,s32); };
struct VBase { char pad[0x3C]; };
class VFuncA8 : public VBase { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28(); virtual void a29(); virtual void a30(); virtual void a31(); virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35(); virtual void a36(); virtual void a37(); virtual void a38(); virtual void a39(); virtual s32 call(); };
extern "C" s32 fn_27_14B2B4(void* unused, void* self, s32 command, s32 extra) {
 if(command<=0x59D7) return fn_27_8C064((u32)unused,(u32)self,(u32)command);
 if(command>0x5A84) { if(command<0x5A8A) {
 VFunc18* iface=*(VFunc18**)(*(char**)((char*)self+0xD8)+0x64); s32 value=iface->call(0x10000000);
 switch(command) {
 case 0x5A86: return fn_27_112BB0(g_ftManager->getOwner(value));
 case 0x5A87: return (s32)fn_27_112BE0(g_ftManager->getOwner(value));
 case 0x5A88: { ftManager* manager=g_ftManager; u32 flag=(*(u8*)((char*)manager+0x6E)>>4)&1; u32 result=(0-flag)|flag; result>>=31; if(result==1) return (u8)fn_27_10B118(manager,value); return 0; }
 case 0x5A89: { ftManager* manager=g_ftManager; s32 flag=0; if(*(u8*)((char*)manager+0x68)==0&&*(u8*)((char*)manager+0x6A)==1) flag=1; if(flag!=0) return manager->getOwner(value)->getStockCount(); return -1; }
 }
 } else { VFuncA8* iface=*(VFuncA8**)((char*)self+8); return fn_27_14DF14(lbl_27_bss_466C,iface->call(),command-0x5A8C); }
 } else if(command<0x59F5) { VFunc18* iface=*(VFunc18**)(*(char**)((char*)self+0xD8)+0xC4); return iface->call44(lbl_27_bss_1B18,command,extra); }
 else return fn_27_145598(&g_ftCommonDataAccesser,lbl_27_bss_1B18);
 return 0;
}