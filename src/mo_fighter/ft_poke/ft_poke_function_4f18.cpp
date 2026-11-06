#include <so/so_module_accesser.h>
#include <so/event/so_event_system.h>
#pragma force_active on
void operator delete(void*);
class soModelEventObserver;
class soCollisionAttackEventObserver;
template <> class soEventUnitWithWorkArea<soModelEventObserver,4> { public: ~soEventUnitWithWorkArea(); };
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver,4> { public: ~soEventUnitWithWorkArea(); };
extern "C" {
void* fn_116_37E8(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_116_3884(void*, short);
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_38F0(void*, short);
void* fn_27_C7770(void*, short);
void* fn_116_394C(void*, short);
void* fn_116_39A8(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3A60(void*, short);
void* fn_116_3ACC(void*, short);
void* fn_116_3B68(void*, short);
void* fn_116_3CA4(void*, short);
void* fn_116_3D28(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_27_5B39C(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_4040(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_116_4C04(void*, short);
void* fn_116_4C70(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* fn_27_1A8CE0(void*, short);
void* fn_27_D7DBC(void*, short);
void* fn_27_D6B9C(void*, short);
void* fn_27_D57AC(void*, short);
void* fn_27_1A9D88(void*, short);
void* fn_27_1A9364(void*, short);
void* fn_27_1D81C8(void*, short);
}
#pragma opt_common_subs off
#pragma always_inline on
#pragma inline_depth(8)
static inline void group(char* p) { if (p) { short d = -1; fn_116_2164(p+0x64,d); fn_116_2200(p+0x48,d); fn_116_38F0(p+0x14,d); if(p) fn_27_C7770(p,d); } }
static inline void collision(char* p) { if(p) { short d=-1; fn_116_3884(p+0x29c,d); group(p+0x1e8); group(p+0x134); group(p+0x80); if(p) { short d=-1; fn_116_2164(p+0x30,d); fn_116_2200(p+0x14,d); if(p) fn_27_C7770(p,d); } } }
static inline void events(char* p) { if (p+0xcc) { short d=-1;
fn_27_1A8CE0(p+0x4c0,d); fn_27_D7DBC(p+0x480,d); fn_27_D6B9C(p+0x444,d);
reinterpret_cast<soEventUnitWithWorkArea<soModelEventObserver,4>*>(p+0x3e8)->soEventUnitWithWorkArea<soModelEventObserver,4>::~soEventUnitWithWorkArea();
reinterpret_cast<soEventUnitWithWorkArea<soCollisionAttackEventObserver,4>*>(p+0x38c)->soEventUnitWithWorkArea<soCollisionAttackEventObserver,4>::~soEventUnitWithWorkArea();
fn_27_D57AC(p+0x350,d); fn_27_1A9D88(p+0x248,d); fn_27_1A9364(p+0x198,d);
reinterpret_cast<soEventManageModuleImpl*>(p+0x184)->soEventManageModuleImpl::~soEventManageModuleImpl();
reinterpret_cast<soInstanceManagerSimpleEntity<soEventUnit*,soArrayVector<soInstanceUnit<soEventUnit*>,19> >*>(p+0xcc)->~soInstanceManagerSimpleEntity();
} }
static inline void modules(char* p) { if(p+0xcc) { short d=-1;
fn_116_394C(p+0x1320,d); fn_116_39A8(p+0x12e0,d); fn_116_3A04(p+0x12c8,d); fn_116_3A60(p+0x1170,d);
if(p+0x1104) fn_116_3ACC(p+0x1148,d);
fn_116_3B68(p+0x1098,d);
if(p+0xfc0) { fn_116_3CA4(p+0xfe8,d); fn_116_3D28(p+0xfd4,d); fn_27_C74E8(p+0xfc0,d); }
fn_116_3D88(p+0xf1c,d); fn_116_3EBC(p+0xee8,d); if(p+0xeb4) fn_27_5B39C(p+0xeb4,d);
fn_116_3F18(p+0xd50,d); fn_116_3F84(p+0xd40,d); fn_116_3FE4(p+0xd18,d); fn_116_4040(p+0xb48,d); fn_116_40C4(p+0xae4,d); fn_116_4190(p+0xaa8,d); fn_116_41EC(p+0xa00,d); fn_116_4258(p+0x94c,d);
if(p+0x7c0) { fn_27_13C90(p+0x7dc,d); fn_27_21038(p+0x7c8,d); }
fn_116_4C04(p+0x67c,d); fn_116_4C70(p+0x64c,d); fn_116_42CC(p+0x63c,d); fn_116_430C(p+0x624,d);
reinterpret_cast<soModuleAccesser*>(p+0x544)->soModuleAccesser::~soModuleAccesser();
events(p); } }
static inline void base(char* p) { if(p) { short d=-1; fn_116_37E8(p+0x1698,d); fn_27_1DBB60(p+0x1660,d); if(p+0xcc) { collision(p+0x133c); modules(p); } fn_27_1D81C8(p,static_cast<short>(0)); } }
extern "C" void* fn_116_4F18(void* object, int deleting) { if(object) { base(static_cast<char*>(object)); if(static_cast<short>(deleting)>0) operator delete(object); } return object; }
