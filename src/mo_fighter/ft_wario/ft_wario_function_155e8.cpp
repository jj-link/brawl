#include <so/so_module_accesser.h>
#pragma force_active on
struct Vec2Words { float x, y; };
struct KineticView {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual Vec2Words getSumSpeed(short&);
};
extern "C" {
extern const float lbl_110_rodata_C0[];
float fn_110_1526C(Vec2Words*);
void fn_110_155E8(void*, soModuleAccesser* a) {
    const float* c = lbl_110_rodata_C0;
    const soModuleEnumeration* e = a->m_enumerationStart;
    soWorkManageModule* w = e->m_workManageModule;
    KineticView* k = reinterpret_cast<KineticView*>(e->m_kineticModule);
    soModelModule* m = e->m_modelModule;
    short flag = -1;
    Vec2Words v = k->getSumSpeed(flag);
    float speed = fn_110_1526C(&v);
    float x = w->getFloat(0x21000004);
    float y = w->getFloat(0x21000005);
    float dx, dy;
    if (w->isFlag(0x22000004)) {
        dx = (c[1] * speed) / (c[2] * (c[3] * a->m_enumerationStart->m_postureModule->getScale()));
        w->setFloat(dx, 0x21000006);
    } else {
        float previous = w->getFloat(0x21000006);
        dx = previous * c[4];
        w->setFloat(dx, 0x21000006);
    }
    if (w->isFlag(0x22000005)) {
        dy = (c[1] * speed) / (c[2] * (c[5] * a->m_enumerationStart->m_postureModule->getScale()));
        w->setFloat(dy, 0x21000007);
    } else {
        dy = w->getFloat(0x21000007);
    }
    x += dx;
    y += dy;
    if (x > c[1]) x -= c[1];
    if (y > c[1]) y -= c[1];
    m->setNodeRotateX(0x11, y);
    m->setNodeRotateX(0x17, x);
    w->setFloat(y, 0x21000005);
    w->setFloat(x, 0x21000004);
}
}