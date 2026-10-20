#pragma force_active on

class Obj {
public:
    char pad[0x3C];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
};

extern "C" {
extern void* lbl_2_bss_58;
extern int lbl_2_data_5220;
extern void* lbl_2_bss_68;
extern char lbl_2_data_5224[];
extern char lbl_2_data_5258[];
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);

void* fn_2_3CC18(void* param1, void* param2) {
    void* task = lbl_2_bss_58;
    if (task != 0) {
        return task;
    }
    lbl_2_data_5220 = (int)param1;
    task = __nw__FUlQ25Heaps8HeapType(0x40, (int)param1);
    if (task != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, (const char*)lbl_2_data_5224, 0, 14, 6, true);
        *(void**)((char*)task + 0x3C) = lbl_2_data_5258;
    }
    lbl_2_bss_58 = task;
    lbl_2_bss_68 = param2;
    Obj* obj = (Obj*)task;
    obj->v21();
    return lbl_2_bss_58;
}
}
