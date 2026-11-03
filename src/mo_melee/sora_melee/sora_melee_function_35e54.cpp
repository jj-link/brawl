#include <types.h>
#pragma force_active on

struct Class_50_base { char pad[0x30]; };
class Class_50 : public Class_50_base {
public:
    virtual void fn_27_1C28();
    virtual int fn_27_2A9C();
};

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual void* fn_27_FF68(int);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

#define HOLDER(p) (*(Class_C80**)((char*)(p) + 8))

extern "C" {
extern void* lbl_27_bss_8;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_362C(void*);
void fn_27_372C(void*, int, void*);
void fn_27_37D7C(void*, void*, s32, s32);
u32 fn_27_38048(void*);
void* fn_8015C1B0(void*, void*);
void fn_8015C144(void*, void*);

void fn_27_35E54(void* arg0) {
    char* item2;
    s32 k;
    s32 j;
    char* item;
    void* base;
    s32 i;
    char* list;
    void* node;
    for (i = 0; i < HOLDER(arg0)->fn_27_FFF0(); i++) {
        list = (char*)HOLDER(arg0)->fn_27_FF68(i) + 0x1c;
        while (*(u16*)(list + 8) != 0) {
            node = fn_8015C1B0(list, 0);
            fn_8015C144(list, node);
            if (lbl_27_bss_8 == 0) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x28, 2);
                if (p != 0) {
                    p = fn_27_362C(p);
                }
                lbl_27_bss_8 = p;
            }
            base = lbl_27_bss_8;
            fn_27_372C(base, ((Class_50*)node)->fn_27_2A9C(), node);
        }
    }
    for (j = 0; j < HOLDER(arg0)->fn_27_FFF0(); j++) {
        item = (char*)HOLDER(arg0)->fn_27_FF68(j);
        fn_27_37D7C(item, *(void**)(item + 0x34), 1, 0);
        if (fn_27_38048(item) == 1) {
            fn_27_37D7C(item, item + 0x28, 1, 0);
        }
    }
    for (k = 0; k < HOLDER(arg0)->fn_27_FFF0(); k++) {
        item2 = (char*)HOLDER(arg0)->fn_27_FF68(k);
        fn_27_37D7C(item2, *(void**)(item2 + 0x38), 1, 0);
        fn_27_37D7C(item2, *(void**)(item2 + 0x3c), 1, 0);
    }
}
}