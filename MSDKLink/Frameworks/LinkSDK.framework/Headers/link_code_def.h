//
// Created by River on 2022/4/2.
//

#ifndef LINKSDK_LINK_CODE_DEF_H
#define LINKSDK_LINK_CODE_DEF_H

#define LINK_ERR_OK                             0           //执行成功

#define LINK_ERR_UNDEFINE                       9999        //未覆盖到的错误码

#define LINK_ERR_PARAM_ERROR                    10000       //参数异常
#define LINK_ERR_FILE_OPEN_FAILED               10001       //文件打开失败
#define LINK_ERR_FILE_READ_FAILED               10002       //文件读取失败
#define LINK_ERR_FILE_WRITE_FAILED              10003       //文件写入失败

#define LINK_ERR_NO_MEMORY                      10100       //内存不足

#define LINK_ERR_THREAD                         10200       //线程错误

#define LINK_ERR_NET_MISS                       10300       //网络客户端未初始化
#define LINK_ERR_NET_BUSY                       10301       //网络忙
#define LINK_ERR_NET_CANCEL                     10302       //网络请求被取消
#define LINK_ERR_NET_TIMEOUT                    10303       //网络请求超时
#define LINK_ERR_NET_OTHER                      10304       //其他网络错误

#define LINK_ERR_PARSE_XML                      10400       //XML解析错误
#define LINK_ERR_PARSE_FIELD_MISS               10401       //对设备返回的内容解析成功,但部分字段解析失败
#define LINK_ERR_PARSE_ERR_CONTENT              10402       //设备返回了错误的内容,无法解析
#define LINK_ERR_PARSE_JSON                     10403       //无法解析设备返回的JSON数据,可能是因为格式错误

#define LINK_ERR_NOT_INIT                       10500       //SDK未初始化

#define LINK_ERR_AUTH_FAIL                      10600       //鉴权失败
#define LINK_ERR_AUTH_NO_PERMIT                 10601       //鉴权流程没有权限获取必要数据
#define LINK_ERR_AUTH_NO_TIMES                  10602       //SDK使用次数已达上限

#define LINK_ERR_NOT_CONNECT                    10700       //未连接记录仪设备

#define LINK_ERR_PROTOCOL_INTERNAL_MISS         10800       //内部错误
#define LINK_ERR_PROTOCOL_UNKNOWN               10801       //所连接的设备对应的协议未实现
#define LINK_ERR_PROTOCOL_NOT_ADAPT             10802       //SDK未适配协议中的特定功能
#define LINK_ERR_PROTOCOL_UNEXPECTED_CALL       10803       //错误的API调用方式
#define LINK_ERR_PROTOCOL_DEVICE_NOT_ADAPT      10804       //设备未适配该功能
#define LINK_ERR_PROTOCOL_NO_PERMIT             10805       //没有连接权限(rc4校验失败)

#define LINK_ERR_CACHE_MENU_MISS                10900       //菜单缓存丢失
#define LINK_ERR_CACHE_MENU_EXIST               10901       //菜单已缓存
#define LINK_ERR_CACHE_FILE_MISS                10902       //文件缓存丢失
#define LINK_ERR_MENU_UPGRADE                   10903       //命令执行成功,菜单已更新,需要重新获取菜单列表
#define LINK_ERR_MENU_DISABLED                  10904       //菜单处于禁用状态


