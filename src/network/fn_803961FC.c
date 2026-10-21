#pragma force_active on
extern void fn_803974FC(void);
extern int fn_80397580(void);
extern void* fn_803970DC(int a, int b);

int fn_803961FC(int arg0) {
    void* p;
    fn_803974FC();
    p = fn_803970DC(fn_80397580(), arg0);
    if (p != 0) {
        return *(int*)((char*)p + 0x4);
    }
    return -1;
}
