#pragma force_active on
class soVirtBase {
public:
    virtual void vfunc2(short p1, signed char p2);
};

extern "C" {
void fn_27_D5390(soVirtBase* obj, short p1, signed char p2) {
    obj->vfunc2(p1, p2);
}
}
