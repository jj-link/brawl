#pragma force_active on
struct Class_2C0_base { void* next; };
class Class_2C0 : public Class_2C0_base {
public:
    virtual void fn_27_5378();
    virtual void fn_27_6CA4();
    virtual void fn_27_6C80();
    virtual void fn_27_6C5C();
};
struct Node {
    Node* next;
    char pad[0x1c];
    Class_2C0* a;
    Class_2C0* b;
    Class_2C0* c;
};
struct Object {
    char pad[0x40];
    Node* head;
    char pad2[0x1c];
    unsigned char enabled;
};
extern "C" {
extern char lbl_27_data_4BCF8[];
extern char __RTTI__10gfCallBack[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
extern "C" void fn_27_2327F0(Object* self) {
    Node* node = self->head;
    if (self->enabled) {
        while (node) {
            Class_2C0* cb = node->b;
            while (cb) {
                cb->fn_27_6C5C();
                cb = (Class_2C0*)__dynamic_cast(cb->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            cb = node->a;
            while (cb) {
                cb->fn_27_6C5C();
                cb = (Class_2C0*)__dynamic_cast(cb->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            cb = node->c;
            while (cb) {
                cb->fn_27_6C5C();
                cb = (Class_2C0*)__dynamic_cast(cb->next, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
            }
            node = node->next;
        }
    }
}