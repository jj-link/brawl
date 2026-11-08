#pragma force_active on
#pragma optimization_level 2
#pragma scheduling off
#pragma opt_propagation off
struct Outer;
class Work {
public:
 virtual void unused0();
 virtual void unused1();
 virtual void unused2();
 virtual void unused3();
 virtual int call(int, Outer*);
};
struct Middle { char padding[0x64]; Work* work; };
struct Outer { char padding[0xD8]; Middle* middle; };
struct Obj { char padding[0x60]; Outer* outer; };
extern "C" void fn_27_39FAB0(Obj* self) {
 Outer* outer = self->outer;
 int value = 0x10000005;
 outer->middle->work->call(value, outer);
}