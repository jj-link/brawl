#pragma force_active on
extern "C" void fn_27_1DA1F4(void*);
class Class_E104 {
public:
virtual void fn_122_ABB4();
virtual void fn_122_176B0();
virtual void fn_122_18F4C();
virtual void fn_122_18F44();
virtual int fn_122_18F3C(unsigned int);
virtual void fn_122_18F34();
virtual void fn_122_18F2C();
virtual void fn_122_18F24();
virtual void fn_122_18F1C();
virtual void fn_122_18F14();
virtual void fn_122_18F0C();
virtual void fn_122_18F04();
virtual void fn_122_18EFC();
virtual void fn_122_18EF4();
virtual void fn_122_18EA4();
virtual void fn_122_18EEC();
virtual void fn_122_18EDC();
virtual void fn_122_18ECC();
virtual void fn_122_18EBC(unsigned int);
virtual void fn_122_18EAC(unsigned int);
};
struct DataObj {
void* pad0[11];
int field_2C;
void* pad30[8];
int field_50;
};
static inline Class_E104* getF(unsigned char* self) {
return *(Class_E104**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xD8) + 0x64);
}
extern "C" void fn_122_268D0(unsigned char* self, int arg1, int arg2) {
fn_27_1DA1F4(self);
if (arg1 == 2) {
if (arg2 == 0) {
Class_E104* f = getF(self);
const DataObj* d = *(const DataObj**)(self + 0x2510);
if (d->field_2C - f->fn_122_18F3C(0x20000000u) > d->field_50) {
getF(self)->fn_122_18EBC(0x22000000u);
return;
}
}
getF(self)->fn_122_18EAC(0x22000000u);
}
}
