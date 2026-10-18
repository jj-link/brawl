#pragma force_active on
extern "C" {

void *fn_109_CEE0(void *, void *);
void *fn_109_CDA4(void *, void *);

}

extern "C" void *fn_109_CDA4(void *a, void *b)
{
    return fn_109_CEE0(b, b);
}
