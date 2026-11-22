#pragma force_active on
#include <types.h>
extern "C" { u8 fn_27_1119B8(void*); u32 fn_27_111E30(void*); void fn_27_145730(u8*, s32, s32, u8); void* getOwner__9ftManagerFi(void*, s32); }
extern u8 g_ftCommonDataAccesser[]; extern void* g_ftManager;
class soNullable { public: virtual void isNull(); virtual void fn_27_14DE5C(); virtual void fn_27_7FB00(); virtual void fn_27_7FAFC(); virtual void fn_27_7FAF8(); virtual void fn_27_7FAF4(); virtual s32 fn_27_7FAF0(); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual s32 slot4(s32); virtual void slot5(); virtual void slot6(); };
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void processCamera(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39(); virtual s32 slot40(); };
struct Inner { char pad0[0x64]; Object_vptr_0* a; char pad1[0x58]; soNullable* c; };
struct Data { char pad0[8]; Object_vptr_3c* b; char pad1[0xcc]; Inner* inner; };
struct Self { char pad[8]; Data* data; };
extern "C" void fn_27_14D834(Self* __restrict self) {
s32 x;
soNullable* c;
s32 id=self->data->inner->a->slot4(0x10000000);
u8 flags;
void* owner=getOwner__9ftManagerFi(g_ftManager,id);
flags=fn_27_1119B8(owner);
if(fn_27_111E30(owner)==1) flags|=0x80;
c=self->data->inner->c;
x=self->data->b->slot40();
s32 y=c->fn_27_7FAF0();
fn_27_145730(g_ftCommonDataAccesser,y,x,flags);
}