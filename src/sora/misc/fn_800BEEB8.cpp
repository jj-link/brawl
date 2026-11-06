#pragma force_active on

#include <sr/sr_common.h>
#include <mu/mu_msg.h>

extern "C" {
extern char lbl_805A22A8[8];
extern char lbl_8059E0D8;

void* fn_800BF204(void* self);
void fn_800B96E8(void* p, int v);
void fn_800BF380(void* self, void* entries, int count, void* resFile, int prio, int heap);
void fn_800BF4BC(void* self, Heaps::HeapType a, int b, unsigned char c, unsigned char d);
void* fn_800B9640(void);
void* fn_800B9678(void);
unsigned long strlen(const char* s);
void fn_800BF850(void* self, int id, const char* str, int len, int flag);

void* fn_800BEEB8(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, Heaps::HeapType arg7,
                  int argSp8, unsigned char argSpC, unsigned char argSp10, unsigned char argSp14)
{
    char* s1;
    char* s2;
    unsigned long len1;
    unsigned long len2;
    char* self = (char*)operator new(0x12C, arg7);
    if (self != 0) {
        self = (char*)fn_800BF204(self);
    }
    *(int*)(self + 0xFC) = arg0;
    *(int*)(self + 0x4C) = arg1;
    *(int*)(self + 0x50) = arg2;
    *(int*)(self + 0x110) = arg6;
    *(int*)(self + 0x44) = arg4;
    fn_800B96E8(self + 0x54, argSp14);
    fn_800BF380(self, lbl_805A22A8, 1, (void*)arg3, arg5, argSp8);
    fn_800BF4BC(self, arg7, argSp8, argSpC, argSp10);

    s1 = (char*)fn_800B9640();
    s2 = (char*)fn_800B9678();
    len1 = strlen(s1);
    len2 = strlen(s2);

    switch (*(int*)(self + 0xFC)) {
    case 1:
        fn_800BF850(self, 2, s1, (int)len1, 2);
        fn_800BF850(self, 3, s2, (int)len2, 2);
        break;
    case 2:
        fn_800BF850(self, 4, s1, (int)len1, 2);
        break;
    default:
        ((MuMsg*)*(void**)(self + 0x48))->printf(2, &lbl_8059E0D8);
        ((MuMsg*)*(void**)(self + 0x48))->printf(3, &lbl_8059E0D8);
        break;
    }
    return self;
}
}
