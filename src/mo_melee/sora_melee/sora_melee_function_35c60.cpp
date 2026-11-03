#include <types.h>
#pragma force_active on

class ListNodeBase {
public:
    char pad[0x30];
};

class ListNode : public ListNodeBase {
public:
    virtual void slot0();
    virtual int getKey();
};

class ItemHolder {
public:
    virtual void slot0();
    virtual void* getItem(int index);
    virtual void slot2();
    virtual int getCount();
};

#define HOLDER(p) (*(ItemHolder**)((char*)(p) + 8))

extern "C" {

extern void* lbl_27_bss_8;

void __dl__FPv(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_362C(void*);
void fn_27_372C(void*, int, void*);
void fn_27_37D7C(void*, void*, s32, s32);
u32 fn_27_38048(void*);
void* fn_8015C1B0(void*, void*);
void fn_8015C144(void*, void*);

void* fn_27_35C60(void* arg0, s32 arg1) {
    void* base;
    void* node;
    char* list;
    s32 i;

    if (arg0 != 0) {
        for (i = 0; i < HOLDER(arg0)->getCount(); i++) {
            list = (char*)HOLDER(arg0)->getItem(i) + 0x1c;
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
                fn_27_372C(base, ((ListNode*)node)->getKey(), node);
            }
        }
        for (i = 0; i < HOLDER(arg0)->getCount(); i++) {
            char* item = (char*)HOLDER(arg0)->getItem(i);
            fn_27_37D7C(item, *(void**)(item + 0x34), 1, 0);
            if (fn_27_38048(item) == 1) {
                fn_27_37D7C(item, item + 0x28, 1, 0);
            }
        }
        for (i = 0; i < HOLDER(arg0)->getCount(); i++) {
            char* item = (char*)HOLDER(arg0)->getItem(i);
            fn_27_37D7C(item, *(void**)(item + 0x38), 1, 0);
            fn_27_37D7C(item, *(void**)(item + 0x3c), 1, 0);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
