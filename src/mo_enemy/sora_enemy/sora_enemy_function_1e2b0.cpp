#pragma force_active on
#include <types.h>
extern "C" { u32 fn_41_1AE7C(void* p); }
class SubObj { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(float); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(float); };
struct Arg { u8 pad0[5]; u8 flags; u8 pad1[2]; int state; u8 pad2[0x3c]; u8 b48; u8 pad3[3]; float f4C; u8 pad4[0x14]; u8 b64; };
struct Mod { u8 pad[8]; SubObj* obj; };
struct Owner { u8 pad[0xd8]; Mod* mod; };
extern "C" void fn_41_1E2B0(void* arg0, void* arg1) {
Arg* a=(Arg*)arg0; Owner* o=(Owner*)arg1;
if(fn_41_1AE7C(arg0)!=1) if((a->flags>>7)&1) if(a->b64!=1 && a->b48!=1) {
int s=a->state;
if(s<14) switch(s) {
case 0: goto done;
case 1: goto call;
default: goto done;
} else if(s<23) { if(s>=20) goto done; goto call; } else if(s<25) {
call: { SubObj* obj=o->mod->obj; obj->v7(a->f4C); obj->v35(a->f4C); }
}
}
done:;
}