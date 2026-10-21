#pragma force_active on
extern void fn_803ADA3C(int arg0, int* arg1);

int fn_803AA4E8(void* arg0) {
    int sp8;
    fn_803ADA3C(*(int*)((char*)arg0 + 0x188C), &sp8);
    return sp8;
}
