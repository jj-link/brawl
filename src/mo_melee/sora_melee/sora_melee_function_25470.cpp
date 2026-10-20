#include <types.h>
#pragma force_active on

class fn_27_25470Base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual float getValue();
    virtual void v32(); virtual void v33();
};

struct fn_27_25470Inner {
    u8 pad[0x54];
    fn_27_25470Base* m_54;
};

struct fn_27_25470Mid {
    u8 pad[0xd8];
    fn_27_25470Inner* m_d8;
};

struct fn_27_25470Outer {
    u8 pad[0x8];
    fn_27_25470Mid* m_08;
    u8 pad2[0x3c - 0x0c];
    float m_3c;
};

extern "C" {
float fn_27_25470(const fn_27_25470Outer* self) {
    return self->m_3c * self->m_08->m_d8->m_54->getValue();
}
}
