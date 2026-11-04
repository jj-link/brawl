#pragma force_active on
#pragma fp_contract on
struct Data {
    float x,y,z,w;
    float radius;
    int a,b;
    char pad[0x1c];
    int c;
};
struct Transform { float m[3][4]; };
struct Input { int a,b; Transform* transform; };
class Class_80487388 {
public:
    virtual void fn_802CD8B8();
    virtual void fn_802CD950();
    virtual void fn_802CD9B0();
    virtual void fn_802CD9DC();
    virtual void fn_802D0890();
    virtual unsigned int fn_802CE094(void*, Data*);
};
class Class_80487490 {
public:
    virtual void fn_802D0AD4(Input*, Data*);
    virtual void fn_802D1434();
    virtual void fn_802D0BDC();
    virtual void fn_802D0BE4();
    virtual void fn_802D0D10();
    virtual void fn_802D0D80();
    float radius;
};
extern "C" void fn_802D0914(Class_80487388* obj, void* arg, Input* input, Class_80487490* target) {
    __declspec(align(16)) Data data;
    data.radius = 1.0f;
    data.a = -1;
    data.c = 0;
    data.b = -1;
    data.radius = target->radius;
    if ((signed char)(obj->fn_802CE094(arg, &data) >> 24)) {
        Transform* t = input->transform;
        float z = data.z, y = data.y, x = data.x;
        data.x = x*t->m[0][0] + y*t->m[1][0] + z*t->m[2][0];
        data.y = x*t->m[0][1] + y*t->m[1][1] + z*t->m[2][1];
        data.z = x*t->m[0][2] + y*t->m[1][2] + z*t->m[2][2];
        data.w = 0.0f;
        target->fn_802D0AD4(input, &data);
    }
}
