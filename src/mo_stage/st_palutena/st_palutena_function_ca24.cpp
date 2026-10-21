#include <types.h>
#pragma force_active on

struct Vec3f {
    float x, y, z;
};

extern "C" void startup__9grGimmickFP9gfArchiveUlUl(void*);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);

class Gimmick {
    char pad[0x3c];
public:
    virtual Vec3f* f0() = 0;
    virtual Vec3f* f1() = 0;
    virtual Vec3f* f2() = 0;
    virtual Vec3f* f3() = 0;
    virtual Vec3f* f4() = 0;
    virtual Vec3f* f5() = 0;
    virtual Vec3f* f6() = 0;
    virtual Vec3f* f7() = 0;
    virtual Vec3f* f8() = 0;
    virtual Vec3f* f9() = 0;
    virtual Vec3f* f10() = 0;
    virtual Vec3f* f11() = 0;
    virtual Vec3f* f12() = 0;
    virtual Vec3f* f13() = 0;
    virtual Vec3f* f14() = 0;
    virtual Vec3f* f15() = 0;
    virtual Vec3f* f16() = 0;
    virtual Vec3f* f17() = 0;
    virtual Vec3f* f18() = 0;
    virtual Vec3f* f19() = 0;
    virtual Vec3f* f20() = 0;
    virtual Vec3f* f21() = 0;
    virtual Vec3f* f22() = 0;
    virtual Vec3f* f23() = 0;
    virtual Vec3f* f24() = 0;
    virtual Vec3f* f25() = 0;
    virtual Vec3f* f26() = 0;
    virtual Vec3f* f27() = 0;
    virtual Vec3f* f28() = 0;
    virtual Vec3f* f29() = 0;
    virtual Vec3f* f30() = 0;
    virtual Vec3f* f31() = 0;
    virtual Vec3f* f32() = 0;
    virtual Vec3f* f33() = 0;
    virtual Vec3f* f34() = 0;
    virtual Vec3f* f35() = 0;
    virtual Vec3f* f36() = 0;
    virtual Vec3f* f37() = 0;
    virtual Vec3f* f38() = 0;
    virtual Vec3f* f39() = 0;
    virtual Vec3f* f40() = 0;
    virtual Vec3f* f41() = 0;
    virtual Vec3f* f42() = 0;
    virtual Vec3f* f43() = 0;
    virtual Vec3f* f44() = 0;
    virtual Vec3f* f45() = 0;
    virtual Vec3f* f46() = 0;
    virtual Vec3f* f47() = 0;
    virtual Vec3f* f48() = 0;
    virtual Vec3f* f49() = 0;
    virtual Vec3f* f50() = 0;
    virtual Vec3f* f51() = 0;
    virtual Vec3f* f52() = 0;
    virtual Vec3f* f53() = 0;
    virtual Vec3f* f54() = 0;
    virtual Vec3f* f55() = 0;
    virtual Vec3f* f56() = 0;
    virtual Vec3f* f57() = 0;
    virtual Vec3f* f58() = 0;
    virtual Vec3f* f59() = 0;
    virtual Vec3f* f60() = 0;
    virtual Vec3f* f61() = 0;
    virtual Vec3f* f62() = 0;
    virtual Vec3f* f63() = 0;
    virtual Vec3f* f64() = 0;
    virtual Vec3f* f65() = 0;
    virtual Vec3f* f66() = 0;
    virtual Vec3f* f67() = 0;
    virtual Vec3f* f68() = 0;
    virtual Vec3f* f69() = 0;
    virtual Vec3f* f70() = 0;
    virtual Vec3f* f71() = 0;
    virtual Vec3f* f72() = 0;
    virtual Vec3f* f73() = 0;
    virtual Vec3f* f74() = 0;
    virtual Vec3f* f75() = 0;
    virtual Vec3f* f76() = 0;
    virtual Vec3f* f77() = 0;
    virtual Vec3f* f78() = 0;
    virtual Vec3f* f79() = 0;
    virtual Vec3f* f80() = 0;
    virtual Vec3f* f81() = 0;
    char pad2[0x10c];
    Vec3f* m_pos;
};

extern "C" void fn_67_CA24(Gimmick* self) {
    startup__9grGimmickFP9gfArchiveUlUl(self);
    self->m_pos = self->f81();
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 0xf);
    setCalcuCallbackRoot__9grGimmickFUl(self, 1);
    Vec3f local;
    float x, y, z;
    z = self->m_pos->z;
    y = self->m_pos->y;
    x = self->m_pos->x;
    local.x = x;
    local.y = y;
    local.z = z;
    setPos__9grGimmickFP5Vec3f(self, &local);
}
