#include <mu/mu_object.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on
extern "C" {
extern void* lbl_805A0310;
extern char lbl_8045C8E8[];
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
int fn_800FA740(void*);
void* fn_801063BC();
int fn_801063C4(void*);
void fn_80101810(...);
void fn_80101948(void*, int);
}
struct Name { char s[65]; };
struct Self { char pad[0x2dc]; int count; char pad2[0x14]; MuObject* obj; };
extern "C" void fn_80103CF8(Self* self, int amount, int animate) {
    int value = self->count + amount;
    int clamped = value & ((-value & ~value) >> 31);
    int valid = 0;
    if ((*(unsigned char*)((char*)lbl_805A0310 + 0x42) >> 6 & 1) && fn_800FA740(*(void**)((char*)lbl_805A0310 + 0x32c))) {
        if (fn_801063C4(fn_801063BC())) valid = 1;
    }
    int result;
    if (valid) result = 1;
    else { fn_80101810(lbl_8045C8E8, amount); result = 0; }
    if (!result) { self->count = clamped; return; }
    if (animate) {
        MuObject* obj = self->obj;
        char* mdl = *(char**)((char*)obj + 8);
        int off = *(int*)(mdl + 0x3c);
        const char* src = off ? mdl + off : 0;
        Name n1, n2, n3, n4;
        n1.s[0] = 0;
        strcat(n1.s, src);
        n2 = n1;
        strcat(n2.s, lbl_8059E484);
        n3 = n2;
        sprintf(n3.s + strlen(n3.s), lbl_8059E480, 1);
        n4 = n3;
        obj->changeNodeAnimNIf(n4.s);
        MuObject* obj2 = self->obj;
        char* mdl2 = *(char**)((char*)obj2 + 8);
        int off2 = *(int*)(mdl2 + 0x3c);
        const char* src2 = off2 ? mdl2 + off2 : 0;
        Name m1, m2, m3, m4;
        m1.s[0] = 0;
        strcat(m1.s, src2);
        m2 = m1;
        strcat(m2.s, lbl_8059E484);
        m3 = m2;
        sprintf(m3.s + strlen(m3.s), lbl_8059E480, 1);
        m4 = m3;
        obj2->changeClrAnimNIf(m4.s);
    }
    fn_80101948((char*)self + 0x2d8, clamped);
}