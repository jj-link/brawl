#include <so/so_external_value_accesser.h>
#pragma force_active on
#define V(n) virtual void slot##n();
class Object_vptr_0 {
public:
V(0) V(1) V(2) V(3) V(4)
virtual int slot5();
V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
virtual unsigned int slot16();
V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33)
virtual int slot34(int);
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
virtual unsigned int slot40();
};
#undef V
struct Modules {
char pad[0x20];
Object_vptr_0* m20;
char pad2[0x1c];
Object_vptr_0* m40;
char pad3[0x2c];
Object_vptr_0* m70;
};
struct Access { char pad[0xd8]; Modules* modules; };
extern "C" unsigned int* fn_27_14554C(void*, unsigned int, unsigned int);
extern "C" char g_ftCommonDataAccesser[];
extern "C" int fn_27_14D74C(Object_vptr_3c* obj) {
    unsigned int motion = ((Access*)soExternalValueAccesser::getModuleAccesser((StageObject*)obj))->modules->m70->slot16();
    unsigned int kind = obj->slot40();
    if ((*fn_27_14554C(g_ftCommonDataAccesser, kind, motion) >> 27) & 1)
        return 0;
    if (((Access*)soExternalValueAccesser::getModuleAccesser((StageObject*)obj))->modules->m40->slot5())
        return 0;
    return ((Access*)soExternalValueAccesser::getModuleAccesser((StageObject*)obj))->modules->m20->slot34(0) == 0;
}