#pragma force_active on
typedef struct Mtx34 {
    float m[12];
} Mtx34;

void fn_80282C78(Mtx34 *dst, const Mtx34 *src);

void fn_80284614(Mtx34 *dst, const Mtx34 *src)
{
    fn_80282C78(dst, src);
    fn_80282C78(dst + 1, src + 2);
    fn_80282C78(dst + 2, src + 1);
    fn_80282C78(dst + 3, src + 3);
}
