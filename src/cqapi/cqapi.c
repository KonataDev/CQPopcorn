#include "cqapi.h"
#include "cqimpl.h"

__cqapi(int32_t) cqapi_send_private_msg(int32_t authcode, uint64_t account, const char *message) { return _virtual_send_private_msg(authcode, account, message); }
__cqapi(int32_t) cqapi_send_group_msg(int32_t authcode, uint64_t group, const char* message){ return _virtual_send_group_msg(authcode, group, message); }
__cqapi(int32_t) cqapi_send_discuss_msg(int32_t authcode, uint64_t discuss, const char* message){ return _virtual_send_discuss_msg(authcode, discuss, message); }
__cqapi(int32_t) cqapi_delete_msg(int32_t authcode, uint64_t msgid) { return _virtual_delete_msg(authcode, msgid); }
__cqapi(int32_t) cqapi_send_like_v2(int32_t authcode, uint64_t account, uint32_t times) { return _virtual_send_like_v2(authcode, account, times); }
__cqapi(int32_t) cqapi_get_cookies_v2(int32_t authcode, const char *domain) { return _virtual_get_cookies_v2(authcode, domain); }
__cqapi(int32_t) cqapi_get_record(int32_t authcode, const char *file, const char *outformat) { return _virtual_get_record(authcode, file, outformat); }
__cqapi(int32_t) cqapi_get_record_v2(int32_t authcode, const char *file, const char *outformat) { return _virtual_get_record_v2(authcode, file, outformat); }
__cqapi(int32_t) cqapi_get_image(int32_t authcode, const char *file) { return _virtual_get_image(authcode,file); }
__cqapi(int32_t) cqapi_can_send_image(int32_t authcode) { return _virtual_can_send_image(authcode); }
__cqapi(int32_t) cqapi_can_send_record(int32_t authcode) { return _virtual_can_send_record(authcode); }
__cqapi(int32_t) cqapi_get_csrf_token(int32_t authcode) { return _virtual_get_csrf_token(authcode); }
__cqapi(char *) cqapi_get_app_directory(int32_t authcode) { return _virtual_get_app_directory(authcode); }
__cqapi(uint64_t) cqapi_get_loginqq(int32_t authcode) { return _virtual_get_loginqq(authcode); }
__cqapi(char *) cqapi_get_login_nick(int32_t authcode) { return _virtual_get_login_nick(authcode); }
__cqapi(int32_t) cqapi_set_group_kick(int32_t authcode, uint64_t group, uint64_t account, bool declineever) { return _virtual_set_group_kick(authcode,  group,  account,  declineever); }
__cqapi(int32_t) cqapi_set_group_ban(int32_t authcode, uint64_t group, uint64_t account, uint64_t timesec) { return _virtual_set_group_ban(authcode,  group,  account,  timesec); }
__cqapi(int32_t) cqapi_set_group_admin(int32_t authcode, uint64_t group, uint64_t account, bool setadmin) { return _virtual_set_group_admin(authcode,  group,  account,  setadmin); }
__cqapi(int32_t) cqapi_set_group_special_title(int32_t authcode, uint64_t group, uint64_t account, const char* specialtitle, uint64_t expiredtime) { return _virtual_set_group_special_title(authcode, group, account, specialtitle,expiredtime); }
__cqapi(int32_t) cqapi_set_group_whole_ban(int32_t authcode, uint64_t group, bool enable) { return _virtual_set_group_whole_ban(authcode, group, enable); }
__cqapi(int32_t) cqapi_set_group_anonymous_ban(int32_t authcode, uint64_t group, const char *anonymousname, uint64_t timesec) { return _virtual_set_group_anonymous_ban(authcode, group, anonymousname, timesec); }
__cqapi(int32_t) cqapi_set_group_anonymous(int32_t authcode, uint64_t group, bool enable) { return _virtual_set_group_anonymous(authcode, group, enable); }
__cqapi(int32_t) cqapi_set_group_card(int32_t authcode, uint64_t group, uint64_t account, const char* newcard) { return _virtual_set_group_card(authcode, group, account,newcard ); }
__cqapi(int32_t) cqapi_set_group_leave(int32_t authcode, uint64_t group, bool dismiss) { return _virtual_set_group_leave(authcode, group, dismiss); }
__cqapi(int32_t) cqapi_set_discuss_leave(int32_t authcode, uint64_t discuss) { return _virtual_set_discuss_leave(authcode, discuss); }
__cqapi(int32_t) cqapi_set_friend_add_request(int32_t authcode, const char *reqtoken, uint32_t rsptype, const char *comment) { return _virtual_set_friend_add_request(authcode, reqtoken,rsptype,comment); }
__cqapi(int32_t) cqapi_set_group_add_request_v2(int32_t authcode, const char* reqtoken, uint32_t reqtype, uint32_t rsptype, const char* reason) { return _virtual_set_group_add_request_v2(authcode, reqtoken,reqtype,rsptype,reason); }
__cqapi(int32_t) cqapi_add_log(int32_t authcode, uint32_t loglevel, char* logtype, char* content) { return _virtual_add_log(authcode, loglevel, logtype, content); }
__cqapi(int32_t) cqapi_set_fatal(int32_t authcode, const char *message) { return _virtual_set_fatal(authcode, message); }
__cqapi(char *) cqapi_get_group_member_info_v2(int32_t authcode, uint64_t group, uint64_t account, bool nocaching) { return _virtual_get_group_member_info_v2(authcode, group, account, nocaching); }
__cqapi(char*) cqapi_get_group_member_list(int32_t authcode, uint64_t group) { return _virtual_get_group_member_list(authcode, group); }
__cqapi(char*) cqapi_get_group_list(int32_t authcode) { return _virtual_get_group_list(authcode); }
__cqapi(char *) cqapi_get_friend_list(int32_t authcode, bool reserved) { return _virtual_get_friend_list(authcode, reserved); }
__cqapi(char *) cqapi_get_stranger_info(int32_t authcode, uint64_t account, bool nocaching) { return _virtual_get_stranger_info(authcode, account, nocaching); }
__cqapi(char *) cqapi_get_group_info(int32_t authcode, uint64_t account, bool nocaching) { return _virtual_get_group_info(authcode, account, nocaching); }
