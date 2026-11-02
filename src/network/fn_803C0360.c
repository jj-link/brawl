#pragma force_active on
typedef struct {
    char pad[0x1878];
    unsigned short unk1878;
} UnkStruct;

typedef struct {
    int a;
    int b;
    int c;
} UnkSp8;

extern int fn_803AA4E8(void* arg0);
extern int fn_803AA540(void* arg0);
extern int fn_803AFEDC(void* arg0, int arg1, void** arg2);
extern void fn_803A9644(void* a, void* b, int c);
extern int fn_803B000C(void* a, void* b);

int fn_803C0360(void* arg0, void* arg1, int arg2, int arg3, int arg4) {
    void* sp8;
    int temp;

    if (arg0 == 0) return 0xA;
    if (arg1 == 0) return 0xA;
    if ((((UnkStruct*)arg0)->unk1878 & 1) == 0 || fn_803AA4E8(arg0) == 0 || fn_803AA540(arg0) != 0) {
        return 9;
    }
    temp = fn_803AFEDC(arg0, arg2, &sp8);
    if (temp != 0) return temp;
    fn_803A9644((void*)(((UnkSp8*)sp8)->c + arg3), arg1, arg4);
    temp = fn_803B000C(arg0, sp8);
    return temp & ((-temp | temp) >> 31);
}
