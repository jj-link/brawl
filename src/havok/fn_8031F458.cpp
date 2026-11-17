#pragma force_active on
#pragma fp_contract on
extern "C" { extern const float lbl_805A4728; }
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2();
virtual void slot3(); virtual void slot4(); virtual void slot5();
virtual void slot6(); virtual void slot7(); virtual void slot8();
virtual void slot9(); virtual void slot10(float*, float*);
};
inline void set4(float* p,float x,float y,float z,float w) {p[0]=x;p[1]=y;p[2]=z;p[3]=w;}
struct Vec4 { float x,y,z,w; };
inline void prepare(const float* v,float* out,float* tmp) {
float x=v[0], y=v[1], z=v[2], w=v[3];
set4(out+8,x,y,z,w);
set4(tmp,-x,-y,-z,-w);
}
inline void rotateInverse(float* dst, const float* m, const float* v) {
float x=v[0], z=v[2], y=v[1];
float b0=x*m[0]+y*m[1]+z*m[2];
float b1=x*m[4]+y*m[5]+z*m[6];
float b2=x*m[8]+y*m[9]+z*m[10];
set4(dst,b0,b1,b2,lbl_805A4728);
}
inline void transformPoint(float* dst, const float* m, const float* v) {
float x=v[0], y=v[1], z=v[2];
float px=m[12]+(x*m[0]+y*m[4]+z*m[8]);
float py=m[13]+(x*m[1]+y*m[5]+z*m[9]);
float pz=m[14]+(x*m[2]+y*m[6]+z*m[10]);
set4(dst,px,py,pz,lbl_805A4728);
}
inline void subtract4(float* dst, const float* a, const float* b) {
float x=a[0]-b[0], y=a[1]-b[1], z=a[2]-b[2], w=a[3]-b[3];
set4(dst,x,y,z,w);
}
inline float dot3(const float* a, const float* b) {
return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}
extern "C" void fn_8031F458(Object_vptr_0* a0,Object_vptr_0* a1,float* m, const Vec4 direction,float* out) {
const float* v=(const float*)&direction;
Vec4 neg __attribute__((aligned(16)));
Vec4 rotated __attribute__((aligned(16)));
Vec4 transformed __attribute__((aligned(16)));
Vec4 delta __attribute__((aligned(16)));
prepare(v,out,(float*)&neg);
a0->slot10((float*)&neg,out);
float* rotatedPtr=(float*)&rotated;
rotateInverse(rotatedPtr,m,v);
a1->slot10(rotatedPtr,out+4);
float d3, d2, d1, d0;
float mp3, mp2, mp1, mp0;
float pz=out[6], py=out[5], px=out[4];
mp0=m[12]+(px*m[0]+py*m[4]+pz*m[8]);
mp1=m[13]+(px*m[1]+py*m[5]+pz*m[9]);
mp2=m[14]+(px*m[2]+py*m[6]+pz*m[10]);
mp3=lbl_805A4728;
d0=out[0]-mp0;
d1=out[1]-mp1;
d2=out[2]-mp2;
d3=out[3]-mp3;
out[11]=d2*out[10]+(d0*out[8]+d1*out[9]);
transformed.x=mp0; transformed.y=mp1; transformed.z=mp2; transformed.w=mp3;
delta.x=d0; delta.y=d1; delta.z=d2; delta.w=d3;
}