#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual int slot14(int,int); virtual void slot15(); virtual void slot16();
 virtual int slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
 virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
 virtual void slot25(); virtual float slot26(int,int);
};
class Class_1250 {
public:
 virtual void fn_27_13C90(); virtual void fn_27_14068(); virtual void fn_27_140C0(); virtual void fn_27_1412C();
 virtual void fn_27_14134(); virtual void fn_27_14370(); virtual void fn_27_14A28(); virtual void fn_27_14A30();
 virtual void fn_27_14A38(); virtual void fn_27_14A48(); virtual void fn_27_14A68(); virtual void fn_27_14AD8();
 virtual void fn_27_14A60(); virtual void fn_27_14D08(); virtual int fn_27_14EDC(int,int); virtual void fn_27_14D00();
 virtual void fn_27_14B80(); virtual void fn_27_14B88(int,int,int); virtual void fn_27_16A70(); virtual void fn_27_16AB8();
 virtual void fn_27_1CBB4(); virtual void fn_27_14A20(); virtual void fn_27_1CBAC(); virtual void fn_27_1CBA4();
 virtual void fn_27_14B98(); virtual void fn_27_14B90(); virtual float fn_27_1CB88(int,int);
};
extern "C" {
extern const char lbl_27_data_8B410[];
extern const char lbl_27_data_248[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_33C3BC(void* self, void* arg) {
 char* p = *(char**)((char*)arg + 0xd8);
 soNullable* first = *(soNullable**)(p + 0x70);
 Class_1250* second = *(Class_1250**)(p + 0x1c);
 char* result = (char*)__dynamic_cast(*(void**)((char*)arg + 8), 0x3c, lbl_27_data_8B410, lbl_27_data_248, 1);
 char* data = *(char**)(result + 0x1ef8);
 if (first->slot17() && second->fn_27_14EDC(0,0)) {
  second->fn_27_14B88(0, (int)(*(float*)(data + 8) * second->fn_27_1CB88(0,0)), 0);
 }
}
}