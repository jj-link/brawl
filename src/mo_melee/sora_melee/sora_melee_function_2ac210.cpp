#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" void* getTask__6gfTaskFi(int);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" unsigned int fn_27_28FE04(void*);
extern "C" u32 lbl_27_data_4A000[];
extern "C" u32 __RTTI__6gfTask[];

struct TaskTypeField {
    unsigned int : 17;
    signed int type : 8;
    unsigned int : 7;
};

extern "C" u32 fn_27_2AC210(u32 p1, u32 p2) {
    void* p = getTask__6gfTaskFi((int)p2);
    if (p) {
        TaskTypeField* tf = (TaskTypeField*)((char*)p + 0x2C);
        if (tf->type == 0x0B) {
            p = __dynamic_cast(p, 0x3C, (const void*)lbl_27_data_4A000, (const void*)__RTTI__6gfTask, 0);
            if (p && *(s32*)((char*)p + 0x8C0) == 0x48) {
                return (u32)__cntlzw(fn_27_28FE04(p)) >> 5;
            }
        }
    }
    return 0;
}
