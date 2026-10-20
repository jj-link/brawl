#pragma force_active on
struct Vec3f {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};

struct Event {
    char data[16];
};

struct State {
    char pad[0x5e0];
    Event e1;
    float t1;
    Vec3f pos1[4];
    Vec3f rot1[4];
    char pad2[0x38];
    Event e2;
    float t2;
    Vec3f pos2[4];
    Vec3f rot2[4];
};

extern "C" {
extern const float lbl_65_rodata_0[];

unsigned long isEvent__13grTenganEventCFv(const void*);
long getPhase__13grTenganEventCFv(const void*);
void setPhase__13grTenganEventFl(void*, long);
void end__13grTenganEventFv(void*);
float randf__Fv();
void* getGround__5StageFi(void*, int);
void setEnableCollisionStatus__6GroundFb(void*, bool);
void mtBezierCurve__FfP5Vec3fP5Vec3f(float, Vec3f*, Vec3f*);
void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
void setRot__9grGimmickFP5Vec3f(void*, Vec3f*);

void fn_65_2A68(State* self, float dt) {
    const float* rd = lbl_65_rodata_0;
    Vec3f pos, rot;

    if (isEvent__13grTenganEventCFv(&self->e1) == 1) {
        switch (getPhase__13grTenganEventCFv(&self->e1)) {
        case 0: {
            self->t1 = rd[0];
            setPhase__13grTenganEventFl(&self->e1, 1);

            self->pos1[0].x = rd[0];
            self->pos1[0].y = rd[0];
            self->pos1[0].z = rd[0];

            float offset1 = rd[0xbc / 4] - rd[0xb8 / 4] * randf__Fv();
            self->pos1[3].z = rd[0xbc / 4] + offset1;
            self->pos1[3].x = rd[0];
            self->pos1[3].y = rd[0xc0 / 4];
            self->pos1[1] = self->pos1[0];
            self->pos1[2] = self->pos1[0];

            self->rot1[0].x = rd[0];
            self->rot1[0].y = rd[0];
            self->rot1[0].z = rd[0];

            float z1 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            float y1 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            float x1 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            self->rot1[3].y = y1;
            self->rot1[3].z = z1;
            self->rot1[3].x = x1;
            self->rot1[1] = self->rot1[0];
            self->rot1[2] = self->rot1[0];

            setEnableCollisionStatus__6GroundFb(
                getGround__5StageFi(self, 0x50), true);
            setEnableCollisionStatus__6GroundFb(
                getGround__5StageFi(self, 0x52), false);
            break;
        }
        case 1:
            self->t1 += rd[0x88 / 4] * dt;
            if (self->t1 >= rd[0x10 / 4])
                self->t1 = rd[0x10 / 4];

            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t1, self->pos1, &pos);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t1, self->rot1, &rot);
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, 0x51), &pos);
            setRot__9grGimmickFP5Vec3f(getGround__5StageFi(self, 0x51), &rot);

            if (rd[0x10 / 4] == self->t1)
                end__13grTenganEventFv(&self->e1);
            break;
        }
    }

    if (isEvent__13grTenganEventCFv(&self->e2) == 1) {
        switch (getPhase__13grTenganEventCFv(&self->e2)) {
        case 0: {
            self->t2 = rd[0x10 / 4];
            setPhase__13grTenganEventFl(&self->e2, 1);

            self->pos2[0].x = rd[0];
            self->pos2[0].y = rd[0];
            self->pos2[0].z = rd[0];

            float offset2 = rd[0xbc / 4] - rd[0xb8 / 4] * randf__Fv();
            self->pos2[3].z = rd[0xbc / 4] + offset2;
            self->pos2[3].x = rd[0];
            self->pos2[3].y = rd[0xc0 / 4];
            self->pos2[1] = self->pos2[0];
            self->pos2[2] = self->pos2[0];

            self->rot2[0].x = rd[0];
            self->rot2[0].y = rd[0];
            self->rot2[0].z = rd[0];

            float z2 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            float y2 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            float x2 = rd[0xc8 / 4] - rd[0xc4 / 4] * randf__Fv();
            self->rot2[3].y = y2;
            self->rot2[3].z = z2;
            self->rot2[3].x = x2;
            self->rot2[1] = self->rot2[0];
            self->rot2[2] = self->rot2[0];
            break;
        }
        case 1:
            self->t2 -= rd[0x88 / 4] * dt;
            if (self->t2 < rd[0])
                self->t2 = rd[0];

            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t2, self->pos1, &pos);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t2, self->rot1, &rot);
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, 0x51), &pos);
            setRot__9grGimmickFP5Vec3f(getGround__5StageFi(self, 0x51), &rot);

            if (rd[0] == self->t2) {
                setEnableCollisionStatus__6GroundFb(
                    getGround__5StageFi(self, 0x50), false);
                setEnableCollisionStatus__6GroundFb(
                    getGround__5StageFi(self, 0x52), true);
                end__13grTenganEventFv(&self->e2);
            }
            break;
        }
    }
}
}
