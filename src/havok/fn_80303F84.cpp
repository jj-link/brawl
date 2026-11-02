#pragma force_active on
#pragma fp_contract on

typedef struct Vec4 {
    float x, y, z, w;
} Vec4 __attribute__((aligned(16)));

typedef struct Mat3 {
    Vec4 col[3];
} Mat3 __attribute__((aligned(16)));

extern "C" {
void fn_80282C78(void*, const void*);
float* fn_80291270(void*, int, int);
void fn_80294740(void*, const void*);
void fn_80294D68(void*, const void*);
void fn_80297444(void*, const void*);
float* fn_80297488(void*, int);
void fn_802DB598(void*);
void* fn_802DB624(void*);
void fn_802DB6D0(void*, float, float, float, float);
void fn_802DB804(void*, const void*);
void fn_802DB878(void*);
void fn_802DB87C(void*, const void*);
void* fn_802DB8A0(void*, int);
void fn_802DC6F8(void*, const void*, const void*);
void fn_802E6F8C(void*, const void*);
void* fn_80303D1C(void*, int);
int fn_80304A14(void*, const void*);
void fn_80304A74(void*, const void*, const void*);
void fn_80304AE0(void*, const void*, int, int, void*);
void fn_80304BC4(void*, const void*, const void*);
void fn_80304C08(void*);
void fn_80304D0C(void*, const void*, const void*);
void fn_80304D50(void*, const void*, int*);
void fn_80304D88(void*, const void*, const void*, const void*);
}

extern float lbl_805A45C4;
extern float lbl_805A4604;
extern float lbl_805A4608;

