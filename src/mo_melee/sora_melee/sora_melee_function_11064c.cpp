#pragma force_active on
struct Inner {
    char pad[0xc];
    float lo;
    float hi;
    float scale;
};

struct Obj {
    char pad[0x44];
    Inner* inner;
};

extern "C" float fn_27_11064C(Obj* obj, float a, float b)
{
    Inner* p = obj->inner;
    if (!(b > p->lo)) {
        return a;
    }
    if (!(b < p->hi)) {
        return a;
    }
    return a * p->scale;
}
