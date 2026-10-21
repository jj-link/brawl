#pragma force_active on
class Object {
    unsigned char padding[8];
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21();
    virtual void call(unsigned int, int);
};

struct Manager {
    unsigned char padding[0x1C];
    Object* objects[16];
};

extern "C" void fn_27_A22C8(Manager* self, unsigned int id)
{
    unsigned int mask = 1;
    mask <<= id & 31;
    Object* object = self->objects[(unsigned int)id >> 28];
    object->call(mask, (int)(id & 255) / 32);
}
