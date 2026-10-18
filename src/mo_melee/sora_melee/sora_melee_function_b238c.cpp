#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern "C" void fn_27_B4844(void* self);

class Arr {
public:
    virtual void f0() = 0;
    virtual u8& at(s32) = 0;
    virtual void f2() = 0;
    virtual s32 size() = 0;
};

class Obj {
public:
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    char pad[20];
    Arr* m_arr;
};

extern "C" void fn_27_B238C(Obj* self) {
    fn_27_B4844(self);
    s32 count = self->m_arr->size();
    for (s32 i = 0; i < count; i++) {
        self->m_arr->at(i) |= 0x80;
    }
    self->m8();
}