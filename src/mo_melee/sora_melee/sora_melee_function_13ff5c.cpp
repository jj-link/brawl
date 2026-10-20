#pragma force_active on
#pragma optimization_level 1

struct StageObject;

struct Object {
    unsigned char padding[0x114];
    StageObject* stageObject;
};

extern "C" float getLr__23soExternalValueAccesserFP11StageObject(StageObject*);
extern "C" const float lbl_27_rodata_10B0;

extern "C" float fn_27_13FF5C(Object* self) {
    if (self->stageObject)
        return getLr__23soExternalValueAccesserFP11StageObject(self->stageObject);
    return lbl_27_rodata_10B0;
}
