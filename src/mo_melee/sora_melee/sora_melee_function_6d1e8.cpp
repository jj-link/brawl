#pragma force_active on
struct Node { virtual void u(); virtual char* get(); };
struct Module {
virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual void f5();virtual void f6();virtual void f7();virtual void f8();virtual void f9();
virtual void f10();virtual void f11();virtual void f12();virtual void f13();virtual void f14();virtual void f15();virtual void f16();virtual void f17();virtual void f18();virtual void f19();
virtual void f20();virtual void f21();virtual void f22();virtual void f23();virtual void f24();virtual void f25();virtual void f26();virtual void f27();virtual void f28();virtual void f29();
virtual void f30();virtual void f31();virtual void f32();virtual void f33();virtual void f34();virtual void f35();virtual void f36();virtual void f37();virtual void f38();virtual void f39();
virtual void f40();virtual void f41();virtual void f42();virtual void f43();virtual void f44();virtual void f45();virtual void f46();virtual void f47();virtual void f48();virtual void f49();
virtual void call();
};
struct Modules { char p[0xA8]; Module* module; };
struct Data { char p[0xD8]; Modules* modules; };
struct Accessor { char p[0x44]; Data* data; };
struct Object { char p[0x48]; Node* node; };
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6D1E8(Object* __restrict object) {
    char* r = object->node->get();
    fn_27_6F30C(r + 0x1C)->data->modules->module->call();
}
