#pragma force_active on

typedef struct {
    int a;
    int b;
    int c;
} Entry12;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Foo;

typedef struct {
    int pad0;
    int unk4;
    int pad8;
    int padC;
    int unk10;
} Bar;

int fn_80210FC0(Foo *arg0, Foo *arg1)
{
    Entry12 *cur;
    unsigned int idx;
    Entry12 *arr;
    Bar *obj;
    char *str;
    int val;
    
    idx = (unsigned int)arg0->unk8;
    obj = (Bar *)arg0->unk0;
    arr = (Entry12 *)obj->unk4;
    cur = arr + idx;
    
loop_1:
    if (idx <= (unsigned int)arg0->unk4 || (unsigned int)arg0->unkC <= idx) {
        return 0;
    }
    arg1->unk0 = (int)obj;
    arg1->unk4 = (int)idx;
    arg1->unk8 = (cur->a & 0xFF000000) != 0;
    str = (char *)(obj->unk10 + (cur->a & 0x00FFFFFF));
    arg1->unkC = (int)str;
    if (*str == 0x2E && (signed char)str[1] == 0) {
        cur++;
        idx++;
        goto loop_1;
    }
    if (arr[idx].a & 0xFF000000) {
        val = arr[idx].c;
    } else {
        val = (int)idx + 1;
    }
    arg0->unk8 = val;
    return 1;
}