#pragma force_active on
#pragma fp_contract on

extern float lbl_805A46F8;
class Transform { public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void apply(float* in, float* out);
};
struct TransformData { float matrix[16]; char pad[0x14]; Transform* ptr1; Transform* ptr2; };
struct R31Data { float out[4]; float call1_out[4]; float call2_out[4]; };
extern "C" void fn_8031D730(TransformData* td, float* vec, R31Data* r31) {
    float neg_vec[4];
    float in_vec[4];
    float out_vec[4] __attribute__((aligned(16)));
    td->ptr1->apply(vec, &r31->call1_out[0]);
    neg_vec[0] = -vec[0];
    neg_vec[1] = -vec[1];
    neg_vec[2] = -vec[2];
    neg_vec[3] = -vec[3];
    float y = neg_vec[1], x = neg_vec[0], z = neg_vec[2];
    in_vec[0] = x * td->matrix[0] + y * td->matrix[1] + z * td->matrix[2];
    in_vec[1] = x * td->matrix[4] + y * td->matrix[5] + z * td->matrix[6];
    in_vec[2] = x * td->matrix[8] + y * td->matrix[9] + z * td->matrix[10];
    in_vec[3] = lbl_805A46F8;
    td->ptr2->apply(in_vec, &r31->call2_out[0]);
    float t2 = r31->call2_out[2];
    float t1 = r31->call2_out[1];
    float t0 = r31->call2_out[0];
    out_vec[0] = t0 * td->matrix[0] + t1 * td->matrix[4] + t2 * td->matrix[8] + td->matrix[12];
    out_vec[1] = t0 * td->matrix[1] + t1 * td->matrix[5] + t2 * td->matrix[9] + td->matrix[13];
    out_vec[2] = t0 * td->matrix[2] + t1 * td->matrix[6] + t2 * td->matrix[10] + td->matrix[14];
    out_vec[3] = lbl_805A46F8;
    r31->out[0] = r31->call1_out[0] - out_vec[0];
    r31->out[1] = r31->call1_out[1] - out_vec[1];
    r31->out[2] = r31->call1_out[2] - out_vec[2];
    r31->out[3] = r31->call1_out[3] - out_vec[3];
}
