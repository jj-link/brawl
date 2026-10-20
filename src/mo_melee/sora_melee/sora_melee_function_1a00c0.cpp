#pragma force_active on
struct A { int _0; char _4[4]; unsigned _8; };
extern "C" int fn_27_1A00C0(const A* p) {
    return (p->_8 >> 25) & 1;
}
