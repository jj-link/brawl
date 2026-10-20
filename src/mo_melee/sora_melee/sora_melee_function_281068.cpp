#pragma force_active on
struct Observer {
    virtual void attach(short, signed char);
    short id;
    short type;
    short link;
};

extern "C" void* __vt__21soStatusEventObserver[];

extern "C" Observer* fn_27_281068(Observer* self, int id, int group) {
    self->id = -1;
    self->type = 4;
    self->link = -1;
    *(void***)self = __vt__21soStatusEventObserver;
    self->attach((short)id, (signed char)group);
    return self;
}
