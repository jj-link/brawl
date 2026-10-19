#pragma force_active on
extern "C" {
void* fn_27_2ACB8C(void* p, int x);
void fn_27_2ACE38(void* p, void* q);

void fn_27_2ACA38(void* p, int x) {
    fn_27_2ACE38(p, fn_27_2ACB8C(p, x));
}
}
