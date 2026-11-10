#pragma force_active on
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) : x(a), y(b) {} };
struct Vec3 { float x, y, z; };
struct SpeedFloat { float x, y; };
struct Speed { int x, y; };
struct AttributeFlag { short mask; AttributeFlag(int n) : mask(n) {} };
class KineticEnergy;
struct Kinetic {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual KineticEnergy* getEnergy(int);
 virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual void v11(); virtual void v12(); virtual Speed getSumSpeed(const AttributeFlag&);
};
struct KineticEnergy {
 virtual void v0(); virtual void v1(); virtual SpeedFloat getSpeed(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13();
};
struct Modules { char pad[0x7c]; Kinetic* kinetic; };
struct Accesser { char pad0[8]; void* owner; char pad1[0xcc]; Modules* modules; };
struct Params { char pad[0xc]; void* data; };
struct Values { char pad[4]; float f, g, h; };
extern "C" {
extern const char lbl_107_data_5E0[], lbl_107_data_45B8[], lbl_107_data_8E64[];
extern const char lbl_107_data_3B18[], lbl_107_data_8CA4[];
extern const float lbl_107_rodata_38;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_107_A8C4(void*);
Vec3* fn_107_B444(Vec3*, float, float, float);
void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);
void fn_107_EF04(Vec2*, const Vec2*);
void fn_107_10654(void*, void*, void*, Accesser* a) {
 AttributeFlag flag(1);
 Speed speed;
 Speed first = a->modules->kinetic->getSumSpeed(flag);
 speed = first;
 a->modules->kinetic->v12();
 KineticEnergy* e1 = static_cast<KineticEnergy*>(__dynamic_cast(
 a->modules->kinetic->getEnergy(1), 0, lbl_107_data_8E64, lbl_107_data_3B18, 1));
 KineticEnergy* e2 = static_cast<KineticEnergy*>(__dynamic_cast(
 a->modules->kinetic->getEnergy(3), 0, lbl_107_data_8CA4, lbl_107_data_3B18, 1));
 e2->getSpeed();
 Vec2 gravity(lbl_107_rodata_38, *(float*)&speed.y);
 Vec3 rot1;
 fn_27_89D08(1, a, 0, &gravity,
 fn_107_B444(&rot1, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
 Vec2 motion;
 SpeedFloat ret = e2->getSpeed();
 motion.x = ret.x;
 motion.y = lbl_107_rodata_38;
 Vec3 rot2;
 fn_27_89D08(3, a, 9, &motion,
 fn_107_B444(&rot2, lbl_107_rodata_38, lbl_107_rodata_38, lbl_107_rodata_38));
 void* cr = __dynamic_cast(a->owner, 0x3c, lbl_107_data_5E0, lbl_107_data_45B8, 1);
 Values* v = (Values*)((Params*)fn_107_A8C4(cr))->data;
 *(float*)((char*)e1 + 0x10) = -v->g;
 *(float*)((char*)e1 + 0x1c) = v->h;
 {
 Vec2 limit(v->f, lbl_107_rodata_38);
 fn_107_EF04((Vec2*)((char*)e2 + 0x20), &limit);
 }
}
}