typedef enum {
    LINK_CMD_UNDEFINE                   = 0,            //未定义的Command类型,一般表示方案上新添加的协议尚未兼容

    LINK_CMD_PRE_RECORDING              = 1000,         //预录像/自动精彩录像
    LINK_CMD_VIDEO_LOOP_REC             = 1001,         //视频循环录制或间隔时间
    LINK_CMD_VIDEO_RESOLUTION           = 1002,         //视频录制分辨率
    LINK_CMD_AUTO_VIDEO_REC             = 1003,         //自动录像
    LINK_CMD_MOTION_DETECT              = 1004,         //移动侦测
    LINK_CMD_PARKING_GUARD              = 1005,         //停车守卫
    LINK_CMD_GSENSOR_SENSITIVITY        = 1006,         //G-Sensor灵敏度
    LINK_CMD_MIC                        = 1007,         //声音录制(是否打开麦克风)
    LINK_CMD_HDR                        = 1008,         //视频高动态范围
    LINK_CMD_PIP_SINGLE_LENS            = 1009,         //画中画功能开关(单镜头设备)
    LINK_CMD_VIDEO_COLOR                = 1010,         //视频色彩模式(彩色或黑白)
    LINK_CMD_ZOOM_INOUT                 = 1011,         //电子变焦
    LINK_CMD_IR_LED                     = 1012,         //IR LED(红外灯)
    LINK_CMD_DATE_LOGO                  = 1013,         //日期水印
    LINK_CMD_PIP_MULTIPLE_LENS          = 1014,         //画中画模式切换(一般是双路或三路)
    LINK_CMD_SLOW_MOTION_REC            = 1015,         //慢动作录影
    LINK_CMD_TIMELAPSE_REC              = 1016,         //缩时录影设置
    LINK_CMD_TIMELAPSE_REC_FPS          = 1017,         //停车模式缩时录影帧率
    LINK_CMD_TIMELAPSE_REC_DURATION     = 1018,         //停车模式缩时录影持续时间
    LINK_CMD_WDR                        = 1019,         //视频宽动态范围
    LINK_CMD_VIDEO_CODEC_TYPE           = 1020,         //视频编码器
    LINK_CMD_FLIP                       = 1021,         //视频预览画面翻转
    LINK_CMD_MIRROR                     = 1022,         //视频预览镜像
    LINK_CMD_LDC                        = 1023,         //畸变矫正
    LINK_CMD_DIS                        = 1024,         //画面防抖
    LINK_CMD_MOVIE_FORMAT               = 1025,         //录像文件格式
    LINK_CMD_ADAS                       = 1026,         //ADAS算法设置
    LINK_CMD_GPS_STAMP                  = 1027,         //GPS水印开关

    LINK_CMD_PHOTO_RESOLUTION           = 2000,         //照片分辨率
    LINK_CMD_TIMER_PHOTO                = 2001,         //定时拍照
    LINK_CMD_BURST                      = 2002,         //连拍
    LINK_CMD_PHOTO_QUALITY              = 2003,         //照片质量
    LINK_CMD_PHOTO_COLOR                = 2004,         //照片调色模式
    LINK_CMD_PHOTO_DATE_STAMP           = 2005,         //照片水印

    LINK_CMD_EV                         = 3000,         //曝光补偿
    LINK_CMD_WHITE_BALANCE              = 3001,         //白平衡
    LINK_CMD_SHARPNESS                  = 3002,         //锐度
    LINK_CMD_ISO                        = 3003,         //感光度

    LINK_CMD_BRIGHTNESS                 = 4000,         //屏幕亮度
    LINK_CMD_VOLUME                     = 4001,         //设备音量
    LINK_CMD_AI_BRAIN                   = 4002,         //AI智能
    LINK_CMD_TV_FORMAT                  = 4003,         //视频制式
    LINK_CMD_KEY_TONE                   = 4004,         //按键音
    LINK_CMD_LANGUAGE                   = 4005,         //设备语言
    LINK_CMD_GPS_SPEED_UNIT             = 4006,         //速度单位
    LINK_CMD_FLICKER                    = 4007,         //光源频率
    LINK_CMD_GYROSCOPE                  = 4008,         //陀螺仪
    LINK_CMD_INTERNAL_STORAGE_SPACE     = 4009,         //内置存储器剩余空间
    LINK_CMD_EXTERNAL_STORAGE_SPACE     = 4010,         //外置存储器剩余空间
    LINK_CMD_FORMAT_INTERNAL_STORAGE    = 4011,         //格式化内置存储
    LINK_CMD_FORMAT_EXTERNAL_STORAGE    = 4012,         //格式化外置存储
    LINK_CMD_BLE_FREE_CONNECT           = 4013,         //蓝牙辅助免密链接
    LINK_CMD_WIFI_SSID                  = 4014,         //WiFi名称
    LINK_CMD_WIFI_PASSWORD              = 4015,         //WiFi密码
    LINK_CMD_BOOT_SOUND                 = 4016,         //开关机声音
    LINK_CMD_SCREEN_OFF_DELAY           = 4017,         //息屏延迟(屏幕保护)
    LINK_CMD_POWER_OFF                  = 4018,         //关机选项
    LINK_CMD_USB_MODE                   = 4019,         //USB工作模式
#if (defined PURE_BYLINWELL)
    LINK_CMD_VIN_CODE                   = 4020,         //汽车识别码
#endif
    LINK_CMD_DELAY_POWER_OFF            = 4021,         //延时关机
    LINK_CMD_WIFI_BAND                  = 4022,         //WiFi频段
    LINK_CMD_SYSTEM_RESET               = 4023,         //恢复默认设置
    LINK_CMD_VERSION                    = 4024,         //设备版本
    LINK_CMD_PIR_INTERVAL               = 4025,         //定时拍照间隔时间,与公版打猎机拍照间隔时间功能相似
    LINK_CMD_PIR_MONITORING_PERIOD      = 4026,         //定时拍照工作开关,与公版打猎机监控时段开关功能相似
    LINK_CMD_PIR_MONITORING_PERIOD_TIME = 4027,         //定时拍照监控时段,与公版打猎机监控时段功能相似?
    LINK_CMD_HUNTING_MODE               = 4028,         //定时拍照工作模式,与公版打猎机打猎模式功能相似?
    LINK_CMD_EDOG_SOUND                 = 4029,         //设置电子狗语音播报开关
    LINK_CMD_FORMAT_REMIND              = 4030,         //设置格式化提醒时间
    LINK_CMD_EDOG_VERSION               = 4031,         //电子狗软件版本
    LINK_CMD_TIMEZONE                   = 4032,         //时区
    LINK_CMD_EDOG                       = 4033,         //电子狗功能开关
    LINK_CMD_EDOG_ICON                  = 4034,         //电子狗图示开关
    LINK_CMD_EDOG_VOLUME                = 4035,         //电子狗报警音量
    LINK_CMD_EDOG_OVERSPEED             = 4036,         //电子狗超速预警开关
    LINK_CMD_MCU_VERSION                = 4037,         //MCU版本
    LINK_CMD_F_SENSOR_VERSION           = 4038,         //前镜头版本
    LINK_CMD_R_SENSOR_VERSION           = 4039,         //后镜头版本
#if (defined PURE_CARMAX)
    LINK_CMD_PLAYBACK_VOLUME            = 4040,         //视频回放音量
#endif
    LINK_CMD_ASR                        = 4041,         //声控功能开关
    LINK_CMD_UPLOAD_COLLISION_DATA      = 4042,         //碰撞数据上传开关

    LINK_CMD_MAXIMUM                    = LINK_CMD_UPLOAD_COLLISION_DATA + 1
} LinkCommand;

