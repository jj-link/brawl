#pragma force_active on
struct Class_8042EC38_base {
 char pad[0xc];
 signed int y:8;
 signed int x:24;
 char pad2[0x38];
};
class Class_8042EC38: public Class_8042EC38_base {
public:
 virtual void fn_8005C798(int);
 inline int getState() const { return y; }
 inline void setState(int value) { y=value; }
 inline void finish() {
 setState(3);
 setState(6);
 if(this) fn_8005C798(1);
 }
};
extern "C" void fn_8005A9C0(Class_8042EC38* self) {
 if (self->getState() == 6) return;
 self->finish();
}