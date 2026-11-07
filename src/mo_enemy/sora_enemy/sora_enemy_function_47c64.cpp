#pragma force_active on
extern unsigned char lbl_41_bss_504[];
extern float lbl_41_rodata_101C;
extern "C" float fn_41_6AD8(void*, void*);
extern "C" void fn_8003DBA8(void*);
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
 virtual float slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual int slot17(unsigned long);
};
struct Holder {
 char pad0[0xc];
 Object_vptr_0* p0c;
 char pad1[0x64 - 0x10];
 Object_vptr_0* p64;
};
struct Accesser {
 char pad[0xd8];
 Holder* holder;
};
struct Vec2 { float x, y; };
extern "C" void fn_41_47C64(char* arg0, Accesser* arg1, Vec2* arg2, Vec2* arg3, int arg4) {
 Vec2 delta;
 delta.x = arg3->x - arg2->x;
 delta.y = arg3->y - arg2->y;
 fn_8003DBA8(&delta);
 float t = fn_41_6AD8(arg0 + 0x38, arg1);
 *(float*)(lbl_41_bss_504 + 0x18) = delta.x * t;
 *(float*)(lbl_41_bss_504 + 0x1c) = delta.y * t;
 *(float*)(lbl_41_bss_504 + 0x20) = delta.x * *(float*)(arg0 + 0x58);
 *(float*)(lbl_41_bss_504 + 0x24) = delta.y * *(float*)(arg0 + 0x58);
 float var_f31 = lbl_41_rodata_101C;
 if (arg1->holder->p64->slot17(0x12000003) == 0 && arg4 != 0)
  var_f31 = arg1->holder->p0c->slot9();
 *(float*)(lbl_41_bss_504 + 0x18) *= var_f31;
 *(float*)(lbl_41_bss_504 + 0x20) *= var_f31;
}