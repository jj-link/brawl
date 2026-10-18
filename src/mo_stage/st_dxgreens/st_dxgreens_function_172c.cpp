#pragma force_active on
extern "C" {
typedef struct DxGreensPair
{
    void *first;
    void *second;
} DxGreensPair;

void *fn_79_172C(void *unused, DxGreensPair *pair)
{
    return pair->second;
}
}
