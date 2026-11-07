#pragma force_active on
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
    virtual void slot30(int);
};
struct Data {
    char pad[0x100];
    int busy;
    int pending;
};
struct Object : Object_vptr_3c {
    char pad40[0x174];
    Data* data;
    char pad1b8[0x1190];
    void* entries[52];
    int index;
    int pending;
};
extern "C" void fn_40_45B78(void*, Data*);
extern "C" void fn_800C2BB4(void*, void*);
extern "C" void fn_800C2BA4(Data*, unsigned int);
extern "C" int fn_40_45A50(Object* self, int advance) {
    if (self->index < 0) return 1;
    if (self->data->busy != 0) return 0;
    if (self->pending >= 0) return 1;
    void* value;
    fn_40_45B78(&value, self->data);
    void** entry = &self->entries[self->index];
    void* tmp = value;
    value = 0;
    fn_800C2BB4(entry, tmp);
    fn_800C2BB4(&value, 0);
    self->slot30(self->index + 1);
    if (self->data->pending != 0) {
        self->pending = self->index;
        return 0;
    }
    if (advance && self->index >= 0 && self->pending < 0) {
        if ((unsigned int)self->index < 0x32) {
            self->index++;
            fn_800C2BA4(self->data, self->index);
        } else {
            self->index = -1;
        }
    }
    return 1;
}