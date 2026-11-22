#pragma force_active on
struct Vec4 { float x,y,z,w; void set(float a,float b,float c,float d) { x=a; y=b; z=c; w=d; } };
class Class_804888F8 {
public:
virtual void fn_8030A578();
virtual void fn_80312920();
virtual void fn_8030B884();
virtual void fn_8030C454();
virtual void fn_8030BFB8();
virtual void fn_8030D044();
virtual void fn_8030D69C();
virtual void fn_80308AF8();
virtual void fn_8030FED4();
virtual void fn_8030D6A8();
virtual void fn_8030D758();
virtual void fn_8030DCEC();
virtual void fn_8030B6BC();
virtual void fn_80312B34(Vec4*, Vec4*);
char pad[0x3c];
Vec4 a, b, scale;
};
extern const float lbl_805A4610;
extern const float lbl_805A4614;
extern "C" void fn_80312D68(Class_804888F8* self, const Vec4* in, Vec4* out) {
    __attribute__((aligned(16))) Vec4 neg;
    __attribute__((aligned(16))) Vec4 result;
    __attribute__((aligned(16))) Vec4 inv;
    neg.x=-in->x; neg.y=-in->y; neg.z=-in->z; neg.w=-in->w;
    self->fn_80312B34(&neg,&result);
    self->a.x += result.x;
    self->a.y += result.y;
    self->a.z += result.z;
    self->a.w += result.w;
    inv.set(lbl_805A4614/self->scale.x, lbl_805A4614/self->scale.y, lbl_805A4614/self->scale.z, lbl_805A4610);
    self->b.x=self->a.x+inv.x;
    self->b.y=self->a.y+inv.y;
    self->b.z=self->a.z + inv.z;
    self->b.w=self->a.w+inv.w;
    out->x=-result.x; out->y=-result.y; out->z=-result.z; out->w=-result.w;
}