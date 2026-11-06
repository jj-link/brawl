#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(float);
    virtual float slot6();
};
class Controller {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
};
struct Mid {
    char pad[8];
    Object_vptr_0* b;
    Object_vptr_0* a;
    Object_vptr_0* c;
    Object_vptr_0* d;
    Object_vptr_0* e;
};
struct Self {
    char pad[16];
    Controller* controller;
    Mid* mid;
};
extern "C" void fn_800B7AA4(Self* self, unsigned int mask, float f) {
    if (mask == 31) {
        if (self->mid->a) {
            if (f != self->mid->a->slot6()) {
                Controller* c = self->controller;
                c->slot6(2, 0);
                c->slot6(5, 0);
            }
            self->mid->a->slot5(f);
        }
        if (self->mid->b) {
            if (f != self->mid->b->slot6()) {
                Controller* c = self->controller;
                c->slot6(2, 0);
                c->slot6(5, 0);
            }
            self->mid->b->slot5(f);
        }
        if (self->mid->c) {
            if (f != self->mid->c->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->c->slot5(f);
        }
        if (self->mid->d) {
            if (f != self->mid->d->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->d->slot5(f);
        }
        if (self->mid->e) {
            if (f != self->mid->e->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->e->slot5(f);
        }
    } else {
        if (mask & 1) {
            if (f != self->mid->a->slot6()) {
                Controller* c = self->controller;
                c->slot6(2, 0);
                c->slot6(5, 0);
            }
            self->mid->a->slot5(f);
        }
        if (mask & 2) {
            if (f != self->mid->b->slot6()) {
                Controller* c = self->controller;
                c->slot6(2, 0);
                c->slot6(5, 0);
            }
            self->mid->b->slot5(f);
        }
        if (mask & 4) {
            if (f != self->mid->c->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->c->slot5(f);
        }
        if (mask & 8) {
            if (f != self->mid->d->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->d->slot5(f);
        }
        if (mask & 16) {
            if (f != self->mid->e->slot6()) {
                self->controller->slot6(3, 0);
            }
            self->mid->e->slot5(f);
        }
    }
}
