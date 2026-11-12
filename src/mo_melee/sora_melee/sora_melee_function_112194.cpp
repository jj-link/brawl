#pragma force_active on

struct State {
    unsigned char pad[0x78];
    unsigned int id;
    float ax;
    float ay;
    float bx;
    float by;
};

struct Object {
    State* state;
};

extern "C" bool fn_27_112194(Object* obj, unsigned int id, const float* a, const float* b)
{
    return ((((obj->state->id == id && obj->state->ax == a[0]) ? true : false) &&
             obj->state->ay == a[1] ? true : false) &&
            obj->state->bx == b[0] ? true : false) &&
           obj->state->by == b[1] ? true : false;
}
