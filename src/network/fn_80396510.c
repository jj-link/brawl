#include <revolution/NHTTP/d_nhttp.h>
#pragma force_active on

NHTTPRequestHandle* fn_8039651C(const char* url, NHTTPReqMethod method, char* buffer, size_t bufferSize, NHTTPReqCallback callback, void* userContext, int a, int b);

NHTTPRequestHandle* NHTTPCreateRequest(const char* url, NHTTPReqMethod method, char* buffer, size_t bufferSize, NHTTPReqCallback callback, void* userContext) {
    return fn_8039651C(url, method, buffer, bufferSize, callback, userContext, 0, 0);
}
