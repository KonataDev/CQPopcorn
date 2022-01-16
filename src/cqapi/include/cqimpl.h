#ifndef _CQ_MODE_H_
#define _CQ_MODE_H_

#include <cqapi.h>
#include "cqapi_virtual.h"
#include "cqapi_uniconn.h"
#include "cqapi_onebot.h"

typedef size_t* cqapi_implfunc_t;

typedef enum cqapi_impl {
  impl_uniconn = 1,
  impl_onebot = 2,  
} cqapi_impl_t;

static const cqapi_implfunc_t _implementions[][3] = 
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

/**
 * @brief initialize cqapi implementations
 * 
 * @param mode implementation mode
 */
bool cqimpl_initialize(cqapi_impl_t mode);

/**
 * @brief get implementation mode
 * 
 * @return cqapi_impl_t 
 */
cqapi_impl_t cqimpl_mode();

#endif /* _CQ_MODE_H_ */
