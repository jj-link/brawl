#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
extern const f32 lbl_805A17B0;
extern "C" void fn_800435E8(register const f32* a,register const f32* b,register f32* o,register f32 t) {
 f32 lo[2],hi[2];
 register f32 *ph=hi,*pl=lo;
 register f32 z,x,s,v1,y,v2,q,w,v4,r;
 s=lbl_805A17B0-t;
 asm { psq_l x,0(a),0,0 }
 asm { psq_l v1,8(a),0,0 }
 asm { psq_l v2,16(a),0,0 }
 asm { ps_muls0 z,x,s }
 asm { psq_l x,0(b),0,0 }
 asm { ps_muls0 v1,v1,s }
 asm { psq_l y,8(b),0,0 }
 asm { ps_muls0 v2,v2,s }
 asm { psq_l w,24(a),0,0 }
 asm { ps_madds0 z,x,t,z }
 asm { psq_l x,16(b),0,0 }
 asm { ps_madds0 v1,y,t,v1 }
 asm { psq_l r,32(a),0,0 }
 asm { ps_madds0 y,x,t,v2 }
 asm { psq_l q,24(b),0,0 }
 asm { psq_st z,0(o),0,0 }
 asm { ps_muls0 v2,w,s }
 asm { ps_muls0 w,r,s }
 asm { psq_l v4,32(b),0,0 }
 x=o[0]; z=o[1];
 asm { ps_madds0 s,q,t,v2 }
 hi[0]=x;
 asm { ps_madds0 t,v4,t,w }
 hi[1]=z;
 asm { psq_l q,0(ph),0,0 }
 lo[0]=x;
 asm { ps_sub v2,v1,q }
 lo[1]=z;
 asm { psq_l x,0(pl),0,0 }
 asm { ps_sel v2,v2,v1,q }
 asm { psq_st v1,8(o),0,0 }
 asm { ps_sub z,v1,x }
 asm { ps_sub q,y,v2 }
 asm { psq_st y,16(o),0,0 }
 asm { ps_sel z,z,x,v1 }
 asm { psq_st s,24(o),0,0 }
 asm { ps_sel v1,q,y,v2 }
 asm { psq_st t,32(o),0,0 }
 asm { ps_sub x,y,z }
 asm { ps_sub v2,s,v1 }
 asm { ps_sel z,x,z,y }
 asm { ps_sel v1,v2,s,v1 }
 asm { ps_sub x,s,z }
 asm { ps_sub y,t,v1 }
 asm { ps_sel z,x,z,s }
 asm { ps_sel s,y,t,v1 }
 asm { ps_sub x,t,z }
 asm { psq_st s,0(ph),0,0 }
 asm { ps_sel x,x,z,t }
 t=hi[0]; z=hi[1]; o[12]=t;
 asm { psq_st x,0(pl),0,0 }
 x=lo[0]; t=lo[1];
 o[10]=x; o[11]=t; o[13]=z;
}