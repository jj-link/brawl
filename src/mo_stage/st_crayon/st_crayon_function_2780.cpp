#pragma force_active on
struct Param {
    char pad[12];
    float speed;
};

struct Node {
    char pad[28];
    float x;
};

struct Handle {
    void* a;
    Node* node;
};

struct Data {
    char pad[232];
    void* field;
};

struct Owner {
    char pad[8];
    Data* data;
};

struct Base {
    char pad[60];
};

struct Obj : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual Param* get();

    char pad40[4];
    Owner* owner;
    char pad48[136];
    Handle handle;
    char padD8[140];
    Data* data;
    void* field;
    char pad16C[7];
    unsigned char state;
    float target;
};

extern "C" {
    extern signed char lbl_56_bss_24;
    extern float lbl_56_bss_20;
    extern const float lbl_56_rodata_58;
}

extern "C" void fn_56_2780(Obj* self, float delta) {
    Param* p = self->get();
    if (p) {
        self->data = self->owner->data;
        self->field = self->data->field;

        if (!lbl_56_bss_24) {
            lbl_56_bss_20 = p->speed;
            lbl_56_bss_24 = 1;
        }

        Handle* h = &self->handle;
        if (h) {
            Node* n = h->node;
            switch (self->state) {
            case 0:
                break;

            case 1: {
                float d = self->target - n->x;
                if (d < lbl_56_rodata_58)
                    lbl_56_bss_20 = -p->speed;
                if (d > lbl_56_rodata_58)
                    lbl_56_bss_20 = p->speed;
                self->state = 2;
                break;
            }

            case 2:
                if ((lbl_56_bss_20 > lbl_56_rodata_58 &&
                     n->x > self->target) ||
                    (lbl_56_bss_20 < lbl_56_rodata_58 &&
                     n->x < self->target)) {
                    self->state = 0;
                } else {
                    n->x += lbl_56_bss_20 * delta;
                }
                break;
            }
        }
    }
}
