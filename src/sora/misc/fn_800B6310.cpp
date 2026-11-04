#pragma force_active on
extern double lbl_805A2208;
struct Data { char pad[0x1c]; unsigned short count; char pad1[2]; int state; };
struct Object { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual double v6(); char pad[0x28]; Data* data; };
struct Link { char pad[0x18]; Object* object; };
struct Self { char pad[0x14]; Link* link; };
extern "C" int fn_800B6310(Self* self) {
    Link* link = self->link;
    if (link == 0) return 1;
    Object* object = link->object;
    if (object == 0) return 1;
    Data* data = object->data;
    if (data->state != 1) {
        unsigned short count = data->count;
        double frame = object->v6();
        float result = count - 1;
        if (frame >= result) return 1;
    }
    return 0;
}