#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, unsigned int);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
 virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(int, unsigned int);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Accesser { char pad[8]; void* object; char pad1[0xcc]; Modules* modules; };
struct Data { char pad[0x10]; int value; };
struct Result { char pad[0x1fb8]; Data* data; };
extern "C" {
extern const char lbl_27_data_86C00[];
extern const char lbl_27_data_248[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_328744(void*, Accesser* arg) {
 Object_vptr_0* work = arg->modules->work;
 Result* result = (Result*)__dynamic_cast(arg->object, 0x3c, lbl_27_data_86C00, lbl_27_data_248, 1);
 work->slot20(0, 0x12000003);
 work->slot5(result->data->value, 0x10000005);
}
}