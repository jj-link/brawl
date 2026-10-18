#pragma force_active on
struct Work {
    virtual void s08() = 0;
    virtual void s0c() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual int getInt(int) = 0;
    virtual void setInt(int, int) = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2c() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual float getFloat(int) = 0;
    virtual void setFloat(float, int) = 0;
};

struct Motion {
    virtual void s08() = 0;
    virtual void s0c() = 0;
    virtual void s10() = 0;
    virtual float get() = 0;
};

struct Status {
    virtual void s08() = 0;
    virtual void s0c() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1c() = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2c() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual void s38() = 0;
    virtual void s3c() = 0;
    virtual void s40() = 0;
    virtual void s44() = 0;
    virtual int get() = 0;
};

struct Kinetic {
    virtual void s08() = 0;
    virtual void s0c() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1c() = 0;
    virtual void* get(int) = 0;
};

struct Modules {
    char p0[0x14];
    Motion* motion;
    char p1[0x4c];
    Work* work;
    char p2[8];
    Status* status;
    char p3[8];
    Kinetic* kinetic;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Energy {
    char pad[0x40];
    float value;
};

extern "C" {
const float* fn_109_862C();
extern const unsigned char lbl_109_data_657C[];
extern const unsigned char lbl_109_data_1670[];
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_109_D7DC(void*, Access* a) {
    Work* w = a->modules->work;
    Status* st = a->modules->status;
    int flag = w->getInt(0x20000000);
    a->modules->motion->get();

    switch (st->get()) {
    case 0x115:
        if (flag == 0) {
            int count = w->getInt(0x20000001);
            if (count >= 1) {
                const float* param = fn_109_862C();
                float speed = w->getFloat(0x21000004);
                speed *= param[0];

                Energy* e = static_cast<Energy*>(__dynamic_cast(
                    a->modules->kinetic->get(0), 0,
                    lbl_109_data_657C, lbl_109_data_1670,
                    static_cast<short>(1)));
                e->value = speed;
                w->setFloat(speed, 0x21000004);
                w->setInt(count - 1, 0x20000001);
            }
        }
        break;
    case 0x11e:
        break;
    }
}
}
