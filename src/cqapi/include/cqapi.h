#ifndef _CQ_API_H_
#define _CQ_API_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef WIN32
#define __cqapi(x) __declspec(dllexport) x __stdcall
#include <Windows.h>
#else
#define __cqapi(x) x
#endif

#include "cqapi_virtual.h"
#include "cqapi_uniconn.h"
#include "cqapi_onebot.h"

#pragma comment(linker, "/EXPORT:CQ_sendPrivateMsg=_cqapi_send_private_msg@16")
__cqapi(int32_t) cqapi_send_private_msg(int32_t authcode, uint64_t account, const char* message);

#pragma comment(linker, "/EXPORT:CQ_sendGroupMsg=_cqapi_send_group_msg@16")
__cqapi(int32_t) cqapi_send_group_msg(int32_t authcode, uint64_t group, const char* message);

#pragma comment(linker, "/EXPORT:CQ_sendDiscussMsg=_cqapi_send_discuss_msg@16")
__cqapi(int32_t) cqapi_send_discuss_msg(int32_t authcode, uint64_t discuss, const char* message);

#pragma comment(linker, "/EXPORT:CQ_deleteMsg=_cqapi_delete_msg@12")
__cqapi(int32_t) cqapi_delete_msg(int32_t authcode, uint64_t msgid);

#pragma comment(linker, "/EXPORT:CQ_sendLikeV2=_cqapi_send_like_v2@16")
__cqapi(int32_t) cqapi_send_like_v2(int32_t authcode, uint64_t account, uint32_t times);

#pragma comment(linker, "/EXPORT:CQ_getCookiesV2=_cqapi_get_cookies_v2@8")
__cqapi(int32_t) cqapi_get_cookies_v2(int32_t authcode, const char* domain);

#pragma comment(linker, "/EXPORT:CQ_getRecord=_cqapi_get_record@12")
__cqapi(int32_t) cqapi_get_record(int32_t authcode, const char* file, const char* outformat);

#pragma comment(linker, "/EXPORT:CQ_getRecordV2=_cqapi_get_record_v2@12")
__cqapi(int32_t) cqapi_get_record_v2(int32_t authcode, const char* file, const char* outformat);

#pragma comment(linker, "/EXPORT:CQ_getImage=_cqapi_get_image@8")
__cqapi(int32_t) cqapi_get_image(int32_t authcode, const char* file);

