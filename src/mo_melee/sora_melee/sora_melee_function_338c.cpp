#pragma force_active on
struct Class_50_base { char pad[0x30]; };
class Class_50 : public Class_50_base {
public:
    virtual void fn_27_1C28();
    virtual int fn_27_2A9C();
};
struct Class_A0_base { char pad[0x30]; };
class Class_A0 : public Class_A0_base {
public:
    virtual void fn_27_2AE0();
    virtual int fn_27_3624();
};
extern "C" {
unsigned int fn_27_118(Class_50*, Class_50*);
unsigned int fn_27_228(Class_50*, Class_50*);
unsigned int fn_27_1504(Class_50*, Class_50*);
unsigned int fn_27_2B8C(Class_50*, Class_50*);
}
extern "C" unsigned int fn_27_338C(Class_50* self, Class_50* other)
{
    if (fn_27_118(self, other) == 1) {
        if (fn_27_228(self, other) == 1)
            return 1;
        switch (other->fn_27_2A9C()) {
        case 1:
            return fn_27_1504(other, self);
        case 0:
            return fn_27_2B8C(self, other);
        }
    }
    return 0;
}