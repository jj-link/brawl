#pragma force_active on
class soLinkEventObserver;
class Object_vptr_0 { public: virtual short slot0(void*); };
extern "C" void* getInstance__13soEventSystemFv();
extern "C" Object_vptr_0* getManager__13soEventSystemFl(void*, long);
template<class T> struct soInstanceUnitFullProperty {
 soInstanceUnitFullProperty();
 ~soInstanceUnitFullProperty();
 char storage[12];
};
struct Elements { soInstanceUnitFullProperty<soLinkEventObserver*> values[2]; };
extern "C" unsigned char lbl_27_data_19A88[];
extern "C" unsigned char lbl_27_data_25970[];
extern "C" unsigned char lbl_27_data_25A60[];
template<class T> class soEventUnitWrapper {
public:
 static unsigned char __vt[];
 void* vtable; short manager; short event;
 void init(short a, short b) {
 manager = a; vtable = __vt; event = b;
 if (a != -1) {
 short id = getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), manager)->slot0(this);
 if (id > -1) event = id;
 }
 }
};
struct Work {
 void* vtable; unsigned char flag; unsigned char pad[3];
 void* priority; void* attribute; void* arrayVtable; void* arraySubVtable;
 unsigned int bits; unsigned char elements[24]; unsigned char enabled;
 void init() {
 flag = 0; vtable = lbl_27_data_25970;
 priority = lbl_27_data_25970 + 0x34;
 attribute = lbl_27_data_25970 + 0x40;
 arrayVtable = lbl_27_data_25A60;
 arraySubVtable = lbl_27_data_25A60 + 0x48;
 bits &= 0x003fffff;
 ((Elements*)elements)->__ct();
 enabled = 0;
 }
};
struct Object { void* vtable; short manager; short event; Work* work; Work embedded; };
extern "C" Object* fn_27_D5878(Object* self, short manager, short event) {
 ((soEventUnitWrapper<soLinkEventObserver>*)self)->init(manager,event);
 Work* work = &self->embedded;
 self->work = work;
 self->vtable = lbl_27_data_19A88;
 work->init();
 return self;
}
