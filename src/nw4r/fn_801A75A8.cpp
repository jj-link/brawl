#include <types.h>
#pragma force_active on
extern "C" {
extern const float lbl_805A3360, lbl_805A3364, lbl_805A3368, lbl_805A336C, lbl_805A3370, lbl_805A3374, lbl_805A3378, lbl_805A337C;
extern const double lbl_805A3380;
struct Obj { int pad[0x1C]; int unk70; float unk74,unk78,unk7C,unk80,unk84,unk88,unk8C,unk90,unk94,unk98,unk9C,unkA0,unkA4; int unkA8; float unkAC,unkB0,unkB4,unkB8,unkBC,unkC0,unkC4,unkC8,unkCC,unkD0,unkD4,unkD8,unkDC,unkE0,unkE4,unkE8,unkEC,unkF0; int unkF4,unkF8,unkFC,unk100,unk104,unk108; };
void fn_801A75A8(void** pp, int arg1, int arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
Obj* obj=(Obj*)*pp;
if(obj) {
obj->unk70=33; obj->unk74=lbl_805A3360; obj->unk78=lbl_805A3360; obj->unk7C=lbl_805A3364; obj->unk80=lbl_805A3360; obj->unk84=lbl_805A3368; obj->unk88=lbl_805A3360; obj->unk8C=lbl_805A3360; obj->unk90=lbl_805A3360; obj->unk94=lbl_805A3360; obj->unk98=lbl_805A3360; obj->unk9C=lbl_805A3360; obj->unkA0=lbl_805A3360; obj->unkA4=lbl_805A3360;
obj->unkA8=0; obj->unkAC=lbl_805A336C; obj->unkB0=lbl_805A3370; obj->unkB4=lbl_805A3374; obj->unkB8=lbl_805A3378; obj->unkBC=lbl_805A3360;
obj->unkC0=(float)arg6; obj->unkC4=lbl_805A3360; obj->unkC8=(float)arg5; obj->unkCC=lbl_805A337C; obj->unkD0=lbl_805A337C; obj->unkD4=lbl_805A337C; obj->unkD8=lbl_805A337C; obj->unkDC=lbl_805A3360; obj->unkE0=lbl_805A3360; obj->unkE4=(float)arg3; obj->unkE8=(float)arg4; obj->unkEC=lbl_805A3360; obj->unkF0=lbl_805A3368; obj->unkF4=0; obj->unkF8=0; obj->unkFC=arg1; obj->unk100=arg2; obj->unk104=0; obj->unk108=0;
}}
}