typedef enum {
    LINK_CMD_TYPE_NORMAL            = 1,        //普通菜单(选项不编辑)
    LINK_CMD_TYPE_EDITABLE          = 2,        //(选项)可编辑类菜单
    LINK_CMD_TYPE_MULTIPLE_CHOICE   = 4         //支持选中多个选项的菜单
} LinkCommandType;

typedef enum {
    LINK_CMD_GROUP_MOVIE            = 1,        //录像/视频相关菜单
    LINK_CMD_GROUP_PHOTO            = 2,        //拍照/照片相关菜单
    LINK_CMD_GROUP_IQ               = 3,        //影像质量相关菜单
    LINK_CMD_GROUP_DEVICE           = 4,        //设备功能相关菜单
    LINK_CMD_GROUP_DEFAULT          = LINK_CMD_GROUP_DEVICE +1  //设备功能相关菜单
} LinkCommandGroup;

typedef enum  {
    LINK_NOTIFY_UNDEFINE            = -1,       //未定义的通知值,一般表示方案上新添加的通知值尚未兼容

    LINK_NOTIFY_REC_STARTED         = 100,      //录像开始
    LINK_NOTIFY_REC_STOPPED         = 101,      //录像停止
    LINK_NOTIFY_REC_LOCKED          = 102,      //录像加锁or紧急录像开始or精彩录像开始
    LINK_NOTIFY_REC_UNLOCKED        = 103,      //录像解锁or紧急录像结束or精彩录像结束

    LINK_NOTIFY_REC_TIME_RESET      = 104,      //刷新录像计时

    LINK_NOTIFY_DO_CAPTURE          = 105,      //设备请求发送拍照指令

    LINK_NOTIFY_MIC_ON              = 106,      //麦克风打开
    LINK_NOTIFY_MIC_OFF             = 107,      //麦克风关闭

    LINK_NOTIFY_MOVIE_WR_ERROR      = 108,      //视频读写出错

    LINK_NOTIFY_CARD_INSERT         = 109,      //已插入存储卡
    LINK_NOTIFY_CARD_REMOVE         = 110,      //存储卡已拔出
    LINK_NOTIFY_CARD_SLOW           = 111,      //存储卡写入速度慢
    LINK_NOTIFY_CARD_FULL           = 112,      //存储卡已满

    LINK_NOTIFY_PIP_STYLE_CHANGED   = 113,      //画中画风格改变

    LINK_NOTIFY_PARKING_GUARD_ON    = 114,      //停车监控打开
    LINK_NOTIFY_PARKING_GUARD_OFF   = 115,      //停车监控关闭

    LINK_NOTIFY_VIDEO_MODE          = 116,      //设备切换到录像模式
    LINK_NOTIFY_PHOTO_MODE          = 117,      //设备切换到拍照模式
    LINK_NOTIFY_PLAYBACK_MODE       = 118,      //设备切换到回放模式
    LINK_NOTIFY_WILL_CHANGE_MODE    = 119,      //设备即将切换工作模式

    LINK_NOTIFY_NEW_USER            = 120,      //新的用户已连接设备,需要断开连接

    LINK_NOTIFY_WIFI_DISCONNECT     = 121,      //WIFI断开

    LINK_NOTIFY_BATTERY_CHANGE      = 122,      //电池电量变化(附加数据中获取具体的电量等级)

    LINK_NOTIFY_SYSTEM_RESET        = 123,      //系统恢复默认设置
    LINK_NOTIFY_POWER_OFF           = 124,      //设备即将关机

    LINK_NOTIFY_CAPTURE_SUCCESS     = 125,      //设备成功完成一次拍照

#if (defined PURE_YADEA)
    LINK_NOTIFY_VEHICLE_STOPPED     = 126,      //设备检测到无车速(车辆停止)
    LINK_NOTIFY_VEHICLE_MOVING      = 127       //设备检测到有车速(车辆行驶中)
#endif
} LinkNotifyCode;

