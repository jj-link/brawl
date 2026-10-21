#pragma force_active on
struct Object {
    int field_0;
    int field_4;
    void* field_8;
};

extern "C" void fn_80111C70(void*, int);

extern "C" void fn_80114AAC(Object* object) {
    fn_80111C70(object->field_8, object->field_0);
}
