#pragma force_active on
extern "C" {

struct _19894C_obj {
    int f0;
    int f4;
    int f8;
};

int fn_27_19894C(_19894C_obj* self)
{
    return self->f8 >> 29;
}

}
