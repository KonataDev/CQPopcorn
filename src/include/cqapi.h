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

#endif // !_CQ_API_H_
