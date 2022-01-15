#ifndef _CQAPI_VIRTUAL_H_
#define _CQAPI_VIRTUAL_H_

typedef int32_t (*_virtual_send_private_msg_t)(int32_t authcode, uint64_t account, const char *message);
static _virtual_send_private_msg_t _virtual_send_private_msg;

typedef int32_t (*_virtual_send_group_msg_t)(int32_t authcode, uint64_t group, const char *message);
static _virtual_send_group_msg_t _virtual_send_group_msg;

typedef int32_t (*_virtual_send_discuss_msg_t)(int32_t authcode, uint64_t discuss, const char *message);
static _virtual_send_discuss_msg_t _virtual_send_discuss_msg;

typedef int32_t (*_virtual_delete_msg_t)(int32_t authcode, uint64_t msgid);
static _virtual_delete_msg_t _virtual_delete_msg;

typedef int32_t (*_virtual_send_like_v2_t)(int32_t authcode, uint64_t account, uint32_t times);
static _virtual_send_like_v2_t _virtual_send_like_v2;

typedef int32_t (*_virtual_get_cookies_v2_t)(int32_t authcode, const char *domain);
static _virtual_get_cookies_v2_t _virtual_get_cookies_v2;

typedef int32_t (*_virtual_get_record_t)(int32_t authcode, const char *file, const char *outformat);
static _virtual_get_record_t _virtual_get_record;

typedef int32_t (*_virtual_get_record_v2_t)(int32_t authcode, const char *file, const char *outformat);
static _virtual_get_record_v2_t _virtual_get_record_v2;

typedef int32_t (*_virtual_get_image_t)(int32_t authcode, const char *file);
static _virtual_get_image_t _virtual_get_image;

typedef int32_t (*_virtual_can_send_image_t)(int32_t authcode);
static _virtual_can_send_image_t _virtual_can_send_image;

typedef int32_t (*_virtual_can_send_record_t)(int32_t authcode);
static _virtual_can_send_record_t _virtual_can_send_record;

typedef int32_t (*_virtual_get_csrf_token_t)(int32_t authcode);
static _virtual_get_csrf_token_t _virtual_get_csrf_token;

typedef char *(*_virtual_get_app_directory_t)(int32_t authcode);
static _virtual_get_app_directory_t _virtual_get_app_directory;

typedef uint64_t (*_virtual_get_loginqq_t)(int32_t authcode);
static _virtual_get_loginqq_t _virtual_get_loginqq;

typedef char *(*_virtual_get_login_nick_t)(int32_t authcode);
static _virtual_get_login_nick_t _virtual_get_login_nick;

typedef int32_t (*_virtual_set_group_kick_t)(int32_t authcode, uint64_t group, uint64_t account, bool declineever);
static _virtual_set_group_kick_t _virtual_set_group_kick;

typedef int32_t (*_virtual_set_group_ban_t)(int32_t authcode, uint64_t group, uint64_t account, uint64_t timesec);
static _virtual_set_group_ban_t _virtual_set_group_ban;

typedef int32_t (*_virtual_set_group_admin_t)(int32_t authcode, uint64_t group, uint64_t account, bool setadmin);
static _virtual_set_group_admin_t _virtual_set_group_admin;

typedef int32_t (*_virtual_set_group_special_title_t)(int32_t authcode, uint64_t group, uint64_t account, const char *specialtitle, uint64_t expiredtime);
static _virtual_set_group_special_title_t _virtual_set_group_special_title;

typedef int32_t (*_virtual_set_group_whole_ban_t)(int32_t authcode, uint64_t group, bool enable);
static _virtual_set_group_whole_ban_t _virtual_set_group_whole_ban;

typedef int32_t (*_virtual_set_group_anonymous_ban_t)(int32_t authcode, uint64_t group, const char *anonymousname, uint64_t timesec);
static _virtual_set_group_anonymous_ban_t _virtual_set_group_anonymous_ban;

typedef int32_t (*_virtual_set_group_anonymous_t)(int32_t authcode, uint64_t group, bool enable);
static _virtual_set_group_anonymous_t _virtual_set_group_anonymous;

typedef int32_t (*_virtual_set_group_card_t)(int32_t authcode, uint64_t group, uint64_t account, const char *newcard);
static _virtual_set_group_card_t _virtual_set_group_card;

typedef int32_t (*_virtual_set_group_leave_t)(int32_t authcode, uint64_t group, bool dismiss);
static _virtual_set_group_leave_t _virtual_set_group_leave;

typedef int32_t (*_virtual_set_discuss_leave_t)(int32_t authcode, uint64_t discuss);
static _virtual_set_discuss_leave_t _virtual_set_discuss_leave;

typedef int32_t (*_virtual_set_friend_add_request_t)(int32_t authcode, const char *reqtoken, uint32_t rsptype, const char *comment);
static _virtual_set_friend_add_request_t _virtual_set_friend_add_request;

typedef int32_t (*_virtual_set_group_add_request_v2_t)(int32_t authcode, const char *reqtoken, uint32_t reqtype, uint32_t rsptype, const char *reason);
static _virtual_set_group_add_request_v2_t _virtual_set_group_add_request_v2;

typedef int32_t (*_virtual_add_log_t)(int32_t authcode, uint32_t loglevel, char *logtype, char *content);
static _virtual_add_log_t _virtual_add_log;

typedef int32_t (*_virtual_set_fatal_t)(int32_t authcode, const char *message);
static _virtual_set_fatal_t _virtual_set_fatal;

typedef char *(*_virtual_get_group_member_info_v2_t)(int32_t authcode, uint64_t group, uint64_t account, bool nocaching);
static _virtual_get_group_member_info_v2_t _virtual_get_group_member_info_v2;

typedef char *(*_virtual_get_group_member_list_t)(int32_t authcode, uint64_t group);
static _virtual_get_group_member_list_t _virtual_get_group_member_list;

typedef char *(*_virtual_get_group_list_t)(int32_t authcode);
static _virtual_get_group_list_t _virtual_get_group_list;

typedef char *(*_virtual_get_friend_list_t)(int32_t authcode, bool reserved);
static _virtual_get_friend_list_t _virtual_get_friend_list;

typedef char *(*_virtual_get_stranger_info_t)(int32_t authcode, uint64_t account, bool nocaching);
static _virtual_get_stranger_info_t _virtual_get_stranger_info;

typedef char *(*_virtual_get_group_info_t)(int32_t authcode, uint64_t account, bool nocaching);
static _virtual_get_group_info_t _virtual_get_group_info;

#endif /* _CQAPI_VIRTUAL_H_ */
