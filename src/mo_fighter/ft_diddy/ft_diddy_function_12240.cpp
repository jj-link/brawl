#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual unsigned long long slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(unsigned long);
    virtual void slot7(float);
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(float, unsigned long);
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
    virtual int slot17(unsigned long);
    virtual void slot18(unsigned long);
};

extern "C" {
extern const char lbl_115_data_7444[];
extern const char lbl_115_data_7524[];
extern const char lbl_115_data_2760[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_115_E59C(float);
void fn_8003DC64(float*, float, float*);
float fn_115_127C0(void*, float, float, float, float);
void fn_115_C8BC(void*, float*);
}

extern "C" void fn_115_12240(void* self, soModuleAccesser* accesser) {
    float pool;
    double bias;
    pool = -1.0f;
    pool = 1.0f;
    pool = 0.0f;
    pool = 360.0f;
    pool = 0.01745329238474369f;
    pool = 180.0f;
    bias = 4503601774854144.0;
    float rate;
    float scale;
    float angle;
    float limit;
    float direction;
    float change;

    scale = accesser->getPostureModule().getLr();
    direction = accesser->getControllerModule().getStickX();
    rate = accesser->getControllerModule().getStickY();
    angle = accesser->getWorkManageModule().getFloat(0x21000004);
    limit = soValueAccesser::getConstantFloat(accesser, 0xFC5, 0);

    if ((direction < 0.0f &&
         accesser->getWorkManageModule().isFlag(0x22000018)) ||
        (direction > 0.0f &&
         accesser->getWorkManageModule().isFlag(0x22000019))) {
        change = scale * (direction *
            soValueAccesser::getConstantFloat(accesser, 0xFC8, 0));
        accesser->getWorkManageModule().onFlag(0x22000018);
        accesser->getWorkManageModule().onFlag(0x22000019);
    } else {
        change = angle;
        float threshold = soValueAccesser::getConstantFloat(accesser, 0xFC9, 0);
        if (fn_115_E59C(angle) > threshold) {
            int sign = angle < 0.0f ? -1 : 1;
            direction = static_cast<float>(sign);
            change = soValueAccesser::getConstantFloat(accesser, 0xFC9, 0) * direction;
        }
        change = -change;
    }

    angle += change;
    if (angle < -limit)
        angle = -limit;
    else if (angle > limit)
        angle = limit;

    accesser->getWorkManageModule().setFloat(angle, 0x21000004);

    float temp = angle * soValueAccesser::getConstantFloat(accesser, 0xFC6, 0);
    if (temp < 0.0f)
        temp = 360.0f + temp;
    accesser->getWorkManageModule().setFloat(temp, 0x21000005);

    float wrapped = (angle / limit) *
        soValueAccesser::getConstantFloat(accesser, 0xFC7, 0);
    wrapped *= scale;
    if (wrapped < 0.0f)
        wrapped = 360.0f + wrapped;
    accesser->getWorkManageModule().setFloat(wrapped, 0x21000006);

    void* first = __dynamic_cast(
        accesser->getKineticModule().getEnergy(3), 0,
        lbl_115_data_7444, lbl_115_data_2760, 1);
    void* second = __dynamic_cast(
        accesser->getKineticModule().getEnergy(1), 0,
        lbl_115_data_7524, lbl_115_data_2760, 1);

    float base = soValueAccesser::getConstantFloat(accesser, 0xFBF, 0);
    if (rate > 0.0f) {
        base += rate * soValueAccesser::getConstantFloat(accesser, 0xFC1, 0);
    } else if (rate < 0.0f) {
        base += rate * soValueAccesser::getConstantFloat(accesser, 0xFC2, 0);
    } else {
        accesser->getMotionModule().setRate(1.0f);
    }

    float phase = fn_115_E59C(angle / limit);
    float contribution = soValueAccesser::getConstantFloat(accesser, 0xFC0, 0);
    contribution *= phase;
    base += contribution;

    float pair[2];
    pair[0] = 0.0f;
    pair[1] = base;
    if (fn_115_E59C(angle) > 0.0f) {
        angle *= scale;
        if (angle < 0.0f)
            angle += 360.0f;
        fn_8003DC64(pair, 0.01745329238474369f * (360.0f - angle), pair);
    }

    float value = 180.0f + temp * scale;
    if (value > 360.0f)
        value -= 360.0f;
    else if (value < 0.0f)
        value += 360.0f;

    accesser->getWorkManageModule().setFloat(value, 0x21000007);
    *reinterpret_cast<float*>(reinterpret_cast<char*>(second) + 0x10) =
        pair[1] - soValueAccesser::getConstantFloat(accesser, 0xFBC, 0);

    unsigned long long got =
        reinterpret_cast<Object_vptr_0*>(first)->slot2();
    union {
        unsigned long long u;
        struct {
            unsigned int lo;
            unsigned int hi;
        } words;
    } ret;
    ret.u = got;

    float out = fn_115_127C0(
        self, *reinterpret_cast<float*>(&ret.words.lo), pair[0],
        soValueAccesser::getConstantFloat(accesser, 0xFCA, 0),
        soValueAccesser::getConstantFloat(accesser, 0xFCB, 0));
    float outPair[2];
    outPair[0] = out;
    outPair[1] = 0.0f;
    fn_115_C8BC(reinterpret_cast<char*>(first) + 8, outPair);
}
