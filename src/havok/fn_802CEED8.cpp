#pragma force_active on
#pragma fp_contract on
extern float lbl_805A4068;
struct V { float x,y,z,w; } __attribute__((aligned(16)));
struct M { V a,b,c,d; };
struct Bounds { float p[3]; float center; float a[4]; float b[3]; };
inline void copyMatrix(M* n,const M* mat) {
 V md,mc,mb,ma;
 ma.x=mat->a.x; ma.y=mat->a.y; ma.z=mat->a.z; ma.w=mat->a.w;
 mb.x=mat->b.x; mb.y=mat->b.y; mb.z=mat->b.z; mb.w=mat->b.w;
 mc.x=mat->c.x; mc.y=mat->c.y; mc.z=mat->c.z; mc.w=mat->c.w;
 md.x=mat->d.x; md.y=mat->d.y; md.z=mat->d.z; md.w=mat->d.w;
 n->a.x=ma.x; n->a.y=ma.y; n->a.z=ma.z; n->a.w=ma.w;
 n->b.x=mb.x; n->b.y=mb.y; n->b.z=mb.z; n->b.w=mb.w;
 n->c.x=mc.x; n->c.y=mc.y; n->c.z=mc.z; n->c.w=mc.w;
 n->d.x=md.x; n->d.y=md.y; n->d.z=md.z; n->d.w=md.w;
}
extern "C" void fn_802CEED8(const Bounds* bd, const M* mat, float* out, float off) {
 V dv;
 V result[2];
 M n;
 float d=off+bd->center;
 dv.x=d; dv.y=d; dv.z=d; dv.w=d;
 copyMatrix(&n,mat);
 const float* input=bd->a;
 for(int i=0;i<2;i++) {
 int j=i*4;
 float* dst=(float*)result+j;
 const float* src=input+j;
 float x=src[0],y=src[1],z=src[2];
 dst[0]=n.d.x+(x*n.a.x+y*n.b.x+z*n.c.x);
 dst[1]=n.d.y+(x*n.a.y+y*n.b.y+z*n.c.y);
 dst[2]=n.d.z+(x*n.a.z+y*n.b.z+z*n.c.z);
 dst[3]=lbl_805A4068;
 }
 V& pa=result[0];
 V& pb=result[1];
 out[0]=pa.x<pb.x?pa.x:pb.x;
 out[1]=pa.y<pb.y?pa.y:pb.y;
 out[2]=pa.z<pb.z?pa.z:pb.z;
 out[3]=pa.w<pb.w?pa.w:pb.w;
 out[0]-=dv.x; out[1]-=dv.y; out[2]-=dv.z; out[3]-=dv.w;
 out[4]=pa.x>pb.x?pa.x:pb.x;
 out[5]=pa.y>pb.y?pa.y:pb.y;
 out[6]=pa.z>pb.z?pa.z:pb.z;
 out[7]=pa.w>pb.w?pa.w:pb.w;
 out[4]+=dv.x; out[5]+=dv.y; out[6]+=dv.z; out[7]+=dv.w;
}
