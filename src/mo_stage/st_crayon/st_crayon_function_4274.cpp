#pragma force_active on

extern "C" {
void fn_56_46BC(char* self);
void fn_56_4780(char* self);
double fn_80400B44(double base, double exponent);
double cos(double x);
double sin(double x);
extern const float lbl_56_rodata_80[];
}

extern "C" void fn_56_4274(char* self, float farg0) {
    const float* c = lbl_56_rodata_80;
    char* outer = self + 0xD0;
    if (outer != 0) {
        int state = *(int*)(self + 0x184);
        switch (state) {
        case 0: {
            fn_56_46BC(self);
            char* obj = *(char**)(outer + 4);
            *(float*)(self + 0x170) = *(float*)(obj + 8);
            *(float*)(self + 0x174) = *(float*)(obj + 0xC);
            float cs = (float)cos((double)*(float*)(self + 0x164));
            *(int*)(self + 0x184) = 1;
            *(float*)(self + 0x178) = *(float*)(self + 0x168) * cs;
            break;
        }
        case 1: {
            float t = *(float*)(self + 0x178) * farg0;
            char* obj = *(char**)(outer + 4);
            *(float*)(obj + 8) = *(float*)(obj + 8) + t;
            float f31 = (float)fn_80400B44((double)*(float*)(self + 0x18C), *(double*)((const char*)c + 0x78));
            float ang = *(float*)(self + 0x164);
            float s = (float)sin((double)ang);
            obj = *(char**)(outer + 4);
            *(float*)(obj + 0xC) = *(float*)(self + 0x174) + farg0 * ((*(float*)(self + 0x18C) * (*(float*)(self + 0x168) * s)) - (c[32] * f31));
            obj = *(char**)(outer + 4);
            *(float*)(obj + 0x1C) = *(float*)(obj + 0x1C) + c[18];
            obj = *(char**)(outer + 4);
            if (*(float*)(obj + 0xC) < c[20]) {
                fn_56_4780(self);
            }
            break;
        }
        }
    }
}