typedef enum  {
    LINK_STATE_OK                       = 0,        //状态正常
    LINK_STATE_FILE_NOT_EXIST           = -1,       //文件不存在
    LINK_STATE_FILE_NO_EXIF             = -2,       //照片文件缺失EXIF信息
    LINK_STATE_FILE_READ_ONLY           = -3,       //文件是只读的
    LINK_STATE_FILE_ERROR               = -4,       //文件错误
    LINK_STATE_FILE_DELETE_FAIL         = -5,       //文件删除失败
    LINK_STATE_FILE_WR_ERROR            = -6,       //文件读写错误

    LINK_STATE_STORAGE_NONE             = -7,       //无卡
    LINK_STATE_STORAGE_ERROR            = -8,       //卡错误
    LINK_STATE_STORAGE_FULL             = -9,       //卡存储空间满
    LINK_STATE_STORAGE_SLOW             = -10,      //卡读写速度慢

    LINK_STATE_FW_READ_ERROR            = -11,      //固件信息读取错误
    LINK_STATE_FW_WRITE_ERROR           = -12,      //固件信息写入错误
    LINK_STATE_FW_STORAGE_ERROR         = -13,      //固件存储失败
    LINK_STATE_FW_UPGRADE_ERROR         = -14,      //固件升级错误

    LINK_STATE_NO_MEMORY                = -15,      //设备内存空间不足
    LINK_STATE_PARAM_ERROR              = -16,      //发送给设备的命令中的参数错误
    LINK_STATE_BATTERY_LOW              = -17,      //设备电量低
    LINK_STATE_ILLEGAL_STATE            = -18,      //设备目前的状态不正确,无法执行相关操作
    LINK_STATE_EXECUTE_FAIL             = -19,      //设备执行操作失败
    LINK_STATE_UNKNOWN_PROTOCOL         = -20,      //设备不支持发送的命令
    LINK_STATE_ACCESS_REFUSED           = -21,      //设备拒绝访问

    LINK_STATE_UNDEFINE                 = -99       //通常表示没有被兼容的返回值状态类型
} LinkStateCode;

typedef enum {
    LINK_STORAGE_INTERNAL = 0,  //内置存储,对于只有单存储设备,内置存储可能是EMMC也有可能是TF卡或SD卡,对于双存储设备,一般是EMMC
    LINK_STORAGE_EXTERNAL = 1   //外置存储,不是必定有的,一般可以拔插,如TF卡、SD卡
} LinkStorageType;

typedef enum {
    LINK_WORKMODE_PHOTO     = 0,        //拍照模式
    LINK_WORKMODE_VIDEO     = 1,        //视频模式
    LINK_WORKMODE_PLAYBACK  = 2         //回放模式
} LinkWorkMode;

typedef enum  {
    LINK_CARD_OK                = 0,    //卡正常
    LINK_CARD_REMOVED           = 1,    //无卡
    LINK_CARD_FULL              = 2,    //卡满
    LINK_CARD_READ_ONLY         = 3,    //卡只允许读
    LINK_CARD_LOCKED            = 4,    //卡锁定
    LINK_CARD_UNFORMATTED       = 5,    //存储卡未格式化
    LINK_CARD_UNKNOWN_FORMAT    = 6,    //无法识别的卡格式
    LINK_CARD_BAD               = 7,    //坏卡
    LINK_CARD_ERROR             = 8     //卡错误(其他错误)
} LinkStorageState;

