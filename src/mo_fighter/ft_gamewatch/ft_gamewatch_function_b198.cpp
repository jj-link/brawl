#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <math.h>

#pragma force_active on

struct Work {
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
    virtual float getFloat(unsigned long);
    virtual void v13();
    virtual void v14();
    virtual void setFloat(float, unsigned long);
    virtual void v15();
    virtual bool isFlag(unsigned long);
    virtual void onFlag(unsigned long);
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void change(int, void*);
};

struct Base {
    int a, b;
};

struct Model : Base {
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
    virtual Vec3f position(int, Vec3f*, bool, bool);
};

struct Effect {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void create(int, Vec3f*, Vec3f*, float, int, int);
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
    virtual void set(int, float);
};

struct Modules {
    char p0[4];
    Model* model;
    char p1[0x5c];
    Work* work;
    char p2[8];
    Status* status;
    char p3[0x14];
    Effect* effect;
};

struct Access {
    char p[0xd8];
    Modules* modules;
};

extern "C" {
extern const float lbl_107_rodata_0[];
Vec3f* fn_107_B444(Vec3f*, float, float, float);
Vec3f* fn_107_B454(Vec3f*, const void*);
}

extern "C" void fn_107_B198(char* self, float amount, int unused,
                            char* input, int flag, Access* access) {
    const float* c = lbl_107_rodata_0;
    if (flag == 0) {
        Work* work = access->modules->work;
        Status* status = access->modules->status;
        if (work->getFloat(0x11000013) < c[8]) {
            float* param = *(float**)(*(char**)(self + 0x1fdb8) + 0x88);
            float value = amount * param[5];
            if (value > param[7])
                value = param[7];

            work->setFloat(value, 0x11000014);
            work->setFloat(c[1], 0x11000013);
            status->change(0x11a, access);

            Vec3f offset;
            fn_107_B444(&offset, c[3], c[9], c[10]);
            Vec3f pos = access->modules->model->position(0x1d, &offset, 0, 0);
            Vec3f diff;
            Vec3f rot;
            Vec3f tmp;
            Vec3fSub(&diff, &pos, fn_107_B454(&tmp, input + 0x10));

            double x = diff.m_x;
            double y = diff.m_y;
            float angle = atan2(y, x);
            rot.m_x = c[3];
            rot.m_y = c[3];
            rot.m_z = angle;

            float sq = diff.m_z * diff.m_z +
                       (diff.m_x * diff.m_x + diff.m_y * diff.m_y);
            float len;
            if ((float)(double)nw4r::ut::Abs(sq) <= c[11])
                len = c[3];
            else
                len = sq * rsqrtf(sq);

            float scale = len / c[0];
            Effect* effect = access->modules->effect;
            Vec3f tmp2;
            effect->create(0x7a, fn_107_B454(&tmp2, input + 0x10),
                           &rot, scale, 0, -1);

            if (work->getFloat(0x11000013) >= c[8] &&
                !work->isFlag(0x1200003d)) {
                work->onFlag(0x1200003d);
                access->modules->effect->set(0x1a, c[3]);
            }
        }
    }
}
