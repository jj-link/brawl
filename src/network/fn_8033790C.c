#include <string.h>
#pragma force_active on
extern void *lbl_805A0F70;
extern char lbl_80489648[];
int fn_8033891C(void);
int fn_803517BC(int, int);
int fn_80350C70(int);
int fn_80350C4C(int);
void fn_80350C7C(int);
void fn_80351A80(int, int);
void fn_80335638(int, const char *, ...);
typedef void (*Callback)(int, int, void *);
int fn_8033790C(int arg0, int arg1, int arg2)
{
    int val;
    int offset;
    int ptr_a;
    int ptr_b;
    int inner_a;
    int inner_b;
    int inner_off;
    int result;
    int i;
    int j;
    int field1c;
    int field1c2;
    int val2;
    int temp;
    Callback func;
    result = -1;
    ptr_a = arg0;
    ptr_b = arg0;
    i = 0;
    offset = 0;
    while (i < arg1) {
        field1c = *(int *)((char *)lbl_805A0F70 + 0x1C);
        if (field1c == 0) {
            val = 0;
        } else {
            temp = fn_803517BC(fn_8033891C(), field1c + offset);
            if (temp == 0) goto zero1;
            if (temp != -1) goto valid1;
zero1:      val = 0;
            goto end1;
valid1:     val = temp;
end1:       ;
        }
        if (val != 0) {
            if (val == arg2) result = i;
            j = i + 1;
            inner_off = j * 0xC;
            inner_a = arg0 + inner_off;
            inner_b = inner_a;
            while (j < arg1) {
                field1c2 = *(int *)((char *)lbl_805A0F70 + 0x1C);
                if (field1c2 == 0) {
                    val2 = 0;
                } else {
                    temp = fn_803517BC(fn_8033891C(), field1c2 + inner_off);
                    if (temp == 0) goto zero2;
                    if (temp != -1) goto valid2;
zero2:              val2 = 0;
                    goto end2;
valid2:             val2 = temp;
end2:               ;
                }
                if (val == val2) {
                    if (fn_80350C70(ptr_a) == 2 && fn_80350C70(inner_a) == 3)
                        fn_80351A80(ptr_b, val);
                    if (fn_80350C4C(inner_a) != 0) fn_80350C7C(ptr_b);
                    fn_80335638(0x20000, lbl_80489648, i, j, fn_80350C70(ptr_a));
                    if (lbl_805A0F70 != 0) {
                        memset((void *)inner_b, 0, 0xC);
                        func = *(Callback *)((char *)lbl_805A0F70 + 0x40);
                        if (func != 0) func(j, i, *(void **)((char *)lbl_805A0F70 + 0x44));
                    }
                    *((unsigned char *)lbl_805A0F70 + 0x21) = 1;
                }
                inner_off += 0xC;
                inner_a += 0xC;
                inner_b += 0xC;
                j++;
            }
        }
        offset += 0xC;
        ptr_a += 0xC;
        ptr_b += 0xC;
        i++;
    }
    return result;
}