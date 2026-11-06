#pragma force_active on
#pragma opt_propagation off
#pragma optimization_level 3
#pragma opt_space on
#pragma peephole off
#pragma opt_common_subs off
#pragma opt_lifetimes off

typedef unsigned int u32;
typedef signed char* (*VFn)(signed char*, int, int);

signed char* fn_8027EA20(signed char* self, int arg, int align) {
    signed char* base;
    void* head;

    if (arg > 0x2000)
        goto tail6;
    if (*(int*)(self + 0x24) == 0)
        goto tail6;

    if (arg <= 0x200) {
        signed char* p = self + arg;
        arg = p[0xf4];
    } else {
        arg = *(int*)(self + 0x2f8 + (((arg - 1) >> 10) << 2));
    }

    base = self + arg * 4;
    head = *(void**)(base + 0x28);
    if (head != 0) {
        *(int*)(base + 0x6c) = *(int*)(base + 0x6c) - 1;
        *(void**)(base + 0x28) = *(void**)head;
        return (signed char*)head;
    }

    self = *(signed char**)(self + 4);
    {
        VFn fn = *(VFn*)self;
        fn = *(VFn*)((char*)fn + 0x20);
        return fn(self, arg, align);
    }

tail6:
    self = *(signed char**)(self + 4);
    {
        VFn fn = *(VFn*)self;
        fn = *(VFn*)((char*)fn + 0x18);
        return fn(self, arg, align);
    }
}