extern "C" int fn_80303F84(void* object, void* other)
{
    char* base = (char*)object;
    Mat3 matrix;
    Mat3 inverse;
    Vec4 v110, v100, vf0, ve0;
    Vec4 vd0, vc0, vb0;
    Vec4 va0, v90, v80;
    Vec4 v70, v60, v50;
    Vec4 v40, v30, v20;
    void* p;
    int flags1, flags2, flags3;
    float lastZ;

    fn_802DB878(&matrix);
    p = fn_80303D1C(fn_802DB624(base + 0x20), 0);
    fn_80294D68(fn_802DB8A0(&matrix, 0), p);
    p = fn_80303D1C(fn_802DB624(base + 0x20), 1);
    fn_80294D68(fn_802DB8A0(&matrix, 1), p);
    p = fn_80303D1C(fn_802DB624(base + 0x20), 2);
    fn_80294D68(fn_802DB8A0(&matrix, 2), p);

    fn_802DB598(&v110);
    fn_802DC6F8(&v110, &matrix, base + 0x70);
    fn_802DB598(&v100);
    fn_80294D68(&v100, base + 0xc0);
    fn_80297444(&v110, base + 0x60);
    fn_802DB804(&v100, &v110);
    if (fn_80304A14(other, &v100) & 0xe)
        return 1;
    fn_80294740(base + 0xe0, &v100);

    fn_802DB598(&vf0);
    fn_80304A74(&vf0, &matrix, base + 0x60);
    fn_802DB598(&ve0);
    fn_80294D68(&ve0, base + 0xd0);
    fn_80297444(&vf0, base + 0x70);
    fn_802DB804(&ve0, &vf0);
    if (fn_80304A14(other, &ve0) & 0xe)
        return 1;
    fn_80294740(base + 0xf0, &ve0);

    fn_802DB878(&inverse);
    fn_80282C78(&inverse, fn_802DB624(base + 0x20));
    fn_802DB87C(&vd0, fn_802DB8A0(&inverse, 0));
    fn_802DB87C(&vc0, fn_802DB8A0(&inverse, 1));
    fn_802DB87C(&vb0, fn_802DB8A0(&inverse, 2));
    fn_802E6F8C(&vd0, &vd0);
    fn_802E6F8C(&vc0, &vc0);
    fn_802E6F8C(&vb0, &vb0);

    fn_802DB598(&va0);
    fn_80304AE0(object, &inverse, 1, 2, &va0);
    fn_802DB598(&v90);

    {
        float z, y, sum, t, x;
        sum = *fn_80291270(&matrix, 1, 2) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 2) * (t = *fn_80297488(base + 0x60, 1)) + sum;
        sum = *fn_80291270(&matrix, 0, 1) * (t = *fn_80297488(base + 0x70, 0)) + sum;
        z = *fn_80291270(&matrix, 0, 0) * (t = *fn_80297488(base + 0x70, 1)) + sum;

        sum = *fn_80291270(&matrix, 1, 1) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 1) * (t = *fn_80297488(base + 0x60, 1)) + sum;
        sum = *fn_80291270(&matrix, 0, 2) * (t = *fn_80297488(base + 0x70, 0)) + sum;
        y = *fn_80291270(&matrix, 0, 0) * (t = *fn_80297488(base + 0x70, 2)) + sum;

        sum = *fn_80291270(&matrix, 1, 0) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 0) * (t = *fn_80297488(base + 0x60, 1)) + sum;
        sum = *fn_80291270(&matrix, 0, 2) * (t = *fn_80297488(base + 0x70, 1)) + sum;
        x = *fn_80291270(&matrix, 0, 1) * (t = *fn_80297488(base + 0x70, 2)) + sum;
        fn_802DB6D0(&v90, x, y, z, lbl_805A45C4);
    }

    fn_802DB598(&v80);
    fn_80304BC4(&v80, &vb0, &vc0);
    fn_802DB804(&va0, &v90);
    fn_80304C08(&v80);
    fn_80304D0C(&va0, &v80, &va0);
    flags1 = fn_80304A14(other, &va0) & 0xe;
    fn_80304D50(&va0, base + 0xb0, &flags1);
    if (flags1)
        return 1;
    fn_80304D88(&va0, &lbl_805A4604, &v80, &lbl_805A4608);
    fn_80294740(base + 0x100, &va0);

    fn_802DB598(&v70);
    fn_80304AE0(object, &inverse, 2, 0, &v70);
    fn_802DB598(&v60);

    {
        float t, sum, y, z, x;
        sum = *fn_80291270(&matrix, 0, 2) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 2) * (t = *fn_80297488(base + 0x60, 0)) + sum;
        sum = *fn_80291270(&matrix, 1, 1) * (t = *fn_80297488(base + 0x70, 0)) + sum;
        z = *fn_80291270(&matrix, 1, 0) * (t = *fn_80297488(base + 0x70, 1)) + sum;

        sum = *fn_80291270(&matrix, 0, 1) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 1) * (t = *fn_80297488(base + 0x60, 0)) + sum;
        sum = *fn_80291270(&matrix, 1, 2) * (t = *fn_80297488(base + 0x70, 0)) + sum;
        y = *fn_80291270(&matrix, 1, 0) * (t = *fn_80297488(base + 0x70, 2)) + sum;

        sum = *fn_80291270(&matrix, 0, 0) * (t = *fn_80297488(base + 0x60, 2));
        sum = *fn_80291270(&matrix, 2, 0) * (t = *fn_80297488(base + 0x60, 0)) + sum;
        sum = *fn_80291270(&matrix, 1, 2) * (t = *fn_80297488(base + 0x70, 1)) + sum;
        x = *fn_80291270(&matrix, 1, 1) * (t = *fn_80297488(base + 0x70, 2)) + sum;
        fn_802DB6D0(&v60, x, y, z, lbl_805A45C4);
    }

    fn_802DB598(&v50);
    fn_80304BC4(&v50, &vb0, &vd0);
    fn_802DB804(&v70, &v60);
    fn_80304C08(&v50);
    fn_80304D0C(&v70, &v50, &v70);
    flags2 = fn_80304A14(other, &v70) & 0xe;
    fn_80304D50(&v70, base + 0xb0, &flags2);
    if (flags2)
        return 1;
    fn_80304D88(&v70, &lbl_805A4604, &v50, &lbl_805A4608);
    fn_80294740(base + 0x110, &v70);

    fn_802DB598(&v40);
    fn_80304AE0(object, &inverse, 0, 1, &v40);
    fn_802DB598(&v30);

    {
        float t, sum, y, x;
        sum = *fn_80291270(&matrix, 0, 2) * (t = *fn_80297488(base + 0x60, 1));
        sum = *fn_80291270(&matrix, 1, 2) * (t = *fn_80297488(base + 0x60, 0)) + sum;
        sum = *fn_80291270(&matrix, 2, 1) * (t = *fn_80297488(base + 0x70, 0)) + sum;
        lastZ = *fn_80291270(&matrix, 2, 0) * (t = *fn_80297488(base + 0x70, 1)) + sum;

        sum = *fn_80291270(&matrix, 0, 1) * (t = *fn_80297488(base + 0x60, 1));
        sum = *fn_80291270(&matrix, 1, 1) * (t = *fn_80297488(base + 0x60, 0)) + sum;
        sum = *fn_80291270(&matrix, 2, 0) * (t = *fn_80297488(base + 0x70, 2)) + sum;
        y = *fn_80291270(&matrix, 2, 2) * (t = *fn_80297488(base + 0x70, 0)) + sum;

        {
            float t, sum, u;
            sum = *fn_80291270(&matrix, 0, 0) * (t = *fn_80297488(base + 0x60, 1));
            sum = *fn_80291270(&matrix, 1, 0) * (t = *fn_80297488(base + 0x60, 0)) + sum;
            t = *fn_80291270(&matrix, 2, 2) * (t = *fn_80297488(base + 0x70, 1)) + sum;
            x = *fn_80291270(&matrix, 2, 1) * (u = *fn_80297488(base + 0x70, 2)) + t;
            fn_802DB6D0(&v30, x, y, lastZ, lbl_805A45C4);
        }
    }

    fn_802DB598(&v20);
    fn_80304BC4(&v20, &vc0, &vd0);
    fn_802DB804(&v40, &v30);
    fn_80304C08(&v20);
    fn_80304D0C(&v40, &v20, &v40);
    flags3 = fn_80304A14(other, &v40) & 0xe;
    fn_80304D50(&v40, base + 0xb0, &flags3);
    if (flags3)
        return 1;
    fn_80304D88(&v40, &lbl_805A4604, &v20, &lbl_805A4608);
    fn_80294740(base + 0x120, &v40);
    return 0;
}
