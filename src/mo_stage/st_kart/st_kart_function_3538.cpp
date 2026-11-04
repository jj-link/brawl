#pragma force_active on
extern "C" {
float randf__Fv();
extern const float lbl_49_rodata_58[];

class Obj {
public:
  char pad1[0x2c];
  float unk2c;
  char pad2[12];
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
  virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
  virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
  virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
  virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
  virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
  virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
  virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
  virtual void* updateStagePositions();
  char pad3[0x25c - 0x40];
  float unk25C;
  float unk260;
  float unk264;
  unsigned char unk268;
};

void fn_49_3538(Obj* arg0, float farg0) {
  const float* d = lbl_49_rodata_58;
  Obj* self = arg0;
  Obj* obj = (Obj*)self->updateStagePositions();
  if (obj != 0) {
    float v = self->unk25C - farg0;
    self->unk25C = v;
    if (v < d[0]) self->unk25C = d[0];
    if (d[0] == self->unk25C) {
      float r = randf__Fv();
      unsigned char* u268 = &self->unk268;
      switch (*u268) {
        case 0:
          if (r < d[13]) *u268 = 1;
          else *u268 = 2;
          break;
        case 1:
          if (r < d[33]) *u268 = 2;
          else *u268 = 0;
          break;
        case 2:
          if (r < d[33]) *u268 = 1;
          else *u268 = 0;
          break;
        default:
          if (r < d[34]) *u268 = 1;
          else if (r < d[35]) *u268 = 2;
          else *u268 = 0;
          break;
      }
      switch (*u268) {
        case 0:
          self->unk260 = d[4] + d[36] * randf__Fv();
          self->unk264 = d[9] * randf__Fv();
          break;
        case 1:
          self->unk260 = d[37] + d[4] * randf__Fv();
          self->unk264 = d[8] + d[13] * randf__Fv();
          break;
        case 2:
          self->unk260 = d[4] + d[5] * randf__Fv();
          self->unk264 = d[38] + d[33] * randf__Fv();
          break;
        case 3:
          self->unk260 = d[4] + d[5] * randf__Fv();
          self->unk264 = d[33] + d[39] * randf__Fv();
          break;
        case 4:
          self->unk260 = d[4] + d[5] * randf__Fv();
          self->unk264 = d[38] + d[38] * randf__Fv();
          break;
      }
      self->unk25C = obj->unk2c;
    }
  }
}
}
