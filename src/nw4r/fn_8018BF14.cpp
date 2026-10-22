#pragma force_active on
extern "C" void fn_8018BCF0(void*);
extern "C" int lbl_804659E8[];
struct Link {
    Link* next;
    Link* prev;
    Link* init() { next = 0; prev = 0; return this; }
};
struct Object {
    void* vtable;
    char pad[0x1C];
    int count;
    int other;
    Link link;
};
extern "C" void* fn_8018BF14(void* self) {
    Object* p = (Object*)self;
    fn_8018BCF0(self);
    Link* link = p->link.init();
    p->vtable = lbl_804659E8;
    p->count = 0;
    p->other = 0;
    link->next = &p->link;
    link->prev = &p->link;
    return self;
}
