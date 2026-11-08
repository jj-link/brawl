#pragma force_active on
struct Obj { char p[4]; float a,b,c; char q[24]; float d; char r[12]; float e; char s[12]; float g; };
extern "C" {
void fn_801EC158(void*);
void fn_80194FF8(float*, void*, void*, float);
void fn_80195280(Obj* obj, void* unused, char* arg2, float f) {
    float out[3];
    obj->a=1.0f; obj->b=1.0f; obj->c=1.0f;
    fn_801EC158((char*)obj + 0x1c);
    fn_80194FF8(out, arg2, arg2 + 8, f);
    obj->d=out[0]; obj->e=out[1]; obj->g=out[2];
}
}