#pragma force_active on
struct Track {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setRate(float);
};

struct ModelAnimation {
    char pad[8];
    Track* a;
    Track* b;
    Track* c;
    Track* d;
    Track* e;
};

struct Model {
    char pad[0x14];
    ModelAnimation* animation;
};

struct Menu {
    char pad[0x64c];
    Model** models;
};

extern "C" void setUpdateRate__16gfModelAnimationFf(ModelAnimation*, float);

extern "C" void fn_18_18D4(Menu* self, unsigned index, unsigned flags, float rate) {
    if (flags == 31) {
        setUpdateRate__16gfModelAnimationFf(self->models[index]->animation, rate);
    } else {
        ModelAnimation* anim = self->models[index]->animation;

        if ((flags & 1) && anim->b)
            anim->b->setRate(rate);

        if ((flags & 2) && anim->a)
            self->models[index]->animation->a->setRate(rate);

        if ((flags & 4) && anim->c)
            self->models[index]->animation->c->setRate(rate);

        if ((flags & 8) && anim->d)
            self->models[index]->animation->d->setRate(rate);

        if ((flags & 16) && anim->e)
            self->models[index]->animation->e->setRate(rate);
    }
}
