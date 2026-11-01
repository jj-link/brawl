#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" void* getTask__6gfTaskFi(s32);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" s32 getStatusKind__23soExternalValueAccesserFP11StageObject(void*);
extern "C" char lbl_27_data_69C0[];
extern "C" char __RTTI__6gfTask[];

class VObj {
public:
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
    virtual void call(u32 a);
};

struct TaskTypeField {
    unsigned int : 17;
    signed int type : 8;
    unsigned int : 7;
};

struct Arg2 { u32 pad0[0x18]; void* middle; };

extern "C" s32 fn_27_29BAD8(void* p1, Arg2* p2, const s32* p3) {
    s32 id = p3[3];
    void* mid = p2->middle;
    void* inr = *(void**)((char*)mid + 0xD8);
    VObj* y = (VObj*)*(void**)((char*)inr + 0x64);
    void* task = getTask__6gfTaskFi(id);
    if (task == 0 || ((TaskTypeField*)((char*)task + 0x2C))->type != 0xA) {
        y->call(0x22000005);
        return 0;
    }
    void* c = __dynamic_cast(task, 0x3C, (const void*)lbl_27_data_69C0, (const void*)__RTTI__6gfTask, 0);
    if (c == 0 || getStatusKind__23soExternalValueAccesserFP11StageObject(c) == 0x102) {
        y->call(0x22000005);
        return 0;
    }
    return 1;
}
