#pragma force_active on
class Arg { public: char pad[12]; void* value; };
class A {
public:
 virtual void fn_8027C6C8();
 virtual void fn_80080A64();
 virtual void fn_8027C0FC(void*, const char*);
 virtual void fn_8027C104();
 virtual void fn_8027C0F8();
};
class B {
public:
 virtual void fn_8027C298();
 virtual void fn_80080A64();
 virtual void fn_8027C270(Arg*);
 virtual void fn_8027C1B8();
 virtual void fn_80280C20();
};
class C {
public:
 virtual void fn_8027C624();
 virtual void fn_80080A64();
 virtual void fn_8027C39C(void*, void*);
 virtual void fn_8027C5FC();
 virtual void fn_8027C5C4();
};
class Class_80488F58 {
public:
 virtual void fn_803328D4();
 virtual void fn_80080A64();
 virtual B* fn_803328CC();
 virtual A* fn_803328C4();
 virtual C* fn_803328BC();
};
extern "C" const char* fn_8027C83C(void*);
extern "C" void fn_80332600(Class_80488F58* self, Arg* arg, void* obj) {
 const char* s = fn_8027C83C(obj);
 self->fn_803328C4()->fn_8027C0FC(obj, s);
 self->fn_803328CC()->fn_8027C270(arg);
 self->fn_803328BC()->fn_8027C39C(arg->value, obj);
}