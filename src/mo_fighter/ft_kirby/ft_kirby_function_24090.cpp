#pragma force_active on
struct Vec2f {
    float x, y;
};

class EnergyModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned long);
    virtual void setFloat(float, unsigned long);
};

class PostureModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getLr();
};

extern "C" {
extern const char lbl_96_data_CEF4[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_548;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_B890(Vec2f*, const Vec2f*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
double cos(double);
double sin(double);

void fn_96_24090(void*, char* self) {
    char* modules = *(char**)(self + 0xd8);
    WorkModule* work = *(WorkModule**)(modules + 0x64);
    EnergyModule* kinetic = *(EnergyModule**)(modules + 0x7c);
    char* energy = (char*)__dynamic_cast(
        kinetic->getEnergy(0), 0,
        lbl_96_data_CEF4, lbl_96_data_5E00, 1);

    float angle = work->getFloat(0x11000001);
    float magnitude = work->getFloat(0x11000002);
    float facing =
        (*(PostureModule**)(*(char**)(self + 0xd8) + 0xc))->getLr();

    Vec2f speed;
    float cosine = cos(angle);
    speed.x = facing * (magnitude * cosine);
    float sine = sin(angle);
    speed.y = -magnitude * sine;

    fn_96_B890((Vec2f*)(energy + 8), &speed);
    energy[5] |= 0x80;

    float result = magnitude -
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            self, 0xfa2, 0);
    if (result < lbl_96_rodata_548)
        result = lbl_96_rodata_548;
    work->setFloat(result, 0x11000002);
}
}