#pragma comment(linker, "/EXPORT:CQ_canSendImage=_cqapi_can_send_image@4")
__cqapi(int32_t) cqapi_can_send_image(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_canSendRecord=_cqapi_can_send_record@4")
__cqapi(int32_t) cqapi_can_send_record(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_getCsrfToken=_cqapi_get_csrf_token@4")
__cqapi(int32_t) cqapi_get_csrf_token(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_getAppDirectory=_cqapi_get_app_directory@4")
__cqapi(char*) cqapi_get_app_directory(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_getLoginQQ=_cqapi_get_loginqq@4")
__cqapi(uint64_t) cqapi_get_loginqq(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_getLoginNick=_cqapi_get_login_nick@4")
__cqapi(char*) cqapi_get_login_nick(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_setGroupKick=_cqapi_set_group_kick@24")
__cqapi(int32_t) cqapi_set_group_kick(int32_t authcode, uint64_t group, uint64_t account, bool declineever);

#pragma comment(linker, "/EXPORT:CQ_setGroupBan=_cqapi_set_group_ban@28")
__cqapi(int32_t) cqapi_set_group_ban(int32_t authcode, uint64_t group, uint64_t account, uint64_t timesec);

#pragma comment(linker, "/EXPORT:CQ_setGroupAdmin=_cqapi_set_group_admin@24")
__cqapi(int32_t) cqapi_set_group_admin(int32_t authcode, uint64_t group, uint64_t account, bool setadmin);

#pragma comment(linker, "/EXPORT:CQ_setGroupSpecialTitle=_cqapi_set_group_special_title@32")
__cqapi(int32_t) cqapi_set_group_special_title(int32_t authcode, uint64_t group, uint64_t account, const char* specialtitle, uint64_t expiredtime);

#pragma comment(linker, "/EXPORT:CQ_setGroupWholeBan=_cqapi_set_group_whole_ban@16")
__cqapi(int32_t) cqapi_set_group_whole_ban(int32_t authcode, uint64_t group, bool enable);

#pragma comment(linker, "/EXPORT:CQ_setGroupAnonymousBan=_cqapi_set_group_anonymous_ban@24")
__cqapi(int32_t) cqapi_set_group_anonymous_ban(int32_t authcode, uint64_t group, const char* anonymousname, uint64_t timesec);

#pragma comment(linker, "/EXPORT:CQ_setGroupAnonymous=_cqapi_set_group_anonymous@16")
__cqapi(int32_t) cqapi_set_group_anonymous(int32_t authcode, uint64_t group, bool enable);

#pragma comment(linker, "/EXPORT:CQ_setGroupCard=_cqapi_set_group_card@24")
__cqapi(int32_t) cqapi_set_group_card(int32_t authcode, uint64_t group, uint64_t account, const char* newcard);

#pragma comment(linker, "/EXPORT:CQ_setGroupLeave=_cqapi_set_group_leave@16")
__cqapi(int32_t) cqapi_set_group_leave(int32_t authcode, uint64_t group, bool dismiss);

#pragma comment(linker, "/EXPORT:CQ_setDiscussLeave=_cqapi_set_discuss_leave@12")
__cqapi(int32_t) cqapi_set_discuss_leave(int32_t authcode, uint64_t discuss);

#pragma comment(linker, "/EXPORT:CQ_setFriendAddRequest=_cqapi_set_friend_add_request@16")
__cqapi(int32_t) cqapi_set_friend_add_request(int32_t authcode, const char* reqtoken, uint32_t rsptype, const char* comment);

#pragma comment(linker, "/EXPORT:CQ_setGroupAddRequestV2=_cqapi_set_group_add_request_v2@20")
__cqapi(int32_t) cqapi_set_group_add_request_v2(int32_t authcode, const char* reqtoken, uint32_t reqtype, uint32_t rsptype, const char* reason);

#pragma comment(linker, "/EXPORT:CQ_addLog=_cqapi_add_log@16")
__cqapi(int32_t) cqapi_add_log(int32_t authcode, uint32_t loglevel, char* logtype, char* content);

#pragma comment(linker, "/EXPORT:CQ_setFatal=_cqapi_set_fatal@8")
__cqapi(int32_t) cqapi_set_fatal(int32_t authcode, const char* message);

#pragma comment(linker, "/EXPORT:CQ_getGroupMemberInfoV2=_cqapi_get_group_member_info_v2@24")
__cqapi(char*) cqapi_get_group_member_info_v2(int32_t authcode, uint64_t group, uint64_t account, bool nocaching);

#pragma comment(linker, "/EXPORT:CQ_getGroupMemberList=_cqapi_get_group_member_list@12")
__cqapi(char*) cqapi_get_group_member_list(int32_t authcode, uint64_t group);

#pragma comment(linker, "/EXPORT:CQ_getGroupList=_cqapi_get_group_list@4")
__cqapi(char*) cqapi_get_group_list(int32_t authcode);

#pragma comment(linker, "/EXPORT:CQ_getFriendList=_cqapi_get_friend_list@8")
__cqapi(char*) cqapi_get_friend_list(int32_t authcode, bool reserved);

#pragma comment(linker, "/EXPORT:CQ_getStrangerInfo=_cqapi_get_stranger_info@16")
__cqapi(char*) cqapi_get_stranger_info(int32_t authcode, uint64_t account, bool nocaching);

#pragma comment(linker, "/EXPORT:CQ_getGroupInfo=_cqapi_get_group_info@16")
__cqapi(char*) cqapi_get_group_info(int32_t authcode, uint64_t account, bool nocaching);

typedef enum cqapi_impl {
  uniconn = 1,
  onebot = 2,  
} cqapi_impl_t;

static const void* _implementions[][3] = 
{
  { &_virtual_send_private_msg,           _uniconn_send_private_msg,            _onebot_send_private_msg           },
  { &_virtual_send_group_msg,             _uniconn_send_group_msg,              _onebot_send_group_msg             },
  { &_virtual_send_discuss_msg,           _uniconn_send_discuss_msg,            _onebot_send_discuss_msg           },
  { &_virtual_delete_msg,                 _uniconn_delete_msg,                  _onebot_delete_msg                 },
  { &_virtual_send_like_v2,               _uniconn_send_like_v2,                _onebot_send_like_v2               },
  { &_virtual_get_cookies_v2,             _uniconn_get_cookies_v2,              _onebot_get_cookies_v2             },
  { &_virtual_get_record,                 _uniconn_get_record,                  _onebot_get_record                 },
  { &_virtual_get_record_v2,              _uniconn_get_record_v2,               _onebot_get_record_v2              },
  { &_virtual_get_image,                  _uniconn_get_image,                   _onebot_get_image                  },
  { &_virtual_can_send_image,             _uniconn_can_send_image,              _onebot_can_send_image             },
  { &_virtual_can_send_record,            _uniconn_can_send_record,             _onebot_can_send_record            },
  { &_virtual_get_csrf_token,             _uniconn_get_csrf_token,              _onebot_get_csrf_token             },
  { &_virtual_get_app_directory,          _uniconn_get_app_directory,           _onebot_get_app_directory          },
  { &_virtual_get_loginqq,                _uniconn_get_loginqq,                 _onebot_get_loginqq                },
  { &_virtual_get_login_nick,             _uniconn_get_login_nick,              _onebot_get_login_nick             },
  { &_virtual_set_group_kick,             _uniconn_set_group_kick,              _onebot_set_group_kick             },
  { &_virtual_set_group_ban,              _uniconn_set_group_ban,               _onebot_set_group_ban              },
  { &_virtual_set_group_admin,            _uniconn_set_group_admin,             _onebot_set_group_admin            },
  { &_virtual_set_group_special_title,    _uniconn_set_group_special_title,     _onebot_set_group_special_title    },
  { &_virtual_set_group_whole_ban,        _uniconn_set_group_whole_ban,         _onebot_set_group_whole_ban        },
  { &_virtual_set_group_anonymous_ban,    _uniconn_set_group_anonymous_ban,     _onebot_set_group_anonymous_ban    },
  { &_virtual_set_group_anonymous,        _uniconn_set_group_anonymous,         _onebot_set_group_anonymous        },
  { &_virtual_set_group_card,             _uniconn_set_group_card,              _onebot_set_group_card             },
  { &_virtual_set_group_leave,            _uniconn_set_group_leave,             _onebot_set_group_leave            },
  { &_virtual_set_discuss_leave,          _uniconn_set_discuss_leave,           _onebot_set_discuss_leave          },
  { &_virtual_set_friend_add_request,     _uniconn_set_friend_add_request,      _onebot_set_friend_add_request     },
  { &_virtual_set_group_add_request_v2,   _uniconn_set_group_add_request_v2,    _onebot_set_group_add_request_v2   },
  { &_virtual_add_log,                    _uniconn_add_log,                     _onebot_add_log                    },
  { &_virtual_set_fatal,                  _uniconn_set_fatal,                   _onebot_set_fatal                  },
  { &_virtual_get_group_member_info_v2,   _uniconn_get_group_member_info_v2,    _onebot_get_group_member_info_v2   },
  { &_virtual_get_group_member_list,      _uniconn_get_group_member_list,       _onebot_get_group_member_list      },
  { &_virtual_get_group_list,             _uniconn_get_group_list,              _onebot_get_group_list             },
  { &_virtual_get_friend_list,            _uniconn_get_friend_list,             _onebot_get_friend_list            },
  { &_virtual_get_stranger_info,          _uniconn_get_stranger_info,           _onebot_get_stranger_info          },
  { &_virtual_get_group_info,             _uniconn_get_group_info,              _onebot_get_group_info             }
};

#endif // !_CQ_API_H_
