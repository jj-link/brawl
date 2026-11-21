#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_26B0[];
float fn_27_195388(float, float, float);
}

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual int slot6(int);
    virtual void slot7(); virtual void slot8(); virtual void slot9();
    virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18();
    virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual float slot22();
};

struct Holder {
    char pad0[0x0c];
    Object_vptr_0* posture;
    char pad1[0xb4];
    Object_vptr_0* flags;
};
struct Object {
    char pad[0xd8];
    Holder* holder;
};
#define CALC(BASE, ONE, EXP, VALUE, OUT) \
    if (c[0] == (EXP)) { \
        (OUT) = (BASE); \
    } else if ((EXP) < c[0]) { \
        float e = -(EXP); \
        float v; \
        if (c[0] == e) { \
            v = (ONE); \
        } else if (e < c[0]) { \
            float ee = -e; \
            float w; \
            if (c[0] == ee) { \
                w = (ONE); \
            } else if (ee < c[0]) { \
                w = (ONE) / fn_27_195388((ONE), (VALUE), -ee); \
            } else if ((VALUE) >= (ONE) || ee <= (ONE)) { \
                float neg = -(EXP); \
                float delta = (VALUE) - c[4]; \
                float exponent2 = -neg; \
                float product = delta * c[4]; \
                w = c[4] + exponent2 * product; \
            } else { \
                w = ((ONE) * (VALUE)) / ee; \
            } \
            v = c[4] / w; \
        } else if ((VALUE) >= (ONE) || e <= (ONE)) { \
            float neg = -(EXP); \
            float delta = (VALUE) - c[4]; \
            float product = delta * c[4]; \
            v = c[4] + neg * product; \
        } else { \
            v = ((ONE) * (VALUE)) / e; \
        } \
        (OUT) = (BASE) / v; \
    } else if ((VALUE) >= (ONE) || (EXP) <= (ONE)) { \
        float delta = (VALUE) - c[4]; \
        float product = delta * (BASE); \
        (OUT) = (BASE) + (EXP) * product; \
    } else { \
        (OUT) = ((BASE) * (VALUE)) / (EXP); \
    }

static inline float calculate(float base, float exponent, float value, const float* c) {
    float factor;
    CALC(base, c[4], exponent, value, factor);
    return factor;
}

extern "C" float fn_27_194B34(Object* self) {
    const float* c = lbl_27_rodata_26B0;
    float result = c[4];
    if (self->holder->flags->slot6(0)) {
        float exponent = *(float*)((char*)*(void**)((char*)g_ftCommonData.dataCommon + 0x30) + 8);
        float value = self->holder->posture->slot22();
        result *= calculate(result, exponent, value, c);
    }
    if (self->holder->flags->slot6(1)) {
        float exponent = *(float*)((char*)*(void**)((char*)g_ftCommonData.dataCommon + 0x34) + 8);
        float value = self->holder->posture->slot22();
        result *= calculate(result, exponent, value, c);
    }
    if (result < c[7]) result = c[7];
    else if (result > c[9]) result = c[9];
    return result;
}
