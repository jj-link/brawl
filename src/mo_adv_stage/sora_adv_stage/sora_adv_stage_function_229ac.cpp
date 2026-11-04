#pragma force_active on
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_229AC(int);
};
struct Node {
    void* prev;
    Node* next;
    grYakumono* value;
};
struct Object {
    char pad[0x3c];
    char* vtable;
    char pad40[0x10c];
    char* vtable2;
    char pad150[4];
    Node* head;
    Node* tail;
    Node* current;
    unsigned int count;
};
extern "C" {
extern char lbl_40_data_5CEC[];
void __dl__FPv(void*);
void fn_27_272420(void*, int);
void __dt__9grGimmickFv(void*, int);
void* fn_40_229AC(Object* self, int flag) {
    if (self) {
        unsigned int i;
        unsigned int n = self->count;
        self->vtable = lbl_40_data_5CEC;
        self->vtable2 = lbl_40_data_5CEC + 0x170;
        self->current = self->head;
        for (i = 0; i < n; i++) {
            if (self->current->value)
                self->current->value->fn_40_229AC(1);
            self->current->value = 0;
            self->current = self->current->next;
        }
        n = self->count;
        self->current = self->head;
        for (i = 0; i < n; i++) {
            Node* p = self->current;
            self->current = p->next;
            if (p)
                __dl__FPv(p);
        }
        self->head = 0;
        self->tail = 0;
        self->current = 0;
        self->count = 0;
        fn_27_272420(&self->vtable2, 0);
        __dt__9grGimmickFv(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}