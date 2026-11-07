#pragma force_active on
extern "C" {
extern signed char lbl_27_bss_8964;
extern char lbl_27_bss_8968[], lbl_27_bss_8980[], lbl_27_bss_7B0C[];
extern char lbl_27_data_9B6C0[], lbl_27_data_C938[];
extern float lbl_27_rodata_7DF0;
extern int lbl_27_rodata_7DF8[];
void fn_27_39A924(void*);
void* fn_27_39A934(void*, int);
void __register_global_object(void*, void* (*)(void*, int), void*);
void fn_27_39B438(void*, int, int, int);
int fn_27_30FACC(void*, int, int, void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_39FAB0(void*);
int fn_27_39FA04(void*);
}
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
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16(int = 0, int = 0);
 virtual void slot17();
 virtual int slot18(int);
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void* slot24(int);
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
 virtual void slot38(int, float);
 virtual void slot39(int);
};
class StatusObject {
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
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual int slot16();
 virtual void slot17();
 virtual int slot18(int);
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void* slot24(int);
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
 virtual void slot38(int, float);
 virtual void slot39(int);
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
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
 virtual void slot39();
 virtual int slot40();
};
struct Modules {
 char pad[0x70];
 StatusObject* status;
 char pad74[0x10];
 Object_vptr_0* item;
 Object_vptr_0* module88;
};
struct Access {
 char pad[8];
 Object_vptr_3c* object;
 char pad0c[0xcc];
 Modules* modules;
};
extern "C" void fn_27_39B9F4(void*, Access* access, int next) {
 Modules* modules = access->modules;
 Object_vptr_0* item = modules->item;
 int status = modules->status->slot16();
 int kind = access->object->slot40();
 int first, second, third, last, index;
 switch (kind) {
 default:
 case 0x21:
  first=0x112; second=0x117; third=0x118; last=0x119; index=0; break;
 case 5:
  first=0x1aa; second=0x1ab; third=0x1ac; last=0x1ad; index=13; break;
 }
 if ((status==first && next!=second && next!=last) ||
     (status==second && next!=third && next!=last) ||
     (status==third && next!=last) ||
     (status==last && item->slot18(index))) {
  if (!lbl_27_bss_8964) {
   fn_27_39A924(lbl_27_bss_8968);
   __register_global_object(lbl_27_bss_8968, fn_27_39A934, lbl_27_bss_8980);
   lbl_27_bss_8964=1;
  }
  fn_27_39B438(access,0,0,0);
  int result=fn_27_30FACC(lbl_27_bss_7B0C,0,status,access,1);
  bool found;
  if ((unsigned)(result-0x117)<=1) {
   for (int i=0;i<6;i++) {
    if (next==lbl_27_rodata_7DF8[i]) {
     if (result==0x118) access->modules->module88->slot38(0x1a,lbl_27_rodata_7DF0);
     found=true;
     goto done;
    }
   }
  }
  access->modules->module88->slot39(0x1a);
  found=false;
 done:
  if (found) {
   void* p=item->slot24(index);
   if (p) {
    void* q=__dynamic_cast(p,0,lbl_27_data_9B6C0,lbl_27_data_C938,1);
    int x=fn_27_39FAB0(q);
    int y=fn_27_39FA04(q);
    if (!lbl_27_bss_8964) {
     fn_27_39A924(lbl_27_bss_8968);
     __register_global_object(lbl_27_bss_8968,fn_27_39A934,lbl_27_bss_8980);
     lbl_27_bss_8964=1;
    }
    fn_27_39B438(access,1,x,y);
   }
  }
  item->slot16(index, 0);
 }
 if (status==first && next==last) access->modules->module88->slot39(0x1a);
 if (status==last) {
  if (!lbl_27_bss_8964) {
   fn_27_39A924(lbl_27_bss_8968);
   __register_global_object(lbl_27_bss_8968,fn_27_39A934,lbl_27_bss_8980);
   lbl_27_bss_8964=1;
  }
  fn_27_39B438(access,0,0,0);
 }
}
