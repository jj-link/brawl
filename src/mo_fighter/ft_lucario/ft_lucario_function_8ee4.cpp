#pragma force_active on
typedef unsigned char u8;
extern "C" float fn_118_8F8C(float, float, float);
extern "C" const float lbl_118_rodata_C;
extern "C" const float lbl_118_rodata_4;
class Class_63D0 {
public:
virtual void fn_118_D9F0();
virtual void fn_118_D72C();
virtual void fn_118_D92C();
virtual void fn_118_D9EC();
virtual void fn_118_D9E8();
virtual void fn_118_D9E4();
virtual void fn_118_D9E0();
virtual void fn_118_D790();
virtual void fn_118_D9DC();
virtual void fn_118_D94C();
virtual void fn_118_D9D8();
virtual void fn_118_D9D0();
virtual float fn_118_D9CC(unsigned int);
};
extern "C" float fn_118_8EE4(void* object) {
    u8* self = static_cast<u8*>(object);
    float* p = *reinterpret_cast<float**>(*reinterpret_cast<u8**>(self + 0x10544) + 0x80);
    Class_63D0* obj = *reinterpret_cast<Class_63D0**>(*reinterpret_cast<u8**>(*reinterpret_cast<u8**>(self + 0x60) + 0xD8) + 0x64);
    float value = obj->fn_118_D9CC(0x11000013);
    float t = lbl_118_rodata_4 - fn_118_8F8C((value - p[1]) / (p[3] - p[1]), lbl_118_rodata_C, lbl_118_rodata_4);
    return p[0] + (p[2] - p[0]) * (lbl_118_rodata_4 - t * t);
}