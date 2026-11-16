#pragma force_active on
#pragma fp_contract off
#include <types.h>
extern const float lbl_805A1D44, lbl_805A1D48, lbl_805A1D54, lbl_805A1D58;
extern const float lbl_80532500[4];
extern "C" double __frsqrte(double);
extern "C" void** fn_8032EF00(void*);
extern "C" s32 fn_8032EC94(void*, s16, s32);
extern "C" void fn_80284DB0(void*, float*);
extern "C" void fn_80283D7C(float*, const float*);
extern "C" void fn_80284FEC(void*, void*);
extern "C" void fn_8028526C(float*, float*, float*);
extern "C" void fn_8032DA40(float*, float*, s32, float);
struct Vec { float x,y,z,w; };
struct Ent { float v[12]; };
extern "C" void fn_800988EC(void* arg0, void* arg1) {
    Ent tmp;
    char* p = (char*)arg0;
    float out[16] __attribute__((aligned(16)));
    float blk[9];
    Vec ca;
    Vec cb;
    float v60[4];
    float dv[4];
    float dir[4];
    float pos[4];
    float v20[4];
    float dst[16];
    float f0v[12];
    float arr[12];
    float o90[12];
    void** r30 = fn_8032EF00(arg1);
    s32 ret = fn_8032EC94(arg1, *(s16*)(p + 0x18), 1);
    s32 indexA = *(s16*)(p + 0x16);
    char* base = (char*)*r30;
    s32 indexB = *(s16*)(p + 0x18);
    float* eA = (float*)(base + indexA * 0x30);
    ca=*(Vec*)eA;
    float* eB = (float*)(base + indexB * 0x30);
    cb=*(Vec*)eB;
    tmp.v[0]=cb.x; tmp.v[1]=eB[1]; tmp.v[2]=eB[2]; tmp.v[3]=eB[3];
    tmp.v[4]=eB[4]; tmp.v[5]=eB[5]; tmp.v[6]=eB[6]; tmp.v[7]=eB[7];
    tmp.v[8]=eB[8]; tmp.v[9]=eB[9]; tmp.v[10]=eB[10]; tmp.v[11]=eB[11];
    fn_80284DB0(&tmp, dst);
    fn_80283D7C(out, dst);
    dv[0] = out[4]; dv[1] = out[5]; dv[2] = out[6]; dv[3] = out[7];
    float n = dv[2]*dv[2]+(dv[0]*dv[0]+dv[1]*dv[1]);
    float sc = lbl_805A1D44;
    if (n != lbl_805A1D44) {
        if (n <= lbl_805A1D44) { union { unsigned int i; float f; } u; u.i=0x7F800000; sc=u.f; }
        else { float r=(float)__frsqrte(n); sc=(lbl_805A1D54*r)*(lbl_805A1D58-r*(n*r)); }
    }
    dv[0]*=sc; dv[1]*=sc; dv[2]*=sc; dv[3]*=sc;
    dv[0]+=cb.x; dv[1]+=cb.y; dv[2]+=cb.z; dv[3]+=cb.w;
    fn_80284FEC(o90, &tmp);
    arr[0]=dv[0]; arr[1]=dv[1]; arr[2]=dv[2]; arr[3]=dv[3];
    arr[4]=lbl_80532500[0]; arr[5]=lbl_80532500[1]; arr[6]=lbl_80532500[2]; arr[7]=lbl_80532500[3];
    arr[8]=lbl_805A1D48; arr[9]=lbl_805A1D48; arr[10]=lbl_805A1D48; arr[11]=lbl_805A1D48;
    fn_8028526C(f0v,o90,arr);
    v20[0]=f0v[0]; v20[1]=f0v[1]; v20[2]=f0v[2]; v20[3]=f0v[3];
    v60[0]=f0v[0]; v60[1]=f0v[1]; v60[2]=f0v[2]; v60[3]=f0v[3];
    float n2=v60[2]*v60[2]+(v60[0]*v60[0]+v60[1]*v60[1]);
    float sc2=lbl_805A1D44;
    if (n2!=lbl_805A1D44) {
        if (n2<=lbl_805A1D44) { union { unsigned int i; float f; } u; u.i=0x7F800000; sc2=u.f; }
        else { float r=(float)__frsqrte(n2); sc2=(lbl_805A1D54*r)*(lbl_805A1D58-r*(n2*r)); }
    }
    v60[0]*=sc2; v60[1]*=sc2; v60[2]*=sc2; v60[3]*=sc2;
    if (*(s32*)(p+0x10)==1) { v60[0]=-v60[0]; v60[1]=-v60[1]; v60[2]=-v60[2]; v60[3]=-v60[3]; }
    if (*(u8*)(p+6)==0) {
        dir[0]=ca.x-cb.x; dir[1]=ca.y-cb.y; dir[2]=ca.z-cb.z; dir[3]=ca.w-cb.w;
        float n3=dir[2]*dir[2]+(dir[0]*dir[0]+dir[1]*dir[1]);
        float sc3=lbl_805A1D44;
        if (n3!=lbl_805A1D44) {
            if (n3<=lbl_805A1D44) { union { unsigned int i; float f; } u; u.i=0x7F800000; sc3=u.f; }
            else { double estimate=__frsqrte(n3); float r=(float)estimate; sc3=(lbl_805A1D54*r)*(lbl_805A1D58-r*(n3*r)); }
        }
        dir[0]*=sc3; dir[1]*=sc3; dir[2]*=sc3; dir[3]*=sc3;
    } else {
        dir[0]=*(float*)(p+0x100); dir[1]=*(float*)(p+0x104); dir[2]=*(float*)(p+0x108); dir[3]=*(float*)(p+0x10c);
    }
    dir[0]=*(float*)(p+0x100); dir[1]=*(float*)(p+0x104); dir[2]=*(float*)(p+0x108); dir[3]=*(float*)(p+0x10c);
    pos[0]=cb.x; pos[1]=cb.y; pos[2]=cb.z; pos[3]=cb.w;
    pos[0]+=*(float*)(p+0xd0); pos[1]+=*(float*)(p+0xd4); pos[2]+=*(float*)(p+0xd8); pos[3]+=*(float*)(p+0xdc);
    blk[0]=v60[0]; blk[1]=v60[1]; blk[2]=v60[2]; blk[3]=v60[3];
    blk[4]=dir[0]; blk[5]=dir[1]; blk[6]=dir[2]; blk[7]=dir[3]; blk[8]=*(float*)(p+0x60);
    fn_8032DA40(blk,pos,ret,*(float*)(p+0x38));
}
