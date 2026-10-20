#pragma force_active on
struct ResourceHandle {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void init();

    bool state;
    void* resource;
    int first;
    int second;
};

extern "C" const char lbl_27_data_2ABF0[];

extern "C" ResourceHandle* fn_27_14033C(ResourceHandle* self, void* resource) {
    self->state = false;
    *(const void**)self = lbl_27_data_2ABF0;
    self->resource = resource;
    self->first = -1;
    self->second = -1;
    self->init();
    return self;
}
