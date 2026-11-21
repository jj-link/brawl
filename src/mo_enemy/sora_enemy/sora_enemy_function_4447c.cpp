#include <wn/wn_em_simple.h>
#include <em/wnem/wnem_proc_common.h>
#include <types.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Object_vptr_0* slot2();
};

struct Modules {
    char pad[0x18];
    Object_vptr_0* obj;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Data {
    char pad[0x5c];
    float value;
};

extern char lbl_41_data_E544[];
extern char lbl_41_data_E565[];
extern const float lbl_41_rodata_F78[];
extern "C" bool fn_41_31960(wnemSimple*, u32);

extern "C" void fn_41_4447C(wnemSimple* wn, Accesser* acc) {
    const float* limits = lbl_41_rodata_F78;
    bool entering = wn->unk2214;
    wn->unk2214 = false;

    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E544);
        wn->setProcFnc_LifeZero(50);

        if (fn_41_31960(wn, 1))
            wn->setProcFnc_TouchGround(52);

        if (fn_41_31960(wn, 7))
            wn->setProcFnc_HitShell(53);

        if (fn_41_31960(wn, 4)) {
            wn->executeAnimCmd(4U);
            wnemCommonProc::Report(lbl_41_data_E565);
        }

        if (fn_41_31960(wn, 5))
            wn->executeAnimCmd(5U);
    }

    if ((int)acc->modules->obj->slot2()->slot2() != 10000) {
        Data* data = (Data*)wn->unk2184[0];
        if (data) {
            float value = data->value;
            bool valid;

            if (value < limits[3] && value > limits[4])
                valid = true;
            else
                valid = false;

            if (valid) {
                wn->unk2200 = limits[5];
                wn->unk2204 = data->value;
            }
        }
    }
}
