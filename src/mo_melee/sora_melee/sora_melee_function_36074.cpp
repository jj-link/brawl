#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_362C(void*);
void* fn_27_36D0(void*, int);
void fn_27_372C(void*, int, void*);
void fn_8015BFB4(void*, void*);
void fn_8015C024(void*, int, void*);
void fn_8015C144(void*, void*);
void* fn_8015C1B0(void*, void*);
void* fn_8015C1EC(void*, unsigned short);
extern void* lbl_27_bss_8;
}

class Manager {
public:
    virtual void slot0();
    virtual char* get(int);
};

struct Class_A0_base {
    char pad[0x30];
};

class Class_A0 : public Class_A0_base {
public:
    virtual int fn_27_2AE0();
    virtual int fn_27_3624();
};

extern "C" int fn_27_36074(char* self, int index, int target, int ctx) {
    Manager* mgr = (Manager*)*(void**)(self + 8);
    char* obj = mgr->get(ctx);
    unsigned short count = *(unsigned short*)(obj + 0x24);
    char* list = obj + 0x1C;

    if (index < (int)count) {
        mgr = (Manager*)*(void**)(self + 8);
        char* item = mgr->get(ctx);
        item = (char*)fn_8015C1EC(item + 0x1C, (unsigned short)index);
        int value = ((Class_A0*)item)->fn_27_3624();
        if (value == target) {
            return 0;
        }

        int position = (int)fn_8015C1B0(list, fn_8015C1EC(list, (unsigned short)index));
        mgr = (Manager*)*(void**)(self + 8);
        char* node = mgr->get(ctx);
        node = (char*)fn_8015C1EC(node + 0x1C, (unsigned short)index);
        mgr = (Manager*)*(void**)(self + 8);
        fn_8015C144(mgr->get(ctx) + 0x1C, node);

        if ((int)lbl_27_bss_8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x28, 2);
            if (p != 0) {
                p = fn_27_362C(p);
            }
            lbl_27_bss_8 = p;
        }
        fn_27_372C(lbl_27_bss_8, value, node);

        if ((int)lbl_27_bss_8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x28, 2);
            if (p != 0) {
                p = fn_27_362C(p);
            }
            lbl_27_bss_8 = p;
        }
        fn_8015C024(list, position, fn_27_36D0(lbl_27_bss_8, target));
        return 1;
    }

    index += 1;
    for (int j = count; j < index; ++j) {
        if ((int)lbl_27_bss_8 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x28, 2);
            if (p != 0) {
                p = fn_27_362C(p);
            }
            lbl_27_bss_8 = p;
        }
        fn_8015BFB4(list, fn_27_36D0(lbl_27_bss_8, target));
    }
    return 0;
}