typedef enum {
    LINK_BATTERY_FULL           = 0,    //电量满
    LINK_BATTERY_MED            = 1,    //电量中
    LINK_BATTERY_LOW            = 2,    //电量低
    LINK_BATTERY_EMPTY          = 3,    //电池极低
    LINK_BATTERY_EXHAUSTED      = 4,    //电量耗尽
    LINK_BATTERY_CHARGE         = 5,    //充电中
    LINK_BATTERY_NONE           = 6     //无电池
} LinkBatteryState;

typedef enum {
    LINK_BOOL_STATE_OFF  = 0,
    LINK_BOOL_STATE_ON   = 1
} LinkBoolState;

typedef enum {
    LINK_FILE_COPY_NONE         = 0,    //不支持文件拷贝功能
    LINK_FILE_COPY_ON           = 1,    //支持文件拷贝功能,且设备未处于文件拷贝中
    LINK_FILE_COPY_EXECUTING    = 2     //支持文件拷贝功能,且设备正在进行文件拷贝
} LinkFileCopyState;

typedef enum {
    LINK_DIR_MIN            = -1,
    LINK_DIR_PHOTO          = 0,        //普通照片
    LINK_DIR_VIDEO          = 1,        //普通录像
    LINK_DIR_EVENT          = 2,        //加锁录像(自动加锁|手动加锁)
#if (defined PURE_CARMAX)
    LINK_DIR_EVENT_PHOTO    = 3,        //加锁照片(自动加锁|手动加锁)
#endif
    LINK_DIR_MAX
} LinkDirType;

#if (defined PURE_CARMAX)
typedef enum {
    LINK_FILE_LOCK_NONE        = 0,        //未加锁
    LINK_FILE_LOCK_AUTO        = 1,        //自动加锁
    LINK_FILE_LOCK_MANUAL      = 2,        //手动加锁
} LinkFileLockType;
#endif

typedef enum {
    LINK_SOFTWARE_MIN       = 0x0,
    LINK_SOFTWARE_FW        = 0x1,          //固件
    LINK_SOFTWARE_EDOG      = 0x2,          //电子狗
    LINK_SOFTWARE_MCU       = 0x4,          //MCU
    LINK_SOFTWARE_F_SENSOR  = 0x8,          //前镜头
    LINK_SOFTWARE_R_SENSOR  = 0x10,         //后镜头
    LINK_SOFTWARE_MAX  = LINK_SOFTWARE_FW | LINK_SOFTWARE_EDOG | LINK_SOFTWARE_MCU | LINK_SOFTWARE_F_SENSOR | LINK_SOFTWARE_R_SENSOR
} LinkSoftwareType;

typedef enum {
    LINK_CAP_PHOTO_MODE                     = 0,
    LINK_CAP_MULTIPLE_STORAGE               = 1,
    LINK_CAP_STORAGE_SWITCH                 = 2,
    LINK_CAP_EXTERNAL_STORAGE_SPACE         = 3,
    LINK_CAP_FORMAT_INTERNAL_STORAGE        = 4,
#if (defined PURE_BYLINWELL)
    LINK_CAP_VIN_CODE                       = 5,
    LINK_CAP_VIN_CODE_MODIFY                = 6,
#endif
    LINK_CAP_GPS_IN_FILE                    = 7,
    LINK_CAP_DISPLAY_RT_TRACK               = 8,
    LINK_CAP_VIDEO_REC                      = 9,
    LINK_CAP_REC_TIME                       = 10,
    LINK_CAP_OTA                            = 11,
    LINK_CAP_MAX
} LinkCapability;

#if (defined PURE_YADEA)
typedef enum {
    LINK_VEHICLE_STATE_STOPPED  = 0,    //车辆停止
    LINK_VEHICLE_STATE_MOVING   = 1     //车辆行驶中
} LinkVehicleState;
#endif

typedef enum {
    LINK_CONNECTION_STATE_NONE          = 0,    //未连接
    LINK_CONNECTION_STATE_CONNECTING    = 1,    //连接中
    LINK_CONNECTION_STATE_CONNECTED     = 2,    //已连接
} ConnectionState;

typedef enum {
    LINK_CONNECTION_TYPE_NONE    = 0,    //无连接
    LINK_CONNECTION_TYPE_WIFI    = 1,    //通过WiFi连接
    LINK_CONNECTION_TYPE_4G      = 2,    //通过4G连接
    LINK_CONNECTION_TYPE_ALL     = 3,    //通过WiFi和4G同时连接
} ConnectionType;

#endif //LINKSDK_LINK_CODE_DEF_H
