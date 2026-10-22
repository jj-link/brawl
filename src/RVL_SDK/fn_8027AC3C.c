#pragma force_active on

int fn_8027B4A8(char* base, int idx);
void fn_8027ACC0(int param0, int param1);
int fn_8021A338(int param0, int param1, void* callback);

int fn_8027AC3C(char* obj, int param1) {
    if (*(int*)obj >= 4) {
        return -2;
    }
    if (fn_8027B4A8(*(char**)(obj + 0x24), *(int*)obj) || *(unsigned char*)(obj + 0x1C)) {
        return -2;
    }
    return fn_8021A338(*(int*)obj, param1, fn_8027ACC0);
}
