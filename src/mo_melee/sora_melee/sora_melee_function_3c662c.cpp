#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Pair {
    unsigned long a;
    unsigned long b;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5(int, Vec2f*, Vec3f*, void*);
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual unsigned long long slot13(short*);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
    virtual void slot18(unsigned long);
    virtual void slot19(unsigned long);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39(unsigned long);
    unsigned char byte4;
    unsigned char flags;
    char pad[10];
    Vec2f accel;
    Vec2f limit;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8084;
float fn_27_192278(void*, unsigned long);
void fn_27_89DAC(int, void*);
}

extern "C" void fn_27_3C662C(void* unused, u8* obj) {
    soNullable* stop = (soNullable*)__dynamic_cast(
        (*(soNullable**)(*(u8**)(obj + 0xd8) + 0x7c))->slot6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    soNullable* gravity = (soNullable*)__dynamic_cast(
        (*(soNullable**)(*(u8**)(obj + 0xd8) + 0x7c))->slot6(1), 0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);
    short id = 1;
    Pair p;
    unsigned long long value = (*(soNullable**)(*(u8**)(obj + 0xd8) + 0x7c))->slot13(&id);
    p = *(Pair*)&value;
    float x;
    if ((*(soNullable**)(*(u8**)(obj + 0xd8) + 0x14))->slot3() == 0) {
        x = *(float*)&p.a * fn_27_192278(obj, 0xFB2);
    } else {
        x = fn_27_192278(obj, 0xFB2);
    }
    Vec2f stopPos;
    stopPos.m_x = x;
    Vec3f stopRot;
    stopRot.m_x = lbl_27_rodata_8084;
    stopRot.m_y = lbl_27_rodata_8084;
    stopRot.m_z = lbl_27_rodata_8084;
    stopPos.m_y = lbl_27_rodata_8084;
    stop->slot5(6, &stopPos, &stopRot, obj);
    stop->flags |= 0x80;
    float y = fn_27_192278(obj, 0xFB3);
    Vec2f gravPos;
    gravPos.m_y = y;
    Vec3f gravRot;
    gravRot.m_x = lbl_27_rodata_8084;
    gravRot.m_y = lbl_27_rodata_8084;
    gravRot.m_z = lbl_27_rodata_8084;
    gravPos.m_x = lbl_27_rodata_8084;
    gravity->slot5(0, &gravPos, &gravRot, obj);
    gravity->accel.m_x = -fn_27_192278(obj, 0xFA0);
    gravity->limit.m_y = fn_27_192278(obj, 0xFA1);
    gravity->accel.m_y = fn_27_192278(obj, 0xFA1);
    gravity->flags |= 0x80;
    fn_27_89DAC(2, obj);
    fn_27_89DAC(0, obj);
    if ((*(soNullable**)(*(u8**)(obj + 0xd8) + 0x64))->slot17(0x22000013) != 0) {
        (*(soNullable**)(*(u8**)(obj + 0xd8) + 0x88))->slot39(0x23);
        (*(soNullable**)(*(u8**)(obj + 0xd8) + 0x64))->slot19(0x22000013);
    }
}
