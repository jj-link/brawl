#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(float, int);
    virtual void slot13(float);
};
struct NetObj {
    void* field0;
    char pad04[4];
    Object_vptr_0* ptr1;
    Object_vptr_0* ptr2;
    float f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B;
    int i3C, i40, i44, i48, i4C;
    char pad50[4];
    int i54, i58;
    char pad5C[4];
    int i60;
    char pad64[0x10];
    int i74;
    char pad78[4];
    int i7C;
    short* ptr80;
    char pad84[0x40];
    float fC4;
};
extern "C" void fn_803EF4A8(void*, int);
extern "C" int fn_803F004C(void*, int, int, int, int, int);
extern "C" void fn_801CBFB0(void*, void*, int, int, int, int);
extern float lbl_805A4B04;
inline void setVolume(Object_vptr_0* p, float v) { if (p) p->slot12(v, 0); }
inline void setPitch(Object_vptr_0* p, float v) { if (p) p->slot13(v); }
extern "C" void fn_803EF640(NetObj* obj) {
    int val1, val2, val3, ret, offset, flag, var_r3;
    if (obj->b39 == 1 && obj->b3A == 0) {
        val1 = obj->ptr80[obj->i4C];
        val2 = obj->ptr80[obj->i4C + 1];
        val3 = obj->ptr80[obj->i4C + 2];
        if (val1 == 0xD3 || val2 == 0xD3) {
            obj->i4C = 0; obj->i48 = 0x12; obj->b39 = 0; obj->i60 = 0;
        }
        while (val1 >= 0xD0 && val1 <= 0x18F && obj->b3A == 0 && obj->b39 == 1) {
            fn_803EF4A8(obj, val1);
            obj->i4C++;
            val1 = obj->ptr80[obj->i4C];
        }
        if (obj->b39 == 0) return;
        {
            if (obj->i44 == 0 || obj->b38 == 1) {
                if ((val1 >= 0 && val1 <= 0xCF) || val1 >= 0x12C) obj->i74 = val1;
                if ((val1 >= 0 && val1 <= 0xCF) || val1 >= 0x12C) obj->i7C++;
                obj->i44 = 1;
                ret = fn_803F004C(obj, val1, val2, val3, obj->i48, 0);
                if (val1 == 0xCC && val2 == 0xCC) ret = 0xC9;
                if (obj->i54 == 0) { obj->i54 = 1; var_r3 = 0; }
                else { obj->i54 = 0; var_r3 = 1; }
                switch (ret) {
                case 0x12B: offset = -1; flag = 1; break;
                case 0xC9: offset = 0x68; flag = 1; break;
                default: offset = ret + obj->i3C; flag = 0; break;
                }
                if (ret == 0xC9 && obj->b38 == 1) offset = -1;
                if (offset != -1)
                    fn_801CBFB0((char*)obj->field0 + 0xC, &obj->ptr1 + var_r3, offset, 0, 0, 0);
                obj->f20 = obj->f1C * (obj->f14 * obj->f18);
                obj->f34 = obj->f30 * (obj->f28 * obj->f2C);
                if (offset >= 0 && offset <= 0xCF && flag == 0) {
                    setVolume(obj->ptr1, obj->f10 * obj->fC4);
                    setVolume(obj->ptr2, obj->f24 * obj->fC4);
                    setPitch(obj->ptr1, obj->f20);
                    setPitch(obj->ptr2, obj->f34);
                } else {
                    setVolume(obj->ptr1, obj->fC4);
                    setVolume(obj->ptr2, obj->fC4);
                    if (obj->ptr1) obj->ptr1->slot13(lbl_805A4B04);
                    if (obj->ptr2) obj->ptr2->slot13(lbl_805A4B04);
                }
                obj->i4C++;
                if (ret != 0xC9 && val2 < 0xD0) obj->i4C++;
            } else if (obj->i44 == obj->i40) obj->i44 = 0;
            else obj->i44++;
        }
    }
    if (obj->i58 != 0) {
        fn_803F004C(obj, obj->i58, 0, 0, obj->i48, 2);
        obj->i58 = 0;
    }
}
