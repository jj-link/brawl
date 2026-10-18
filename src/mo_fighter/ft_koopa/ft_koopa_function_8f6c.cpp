#pragma force_active on
struct KnuckleParam {
    float data[2];
};

struct KnuckleParam8 {
    KnuckleParam members[2];
};

extern "C" {

KnuckleParam* fn_102_8F6C(KnuckleParam8* array, int index) {
    KnuckleParam* result = &array->members[0];
    result = (KnuckleParam*)((int)result + 8 * index + 4);
    return result;
}

}