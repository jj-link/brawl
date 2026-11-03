#pragma always_inline on
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

struct V2 { float x, y; };
struct Words { int x, y; };
union Pair { V2 vec; Words bits; };

class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual Words slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
};
struct Data { int type; float kind; char pad[28]; float angle; };
extern "C" {
extern float lbl_41_rodata_C38[];
float fn_41_10830(V2*);
Words fn_41_108CC(V2*, float);
void fn_41_1592C(V2*, Words*);
Data* fn_41_15964(void*, int);
float fn_41_15A00(float, V2*);
soAnimCmdEventObserver* fn_41_15FD4(void*, int);
void fn_41_1627C(void*, int, int, Data*, bool, bool, float, int, float, float);
int fn_41_1794C(void*, int);
void fn_41_17C30(void*, int);
unsigned int fn_41_1AE7C(soAnimCmdEventObserver*);
int fn_41_1C1D4(soAnimCmdEventObserver*, void*);
unsigned int fn_41_1C2BC(soAnimCmdEventObserver*, void*, int);
unsigned int fn_41_1C414(soAnimCmdEventObserver*, void*, V2*);
void fn_41_1C610(soAnimCmdEventObserver*, V2*, float);
void fn_41_1CC18(soAnimCmdEventObserver*);

void fn_41_16CFC(char* self, int id, int param, int arg3, int arg4) {
    float* base = lbl_41_rodata_C38;
    V2 sum = {base[1], base[1]};
    V2 out = {base[1], base[1]};
    for (int i = 0; i < 8; ++i) {
        soAnimCmdEventObserver* unit = fn_41_15FD4(self, i);
        if (fn_41_1AE7C(unit) != 1 && fn_41_1C1D4(unit, *(void**)(self + 0x20))) {
            unsigned int flag = fn_41_1C2BC(unit, *(void**)(self + 0x20), 1);
            Words value = unit->slot2();
            fn_41_1592C(&sum, &value);
            if (flag == 1)
                fn_41_1CC18(unit);
        }
    }
    if (base[1] != fn_41_10830(&sum) && fn_41_1794C(self, id)) {
        Data* data = fn_41_15964(self, param);
        if ((data->type == 0 || data->type == 8 || data->type == 9 || data->type == 10 || data->type == 11 || data->type == 12 || data->type == 13) &&
            (base[13] == data->kind || base[14] == data->kind || base[15] == data->kind)) {
            if (arg4 == 0) {
                Words value = fn_41_108CC(&sum, base[0]);
                out.x = *(float*)&value.x;
                out.y = *(float*)&value.y;
            } else {
                out = sum;
                float ay = (float)(double)nw4r::math::FAbs((float)out.y);
                float ax = (float)(double)nw4r::math::FAbs((float)out.x);
                if (ax >= ay)
                    out.x = (float)out.x * base[0];
                else
                    out.y = (float)out.y * base[0];
            }
            float angle = data->angle;
            if (base[14] == angle) {
                soNullable* module = *(soNullable**)(*(char**)(*(char**)(self + 0x20) + 0xD8) + 0xC);
                float value = module->slot9();
                V2 copy = out;
                angle = fn_41_15A00(value, &copy);
            }
            for (int i = 0; i < 8; ++i) {
                soAnimCmdEventObserver* unit = fn_41_15FD4(self, i);
                if (fn_41_1AE7C(unit) != 1 && fn_41_1C1D4(unit, *(void**)(self + 0x20)) &&
                    fn_41_1C414(unit, *(void**)(self + 0x20), &out) == 1)
                    fn_41_1CC18(unit);
            }
            fn_41_17C30(self, id);
            fn_41_1C610(fn_41_15FD4(self, id), &out, angle);
            fn_41_1627C(self, id, param, data, 0, 0, angle, arg3, base[0], base[1]);
        }
    }
}
}