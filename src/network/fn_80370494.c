#pragma force_active on
typedef int (*fn_803703DC_t)(int*, int);
typedef int (*fn_803703F0_t)(int*, int*);
typedef void (*fn_80370400_t)(unsigned char*);

extern int fn_803703DC(int*, int);
extern int fn_803703F0(int*, int*);
extern void fn_80370400(unsigned char*);
extern int fn_8035AEB4(int, int, fn_803703DC_t, fn_803703F0_t, fn_80370400_t);

int fn_80370494(void* arg0) {
    void* obj;
    int result;
    obj = *(void**)arg0;
    ((int*)obj)[0x44c / 4] = 0;
    ((int*)obj)[0x448 / 4] = 0;
    result = fn_8035AEB4(0x1c, 0x20, fn_803703DC, fn_803703F0, fn_80370400);
    ((int*)obj)[0x444 / 4] = result;
    return result != 0;
}