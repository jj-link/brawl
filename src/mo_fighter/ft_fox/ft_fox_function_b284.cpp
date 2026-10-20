#pragma force_active on
typedef unsigned int u32;

struct Pad {
    u32 a;
    u32 b;
};

class Obj : public Pad {
public:
    virtual u32 v00(u32 a, u32 b);
    virtual u32 v01(u32 a, u32 b);
    virtual u32 v02(u32 a, u32 b);
    virtual u32 v03(u32 a, u32 b);
    virtual u32 v04(u32 a, u32 b);
    virtual u32 v05(u32 a, u32 b);
    virtual u32 v06(u32 a, u32 b);
    virtual u32 v07(u32 a, u32 b);
    virtual u32 v08(u32 a, u32 b);
    virtual u32 v09(u32 a, u32 b);
    virtual u32 v10(u32 a, u32 b);
    virtual u32 v11(u32 a, u32 b);
    virtual u32 v12(u32 a, u32 b);
    virtual u32 v13(u32 a, u32 b);
    virtual u32 v14(u32 a, u32 b);
    virtual u32 v15(u32 a, u32 b);
    virtual u32 v16(u32 a, u32 b);
    virtual u32 v17(u32 a, u32 b);
    virtual u32 v18(u32 a, u32 b);
    virtual u32 v19(u32 a, u32 b);
    virtual u32 v20(u32 a, u32 b);
    virtual u32 v21(u32 a, u32 b);
    virtual u32 v22(u32 a, u32 b);
};

extern "C" u32 fn_97_B284(Obj* self, u32 a, u32 b) {
    u32 result = self->v22(a, b);
    if (result == 1) {
        self->v20(a, b);
    }
    return result;
}
