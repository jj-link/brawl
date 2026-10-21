#pragma force_active on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };

class VFace {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6(int);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
Vec3* fn_107_B444(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
void fn_107_EF04(Vec2*, const Vec2*);
extern char g_ftCommonDataAccesser[];
extern char lbl_107_data_3B18[], lbl_107_data_8DD0[];
extern const float lbl_107_rodata_38;
}

extern "C" void fn_107_114E4(void* a3, void* a4, Vec2* a5, void* a6) {
    char* r30 = *(char**)((char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12) + 0xb8);
    Vec3 rot;
    fn_27_89D08(0, a6, 2, a5, fn_107_B444(&rot, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
    VFace* m = *(VFace**)(*(char**)((char*)a6 + 0xd8) + 0x7c);
    void* ret = m->f6(0);
    void* obj = __dynamic_cast(ret, 0, lbl_107_data_8DD0, lbl_107_data_3B18, 1);
    Vec2 v;
    v.x = *(float*)(r30 + 0xc);
    v.y = lbl_107_rodata_38;
    fn_107_EF04((Vec2*)((char*)obj + 0x20), &v);
}
