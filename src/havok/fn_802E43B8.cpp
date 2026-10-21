#pragma force_active on
class A {
public:
    virtual void v0(float);
    virtual void v1(float);
    virtual void v2(float);
    virtual void v3(float);
};
extern "C" void fn_802E43B8(void* obj, float val) {
    extern float lbl_805A43B0;
    extern float lbl_805A43B4;
    float result;
    if (lbl_805A43B0 == val)
        result = lbl_805A43B0;
    else
        result = lbl_805A43B4 / val;
    ((A*)obj)->v3(result);
}