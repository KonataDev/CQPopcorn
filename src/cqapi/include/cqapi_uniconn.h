#ifndef _CQAPI_UNICONN_H_
#define _CQAPI_UNICONN_H_

int32_t _uniconn_send_private_msg(int32_t authcode, uint64_t account, const char* message);
int32_t _uniconn_send_group_msg(int32_t authcode, uint64_t group, const char* message);
int32_t _uniconn_send_discuss_msg(int32_t authcode, uint64_t discuss, const char* message);
int32_t _uniconn_delete_msg(int32_t authcode, uint64_t msgid);
int32_t _uniconn_send_like_v2(int32_t authcode, uint64_t account, uint32_t times);
int32_t _uniconn_get_cookies_v2(int32_t authcode, const char* domain);
int32_t _uniconn_get_record(int32_t authcode, const char* file, const char* outformat);
int32_t _uniconn_get_record_v2(int32_t authcode, const char* file, const char* outformat);
int32_t _uniconn_get_image(int32_t authcode, const char* file);
int32_t _uniconn_can_send_image(int32_t authcode);
int32_t _uniconn_can_send_record(int32_t authcode);
int32_t _uniconn_get_csrf_token(int32_t authcode);
char* _uniconn_get_app_directory(int32_t authcode);
uint64_t _uniconn_get_loginqq(int32_t authcode);
char* _uniconn_get_login_nick(int32_t authcode);
int32_t _uniconn_set_group_kick(int32_t authcode, uint64_t group, uint64_t account, bool declineever);
int32_t _uniconn_set_group_ban(int32_t authcode, uint64_t group, uint64_t account, uint64_t timesec);
int32_t _uniconn_set_group_admin(int32_t authcode, uint64_t group, uint64_t account, bool setadmin);
int32_t _uniconn_set_group_special_title(int32_t authcode, uint64_t group, uint64_t account, const char* specialtitle, uint64_t expiredtime);
int32_t _uniconn_set_group_whole_ban(int32_t authcode, uint64_t group, bool enable);
int32_t _uniconn_set_group_anonymous_ban(int32_t authcode, uint64_t group, const char* anonymousname, uint64_t timesec);
int32_t _uniconn_set_group_anonymous(int32_t authcode, uint64_t group, bool enable);
int32_t _uniconn_set_group_card(int32_t authcode, uint64_t group, uint64_t account, const char* newcard);
int32_t _uniconn_set_group_leave(int32_t authcode, uint64_t group, bool dismiss);
int32_t _uniconn_set_discuss_leave(int32_t authcode, uint64_t discuss);
int32_t _uniconn_set_friend_add_request(int32_t authcode, const char* reqtoken, uint32_t rsptype, const char* comment);
int32_t _uniconn_set_group_add_request_v2(int32_t authcode, const char* reqtoken, uint32_t reqtype, uint32_t rsptype, const char* reason);
int32_t _uniconn_add_log(int32_t authcode, uint32_t loglevel, char* logtype, char* content);
int32_t _uniconn_set_fatal(int32_t authcode, const char* message);
char* _uniconn_get_group_member_info_v2(int32_t authcode, uint64_t group, uint64_t account, bool nocaching);
char* _uniconn_get_group_member_list(int32_t authcode, uint64_t group);
char* _uniconn_get_group_list(int32_t authcode);
char* _uniconn_get_friend_list(int32_t authcode, bool reserved);
char* _uniconn_get_stranger_info(int32_t authcode, uint64_t account, bool nocaching);
char* _uniconn_get_group_info(int32_t authcode, uint64_t account, bool nocaching);

#endif /* _CQAPI_UNICONN_H_ */
