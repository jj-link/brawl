#pragma force_active on
extern float lbl_805A1958;
extern double lbl_805A1960;
class FnVt { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(float); virtual void v6(); virtual void v7(); virtual void v8(float); };
struct FnInner { char pad[0x10]; FnVt* m_10; };
struct FnSelf { char pad[0x48]; FnInner* m_48; char pad2[0x56 - 0x4C]; unsigned short m_56; };
extern "C" void fn_80063498(FnSelf* self, unsigned int arg1) {
    FnInner* inner = self->m_48;
    if (inner != 0 && inner->m_10 != 0) {
        unsigned short flags = self->m_56;
        float c = lbl_805A1958;
        self->m_56 = flags | 8;
        inner->m_10->v8(c);
        FnInner* next = self->m_48;
        next->m_10->v5((float)arg1);
    }
}