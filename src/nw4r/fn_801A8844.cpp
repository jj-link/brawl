#pragma force_active on
extern "C" void fn_80162384(float*, float*, float);
extern const float lbl_805A33A0;
extern const float lbl_805A33A4;
extern const float lbl_805A33A8;
extern const float lbl_805A33AC;
extern const float lbl_805A33B0;
inline void SinCos(float angle, float* s, float* c) { fn_80162384(s,c,lbl_805A33A8 * angle); }
extern "C" void fn_801A8844(float* a, const float* b) {
 float s,c;
 SinCos(b[2],&s,&c);
 float ss,cc;
 float z,sy,sx,t9,t10,t11;
 cc=c;
 sy=b[1];
 ss=s;
 sx=b[0];
 t11=sy*cc;
 float t3=sy*ss;
 z=lbl_805A33A0;
 t9=sx*cc;
 t10=sx*ss;
 a[0]=t9;
 a[1]=t10;
 a[2]=z;
 float w=lbl_805A33B0*((t10+t9)-sx);
 a[4]=-t3;
 a[3]=w;
 a[5]=t11;
 a[6]=z;
 a[7]=lbl_805A33A4+lbl_805A33AC*((t3-t11)-sy);
}
