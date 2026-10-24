#include <types.h>
#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct RotInfo {
    u8 pad0[0x2C];
    float f2C;
    u8 pad1[0x0C];
    float f3C;
    float f40;
    float f44;
    float f48;
};

struct grGimmick {
    u8 pad0[0x3C];
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
    virtual RotInfo* getInfo();
    u8 pad1[0x1DC - 0x40];
    float m_1DC;
};

extern "C" void getRot__9grGimmickFv(Vec3f* out, void* self);
extern "C" void setRot__9grGimmickFfff(void* self, float x, float y, float z);
extern "C" const float lbl_74_rodata_138;

extern "C" void fn_74_AFC8(grGimmick* self, float dt) {
    Vec3f cur;
    Vec3f rot;
    RotInfo* r = self->getInfo();

    if (r != 0) {
        float t = self->m_1DC - dt;
        self->m_1DC = t;
        if (t < lbl_74_rodata_138) {
            self->m_1DC = lbl_74_rodata_138;
        }
        getRot__9grGimmickFv(&rot, self);
        cur.x = rot.x;
        cur.y = rot.y;
        cur.z = rot.z;
        if (lbl_74_rodata_138 == self->m_1DC) {
            float a = r->f2C;
            if (cur.z != a) {
                if (cur.z > a) {
                    float t0 = cur.z - r->f48;
                    cur.z = t0;
                    if (t0 < a) {
                        cur.z = a;
                    } else {
                        self->m_1DC = r->f44;
                    }
                } else {
                    float t1 = cur.z + r->f48;
                    cur.z = t1;
                    if (t1 > a) {
                        cur.z = a;
                    } else {
                        self->m_1DC = r->f44;
                    }
                }
            }
        } else {
            if (cur.z < r->f40) {
                cur.z = r->f40;
            }
            if (cur.z > r->f3C) {
                cur.z = r->f3C;
            }
        }
        setRot__9grGimmickFfff(self, cur.x, cur.y, cur.z);
    }
}
