#pragma force_active on
struct V2 { float x, y; void set(float a, float b) { x = a; y = b; } };
struct V3 { float x, y, z; };
struct Result { unsigned int x, y; };
extern "C" {
extern char __RTTI__16emAreaModuleImpl[], __RTTI__12soAreaModule[];
extern char __RTTI__5Enemy[], __RTTI__11StageObject[];
extern const float lbl_41_rodata_D50[13];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_10830(V2*);
V3* fn_41_5AC4(V3*, float, float, float);
void getCenterPos__23emExternalValueAccesserFP5Enemy(V3*, void*);
void fn_41_534C(V3*, const V3*);
V2* fn_41_2354(V2*, float, float);
Result fn_41_24110(V2*, V2*);
float fn_8003DDD0(void*, Result*);

float fn_41_25138(char* self, V2* a, V2* b, V2* direction) {
    const float* c = lbl_41_rodata_D50;
    __dynamic_cast(*(void**)(*(char**)(self + 0xd8) + 0x90), 0,
                   __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    if (c[2] == fn_41_10830(direction))
        return c[9];
    V3 center, temp;
    fn_41_5AC4(&center, c[2], c[2], c[2]);
    getCenterPos__23emExternalValueAccesserFP5Enemy(&temp,
        __dynamic_cast(*(void**)(self + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1));
    fn_41_534C(&center, &temp);
    V2 pos;
    pos.set(center.x, center.y);
    V2 sum;
    fn_41_2354(&sum, a->x + b->x, a->y + b->y);
    Result p;
    Result r = fn_41_24110(&sum, &pos);
    p = r;
    return c[5] * fn_8003DDD0(direction, &p);
}
}
