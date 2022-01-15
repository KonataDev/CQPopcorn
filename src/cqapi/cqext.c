#include <cqext.h>

#define _checkret(x) result = x; if(result != ok) return result;

cq_ext_instance_t cqext_load(const char* path) {
#ifdef _WIN32
  // Load coolq extension
  HINSTANCE instance = LoadLibrary(path);
  if (instance == NULL) return NULL;

  // Check coolq api version "9,com.example.coolq"
  char* appinfo = cqext_appinfo(instance);
  if (appinfo[0] != '9') return NULL;

  return instance;
#endif
}

__forceinline cq_ext_proc_t cqext_getproc(cq_ext_instance_t instance, const char* symbol) {
#ifdef _WIN32
  return GetProcAddress(instance, symbol);
#endif
}

cq_ret_t cqext_bootstrap(cq_ext_instance_t instance, int32_t authcode)
{
  cq_ret_t result;

  // Initialize extension
  _checkret(cqext_initialize(instance, authcode));

  // Startup event
  _checkret(cqext_event_startup(instance));

  return 0;
}

const char* cqext_appinfo(cq_ext_instance_t instance) {
  return ((CQ_AppInfo_t)cqext_getproc(instance, "AppInfo"))();
}

cq_ret_t cqext_initialize(cq_ext_instance_t instance, int32_t authcode) {
  return ((CQ_Initialize_t)cqext_getproc(instance, "Initialize"))(authcode);
}

cq_ret_t cqext_event_startup(cq_ext_instance_t instance) {
  return ((CQ_eventStartup_t)cqext_getproc(instance, "_eventStartup"))();
}

cq_ret_t cqext_event_enable(cq_ext_instance_t instance) {
  return ((CQ_eventStartup_t)cqext_getproc(instance, "_eventEnable"))();
}

cq_ret_t cqext_event_disable(cq_ext_instance_t instance) {
  return ((CQ_eventStartup_t)cqext_getproc(instance, "_eventDisable"))();
}

cq_eventctl_t cqext_event_private_msg(cq_ext_instance_t instance, int32_t subtype, 
  uint32_t msgid, uint64_t account, char* content, int32_t font){
    return ((CQ_eventPrivateMsg_t)cqext_getproc(instance, "_eventPrivateMsg"))(subtype, msgid, account, content, font);
}