#pragma force_active on
struct Obj {
    char pad0[0x2c]; float value; float other; char pad34[0xf];
    unsigned char flag; float rate; char pad48[0x10]; int count;
};
struct Arg { Obj* obj; char pad[4]; float value; };
extern "C" float fn_8016017C(Obj*);
extern "C" float fn_8015F814(Obj*);
extern "C" int fn_8015C578(void*, int code, Arg* arg) {
    switch (code) {
    case 10: {
        Obj* obj = arg->obj;
        float value = arg->value;
        float other = obj->other;
        float result = other + fn_8016017C(obj);
        obj->value = value;
        obj->other = result;
        return 3;
    }
    case 9: {
        Obj* obj = arg->obj;
        int count = obj->count;
        if (count > 0) {
            float rate;
            if (obj->flag) rate = obj->rate;
            else rate = fn_8015F814(obj);
            float difference = obj->value - arg->value;
            float step = (float)count * rate;
            obj->value = arg->value + step * (float)((int)(difference / step) + 1);
        }
        return 1;
    }
    default: return 0;
    }
}