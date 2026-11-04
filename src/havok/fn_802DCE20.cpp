#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A4270;
extern const float lbl_805A4278;
extern const float lbl_805A4284;
extern const float lbl_805A4288;
extern "C" double __frsqrte(double);
extern "C" void fn_80287FE8(void*, void*, void*);
struct Vec4 { float x,y,z,w; } __attribute__((aligned(16)));
inline float dot3(const Vec4& a, const Vec4& b) { return a.z*b.z+(a.x*b.x+a.y*b.y); }
extern "C" void fn_802DCE20(void* unused, unsigned int** indices, float** values, void* unused2, char* obj, void* arg8, void* arg9) {
    Vec4 a, b;
    struct Result { Vec4 normal; float x,y,z,w; } result;
    ++*indices;
    unsigned int index = **indices;
    result.w = lbl_805A4278;
    float* p = (float*)(obj + (index << 4));
    a.x=p[20]; a.y=p[21]; a.z=p[22]; a.w=p[23];
    b.x=p[32]; b.y=p[33]; b.z=p[34]; b.w=p[35];
    float cx = a.y*b.z-a.z*b.y;
    float cy = a.z*b.x-a.x*b.z;
    float cz = a.x*b.y-a.y*b.x;
    result.w = lbl_805A4278;
    result.normal.x = cx;
    result.normal.y = cy;
    result.normal.z = cz;
    result.normal.w = lbl_805A4270;
    float s = cz*cz+(cx*cx+cy*cy);
    if (!(s < lbl_805A4284)) {
        float scale = lbl_805A4270;
        if (s != lbl_805A4270) {
            if (s <= lbl_805A4270) {
                union { unsigned int i; float f; } u;
                u.i=0x7f800000;
                scale=u.f;
            } else {
                double estimate=__frsqrte(s);
                float r=(float)estimate;
                scale=(lbl_805A4278*r)*(lbl_805A4288-r*(s*r));
            }
        }
        result.normal.x *= scale;
        result.normal.y *= scale;
        result.normal.z *= scale;
        result.normal.w *= scale;
        result.z = dot3(a,b);
        float* v=*values;
        *values=v+4;
        result.x=v[0];
        result.y=v[1];
        fn_80287FE8(&result,arg8,arg9);
        ++*(int*)(obj+0xb8);
    }
}