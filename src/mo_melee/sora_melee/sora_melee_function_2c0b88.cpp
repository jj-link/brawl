#include <ty/ty_fig_listmng.h>
#include <sr/sr_common.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_7AA38[];
extern char lbl_27_data_7AA88[];
void fn_27_2C23B4(void*);
void fn_27_2C2490(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}
class List {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual int slot13();
};
struct Obj {
 void* vt;
 tyFigListDataManager* manager;
 void* listvt;
 unsigned int flags;
 char entries[0x300];
 int count;
};
extern "C" Obj* fn_27_2C0B88(Obj* self, void* data, unsigned long size) {
 List* list = (List*)&self->listvt;
 self->vt = lbl_27_data_7AA38;
 self->listvt = lbl_27_data_7AA88;
 *(unsigned int*)((char*)list + 4) |= 0xffff0000;
 *(unsigned int*)((char*)list + 4) |= 0xff00;
 __construct_array((char*)list + 8, fn_27_2C23B4, (void (*)(void*))fn_27_2C2490, 12, 64);
 list->slot8();
 bool load = data == 0;
 tyFigListDataManager* manager = new (Heaps::HeapType(2)) tyFigListDataManager(load);
 self->manager = manager;
 if (data) manager->setData(data, size);
 int count = ((List*)&self->listvt)->slot13();
 self->count = count;
 if (count > ((List*)&self->listvt)->slot13()) self->count = ((List*)&self->listvt)->slot13();
 else if (count < 0) self->count = 0;
 return self;
}