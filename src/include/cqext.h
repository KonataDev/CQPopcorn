#ifndef _CQ_EXTENSION_H_
#define _CQ_EXTENSION_H_

#include <stdint.h>

#ifdef _WIN32
#include <Windows.h>
typedef HINSTANCE cq_ext_instance_t;
#endif

typedef void* cq_ext_proc_t;

typedef enum cq_ret
{
  ok = 0
} cq_ret_t;

typedef enum cq_eventctl {
  ignore, // Ignore event
  handled // Do not pass this event to next
} cq_eventctl_t;

typedef char* (__stdcall* CQ_AppInfo_t)();
typedef cq_ret_t(__stdcall* CQ_Initialize_t)(int32_t authcode);
typedef cq_ret_t(__stdcall* CQ_eventStartup_t)();
typedef cq_ret_t(__stdcall* CQ_eventExit_t)();
typedef cq_ret_t(__stdcall* CQ_eventEnable_t)();
typedef cq_ret_t(__stdcall* CQ_eventDisable_t)();

// Type = 1, Private message
typedef cq_eventctl_t(__stdcall* CQ_eventPrivateMsg_t)(
  uint32_t subType,
  uint32_t msgId,
  uint64_t fromAccount,
  char* msg,
  uint32_t font
);

// Type = 2, Group message
typedef cq_eventctl_t(__stdcall* CQ_eventGroupMsg_t) (
  uint32_t subType,
  uint32_t msgId,
  uint64_t fromGroup,
  uint64_t fromAccount,
  char* fromAnonymous,
  char* msg,
  uint32_t font
);

// Type = 4, Discuss message
typedef cq_eventctl_t(__stdcall* CQ_eventDiscussMsg_t) (
  uint32_t subType,
  uint32_t msgId,
  uint64_t fromDiscuss,
  uint64_t fromAccount,
  char* msg,
  uint32_t font
);

// Type = 11, File upload message
typedef cq_eventctl_t(__stdcall* CQ_eventGroupUpload_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t fromAccount,
  char* file
);

// Type = 101, Admin changed
typedef cq_eventctl_t(__stdcall* CQ_eventSystem_GroupAdmin_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t beingOperateAccount
);

// Type = 102, Member decrease
typedef cq_eventctl_t(__stdcall* CQ_eventSystem_GroupMemberDecrease_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t fromAccount,
  uint64_t beingOperateAccount
);

// Type = 103, Member increase
typedef cq_eventctl_t(__stdcall* CQ_eventSystem_GroupMemberIncrease_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t fromAccount,
  uint64_t beingOperateAccount
);

// Type = 104, Group ban
typedef cq_eventctl_t(__stdcall* CQ_eventSystem_GroupBan_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t fromAccount,
  uint64_t beingOperateAccount,
  uint64_t duration
);

// Type = 201, Friend added
typedef cq_eventctl_t(__stdcall* CQ_eventFriend_Add_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromAccount
);

// Type = 301, Add friend
typedef cq_eventctl_t(__stdcall* CQ_eventRequest_AddFriend_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromAccount,
  char* msg,
  char* reponseFlag
);

// Type = 201, Add group
typedef cq_eventctl_t(__stdcall* CQ_eventRequest_AddGroup_t) (
  uint32_t subType,
  uint32_t sendTime,
  uint64_t fromGroup,
  uint64_t fromAccount,
  char* msg,
  char* reponseFlag
);

/**
 * load a coolq extension
 * @param path path to extension library.
 * @return if success, return extension instance.
 */
cq_ext_instance_t cqext_load(const char* path);

/**
 * start an extension
 * @param instance extension instance.
 * @param authcode authcode for validating legal cqapi calls.
 * @return if success, return 0.
 */
int32_t cqext_bootstrap(cq_ext_instance_t instance, int32_t authcode);

/**
 * get appinfo of an extension.
 * @param instance extension instance.
 * @return return a string contains api version and package name separated with a comma.
 */
const char* cqext_appinfo(cq_ext_instance_t instance);

/**
 * initialize an extension
 * @param instance extension instance.
 * @param authcode authcode for validating legal cqapi calls.
 * @return if success, return 0.
 */
cq_ret_t cqext_initialize(cq_ext_instance_t instance, int32_t authcode);

/**
 * initialize an extension
 * @param instance extension instance.
 * @return if success, return 0.
 */
cq_ret_t cqext_event_startup(cq_ext_instance_t instance);

/**
 * enable an extension
 * @param instance extension instance.
 * @return if success, return 0.
 */
cq_ret_t cqext_event_enable(cq_ext_instance_t instance);

/**
 * disable an extension
 * @param instance extension instance.
 * @return if success, return 0.
 */
cq_ret_t cqext_event_disable(cq_ext_instance_t instance);

#endif // !_CQ_EXTENSION_H_
