#include <types.h>
#include <it/it_manager.h>
#include <so/so_archive_db.h>
#pragma force_active on
struct ItemKey { s32 kind; u32 variation; };
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void processCamera();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void renderOpa();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void init();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual u32 slot31(s32*, ItemKey*);
};
struct BssLoc { u32 unk0, unk4; };
struct BssArc { u32 unk0, unk4, unk8, unkC, unk10, unk14, unk18; };
struct CallOut { s32 a; u32 pad; ItemKey key; };
struct FooCtx { s32 unk0; ItemKey key; u32 unkC; u8 unk10, unk11, unk12; void* unk14; };
extern "C" {
void* fn_800455E0(void*, u32);
u32 fn_800453AC(void*, s32, s32, s32, s32, s32, s32, void*, s32);
}
extern BssLoc lbl_27_bss_7130, lbl_27_bss_7138;
extern BssArc lbl_27_bss_6A38;
extern Object_vptr_3c* lbl_27_bss_5668;
extern char lbl_27_data_790D0[], lbl_805A00C0[];
extern "C" FooCtx* fn_27_2B2830(FooCtx* self,ItemKey src,s32 arg5,s32 arg6) {
self->unk14=lbl_27_data_790D0;
self->unk0=arg6;
self->key=src;
self->unkC=0xFFFF;
self->unk10=0; self->unk11=0; self->unk12=0;
if (src.kind==0xFF) {
itManager::getInstance();
BssArc snap=lbl_27_bss_6A38;
if(lbl_27_bss_7130.unk4==src.variation) {
if(snap.unkC!=0) { void* mgr=soArchiveDb::getManager(2); self->unkC=(u32)fn_800455E0(mgr,snap.unkC); }
} else if(lbl_27_bss_7138.unk4==src.variation && snap.unk10!=0) {
void* mgr=soArchiveDb::getManager(2); self->unkC=(u32)fn_800455E0(mgr,snap.unk10);
}
} else {
CallOut co;
bool r=*((u8*)itManager::getInstance()+0x149D)==0;
self->unk0=4;
if(lbl_27_bss_5668!=0 && r) {
co.a=0; co.key=src;
lbl_27_bss_5668->slot31(&co.a,&co.key);
s32 found=co.a;
if(found!=0) { void* mgr=soArchiveDb::getManager(2); self->unkC=(u32)fn_800455E0(mgr,found); }
}
}
if(self->unkC==0xFFFF) {
void* mgr=soArchiveDb::getManager(2);
self->unkC=fn_800453AC(mgr,arg5,8,0,0,0,0xFF,lbl_805A00C0,1);
}
return self;
}
