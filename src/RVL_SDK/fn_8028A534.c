#pragma fp_contract on
#pragma force_active on
extern const float lbl_805A3D90, lbl_805A3D98, lbl_805A3DB0, lbl_805A3DB4;
extern float lbl_804864F0[];
extern double __frsqrte(double);
extern void fn_8028E4A4(float *, float *, float **);
void fn_8028A534(float *arg0, float *arg1, const float *arg2, const float *arg3, float **arg4)
{
    union { unsigned int i; float f; } u;
    float dw, dz, dy, dx;
    float w3, z3, y3, x3, w2, z2, y2, x2;
    float len2, r, var, len, sc, a0, a1, a2, a3;
    float *k;
    float buf[16] __attribute__((aligned(16)));
    y2=arg2[13]; y3=arg3[13]; x2=arg2[12]; x3=arg3[12];
    z2=arg2[14]; z3=arg3[14]; w2=arg2[15]; w3=arg3[15];
    dx=x2-x3; dy=y2-y3; dz=z2-z3; dw=w2-w3;
    len2=dz*dz+(dx*dx+dy*dy);
    buf[4]=x2;buf[5]=y2;buf[6]=z2;buf[7]=w2;
    buf[8]=x3;buf[9]=y3;buf[10]=z3;buf[11]=w3;
    buf[0]=dx;buf[1]=dy;buf[2]=dz;buf[3]=dw;
    if(len2<=lbl_805A3D90){u.i=0x7F800000;var=u.f;}
    else{r=(float)__frsqrte(len2);var=lbl_805A3DB0*r*(lbl_805A3DB4-r*(len2*r));}
    len=lbl_805A3D98/var;sc=lbl_805A3D98/len;
    a0=buf[0]*sc;a1=buf[1]*sc;a2=buf[2]*sc;a3=buf[3]*sc;
    buf[0]=a0;buf[1]=a1;buf[2]=a2;buf[3]=a3;
    if(len>lbl_805A3D90){buf[12]=a0;buf[13]=a1;buf[14]=a2;buf[15]=a3;}
    else{len=lbl_805A3D90;k=lbl_804864F0;buf[12]=k[0];buf[13]=k[1];buf[14]=k[2];buf[15]=k[3];}
    fn_8028E4A4(&buf[4],arg1,arg4);
    { float a, b; a=arg0[1]-len; b=arg1[2]; (*arg4)[-9]=a*b; }
}