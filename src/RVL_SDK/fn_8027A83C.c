#pragma force_active on
int fn_8027B390(int, int);

int fn_8027A83C(char* p) {
    return fn_8027B390(*(int*)(p + 0x24), *(int*)p);
}
