#include <types.h>

#pragma force_active on

extern "C" int fn_27_1922CC(void*, unsigned long);

class Inner {
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
    virtual s32 v14(s32, s32);
    virtual void v15();
    virtual void v16();
    virtual void v17(s32, s32, s32);
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
    virtual s32 v54();
};

class Other {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 v4(s32);
};

struct Mid {
    void* pad[7];
    Inner* inner;
    void* pad2[17];
    Other* other;
};

struct Outer {
    void* pad[0x36];
    Mid* mid;
};

inline s32 calculateValue(Outer* self, s32 offset) {
    s32 value = fn_27_1922CC(self, 0x5dc1);
    value += offset;
    return value;
}

extern "C" void fn_27_34E23C(void* unused, void* arg) {
    Other* other;
    Outer* self = (Outer*)arg;
    Mid* mid = self->mid;
    other = mid->other;
    s32 value = calculateValue(self, (other->v4(0x20000000) / 30) * (fn_27_1922CC(self, 0x5dc2)));

    for (s32 i = 0; i < self->mid->inner->v54(); i++) {
        if (self->mid->inner->v14(i, 0) != 0) {
            self->mid->inner->v17(i, value, 0);
        }
    }
}
