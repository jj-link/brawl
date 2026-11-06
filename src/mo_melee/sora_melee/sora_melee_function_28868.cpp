#include <types.h>
#pragma force_active on

extern "C" int fn_80134344(void* p, u32 idx);
extern "C" u32 fn_80134534(void* p, u32 idx);
extern "C" u32 fn_80134C54(void* p, u32* v);

struct Inner {
    int pad0;
    void* ptr;
};

struct Sub {
    virtual void f0();
    virtual Inner* f3(u32 a);
};

struct Base8 {
    int a;
    int b;
};

struct Self : Base8 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual int v55(u32 flags, u32 zero);
    u8 pad[0x1c];
    Sub* sub;
};

extern "C" void fn_27_28868(Self* self, u32 flags, u32 arg) {
    if (self->v55(flags, 0)) {
        u32 i = 0;
        for (u32 mask = 1; mask <= 0xff; mask <<= 1, i++) {
            if (flags & mask) {
                Inner* in = self->sub->f3(arg);
                if (fn_80134344(in->ptr, i)) {
                    u32 tmp = fn_80134534(self->sub->f3(arg)->ptr, i);
                    fn_80134C54(self->sub->f3(arg)->ptr, &tmp);
                }
            }
        }
    }
}
