

#import <Foundation/Foundation.h>
#import "link_code_def.h"
#import "LinkSDKModel.h"

@interface LinkManager : NSObject

@property(nonatomic, copy) void (^_Nullable notifyBlock)(LinkNotifyCode type, NSString *_Nullable valueString);//机器状态通知

// 文件进度
@property(nonatomic, copy) void (^_Nullable progressBlock)(double total, double now);

+ (LinkManager *_Nonnull)shareInstance;

/// 连接设备
/// @param block ：函数回调，返回请求状态code
- (void)connect:(void (^_Nullable)(NSInteger code))block;


/// 断开设备
- (void)disconnect;

/// 打开机器消息通知
/// @param block : 函数回调，返回请求状态code
- (void)openNotify:(void (^_Nullable)(NSInteger code))block;

/// 关闭机器消息通知
- (void)closeNotify;


/// 获取预览地址
/// @param block ：函数回调，返回请求状态code及预览地址list。当code异常时，list直接忽视
- (void)getStreamURL:(void (^_Nullable)(NSInteger code, NSArray * _Nullable list))block;


/// 获取设备工作模式
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state负值时对应LinkStateCode值，否则对应LinkWorkMode。
- (void)getWorkMode:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 设置设备工作模式
/// @param mode :  工作模式，具体请参考LinkWorkMode
/// @param block ：函数回调，返回请求状态code及设备状态值state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)setWorkMode:(LinkWorkMode)mode callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 预览是否支持拍照
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值， 0代表不支持拍照，1代表支持拍照。
- (void)isPhotoModelSupported:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 设置设备录像状态
/// @param state : 0代表关闭，1代表打开
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)setVideoRecState:(BOOL)state callback:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询设备录像状态
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，0代表非录像状态，1代表正在录像。
- (void)getVideoRecStatus:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询当前已录像时长
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，其余值对应当前已录像时长，单位为s(秒)。
- (void)queryRecSeconds:(void (^_Nullable)(NSInteger code, NSInteger state))block;

    
/// 闪照，仅在录像状态下使用
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)snapshot:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 拍照，仅在预览为拍照模式下使用
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)takePhoto:(void (^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取菜单列表
/// @param block  ： 函数回调，返回请求状态code及菜单列表list。当code异常时，list内容直接忽视
/// @param isCache : 是否使用缓存数据。当设置为NO时，将清空缓存重新拉取菜单列表。
- (void)getMenuList:(void (^_Nullable)(NSInteger code, NSArray * _Nullable list))block cache:(BOOL)isCache;


/// 获取菜单选项状态
/// @param cmd  : 设置选项
/// @param block ：函数回调，返回请求状态code，state及当前菜单选项menuValue。当code异常时，state和menuValue直接忽视。
/// 仅当code及state正常时使用menuValue内容。
- (void)getMenuState:(NSInteger)cmd callback:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable menuValue))block;


/// 菜单选项设置
/// @param cmd : 设置选项
/// @param opt : 设置状态选项
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)setMenuState:(NSInteger)cmd status:(NSString *_Nonnull)opt callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 设备是否有多个存储区域
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，0代表单存储，1代表多存储。
- (void)isMultipleStorageSupported:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询设备是否支持切换存储区域
/// @param block  ： 函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，0代表不支持切换存储区域，1代表支持切换存储区域。
- (void)isStorageSelectSupported:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 切换设备存储区域
/// @param type : 存储区域类型，具体参考LinkStorageType
/// @param block ： 函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)storageSelect:(LinkStorageType)type callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取文件目录名
/// @param block ：函数回调，返回请求状态code及文件目录list。当code异常时，list内容直接忽视
- (void)getFileDirectory:(void(^_Nullable)(NSInteger code,NSArray * _Nullable list))block;


/// 获取文件列表（全部）（注意：机器必须处于回放模式）
/// @param type :  查询文件类型，具体参考FileType
/// @param block ：函数回调，返回请求状态code及文件列表list。当code异常时，list内容直接忽视
- (void)getFileList:(LinkDirType)type callback:(void(^_Nullable)(NSInteger code,NSArray <LinkSDKFileModel *>* _Nullable list))block;


/// 获取文件列表（分页）（注意：机器必须处于回放模式）
/// @param type :  查询文件类型，具体参考FileType
/// @param index :  查询文件起始
/// @param number :  查询文件个数
/// @param block : 函数回调，返回请求状态code及文件列表list。当code异常时，list内容直接忽视
- (void)getFileList:(LinkDirType)type from:(NSInteger)index count:(NSInteger)number callback:(void(^_Nullable)(NSInteger code,NSArray <LinkSDKFileModel *>* _Nullable list))block;


/// 删除文件
/// @param fileURL  : 指定删除文件信息
/// @param block : 函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)deleteFile:(NSString *_Nonnull)fileURL callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询设备是否正在文件拷贝
/// @param block ：函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，其余代表LinkFileCopyState值。
- (void)getFileCopyState:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 拷贝文件到TF卡
/// @param fileURL  : 传入拷贝文件路径
/// @param block  ：函数回调，返回请求状态code。code异常时，state内容直接忽略。
/// state对应LinkStateCode值。
- (void)copyFileToTFCard:(NSString *_Nonnull)fileURL callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 当前拷贝文件进度
/// @param block ：函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，否则对应拷贝进度值。
- (void)getFileCopyProgress:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 检测外部存储状态
/// @param block ：函数回调，返回请求状态code及外部存储状态state。code异常时，state状态直接忽略。
/// state为负值时对应LinkStateCode值，否则对应LinkStorageState值。
- (void)getExternalStorageState:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 是否显示外部存储空间
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state为负值时对应LinkStateCode值，0代表不显示外部存储空间，1代表显示外部存储空间。
- (void)shouldShowExternalStorageSpace:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询剩余空间
/// @param type : 需要查询的存储区域，具体参考LinkStorageType
/// @param block ：函数回调，返回请求状态code，state及存储空间信息space。code异常时，state及space内容直接忽略。
/// 仅当code及state均正常时才使用space内容
- (void)queryStorageSpace:(LinkStorageType)type callback:(void(^_Nullable)(NSInteger code, NSInteger state, LinkSDKSpaceModel * _Nullable space))block;


/// 查询是否支持格式化存储区域
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state为负值时对应LinkStateCode值，0代表不支持格式化存储区域，1代表支持格式化存储区域。
- (void)isInternalStorageFormatSupported:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 格式化存储区域
/// @param type : 格式化对象，具体参考StorageType
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state对应LinkStateCode值。
- (void)formatStorage:(LinkStorageType)type callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 设备同步系统时间
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state对应LinkStateCode值。
- (void)syncTime:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 设备系统重置
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state对应LinkStateCode值。
- (void)systemReset:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 设备系统版本号
/// @param block ：函数回调，返回请求状态code，state及设备系统版本号。code异常时，state及version内容直接忽略。
/// 仅当code及state正常时才使用version内容。
- (void)getSystemVersion:(LinkSoftwareType)type callback:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable version))block;


/// 设备电量信息,具体参考BatteryLevel结构体
/// @param block ：函数回调，返回请求状态code及电量信息state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，否则对应LinkBatteryState值。
- (void)getBatteryState:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取WiFi名称
/// @param block ：函数回调，返回请求状态code，state及WiFi name。code异常时，state及name内容直接忽略。
/// 仅当code及state正常时才使用name内容。
- (void)getWiFiSSID:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable name))block;


/// 修改WiFi名称
/// @param name : 新的WiFi名称
/// @param block ：函数回调，返回请求状态code。code异常时，state内容直接忽略。
/// state对应LinkStateCode值。
- (void)setWiFiSSID:(NSString *_Nonnull)name callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询WiFi密码
/// @param block ：函数回调，返回请求状态code，state及WiFi密码psd。code异常时，state及psd内容直接忽略。
/// 仅当code及state正常时才使用psd内容。
- (void)getWiFiPassword:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable psd))block;


/// 修改WiFi密码
/// @param psd : 新的WiFi密码
/// @param block ：函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state对应LinkStateCode值。
- (void)setWiFiPassword:(NSString *_Nonnull)psd callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


#if (defined BYLINWELL_SINGLE_ENCRYPT)

/// 是否支持车辆识别码
/// @param block ：函数回调，返回请求状态code及state。code异常时，state直接忽略。
/// state为负值时对应LinkStateCode值。0代表不支持车辆识别码，1代表支持车辆识别码。
- (void)isVinCodeSetSupported:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询车辆识别码
/// @param block ：函数回调，返回请求状态code及车辆识别码vin。code异常时，state及vin内容直接忽略。
/// 仅当code及state正常时才使用vin内容。
- (void)getVinCode:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable vin))block;


/// 修改车辆识别码
/// @param vcode  : 新车辆识别码
/// @param block ：函数回调，返回请求状态code及state。code异常时，state内容直接忽略
/// state对应LinkStateCode值。
- (void)setVinCode:(NSString *_Nonnull)vcode callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;

#endif



#if (defined YADEA_SINGLE_ENCRYPT)

/// 查询车辆行驶状态
/// @param block ：函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，否则对应LinkVehicleState值。
- (void)getVehicleSpeed:(void(^_Nullable)(NSInteger code, NSInteger state))block;

#endif



/// 设置PIR间隔时间
/// @param interval : 间隔时间，单位s
/// @param block : 函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，否则对应LinkVehicleState值。
- (void)setPIRInterval:(NSInteger)interval callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 设置监控时段
/// @param index : 监控时段索引(机器可能支持多个时段)
/// @param bt : 开始时间
/// @param et : 结束时间
/// @param block : 函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state为负值时对应LinkStateCode值，否则对应LinkVehicleState值。
- (void)setMonitorPerid:(NSInteger)index beginTime:(NSString *_Nonnull)bt endTime:(NSString *_Nonnull)et callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询设备是否支持在线获取文件GPS信息
/// @param block  ： 函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，0代表不支持在线GPS，1代表支持在线GPS。
- (void)isFileGPSSupported:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取文件GPS信息
/// @param file ：文件名
/// @param block ：函数回调，返回请求状态code，state及GPS信息。当code异常时，state及gpsinfo直接忽视。
/// 仅当code和state正常时才使用gpsinfo内容。
- (void)getFileGPSInfo:(NSString *_Nonnull)file callback:(void(^_Nullable)(NSInteger code, NSInteger state,NSString * _Nullable gpsinfo))block;


/// APP是否需要显示实时地图轨迹
/// @param block  ： 函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值，0代表不支持地图轨迹，1代表支持地图轨迹。
- (void)isShouldShowRTMapTacks:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取设备软件版本信息(OTA功能标准化版本信息)
/// @param type ：软件类型
/// @param block ：函数回调，返回请求状态code、state及固件信息。当code异常时或state异常时，softwareModel内容直接忽视。
- (void)getSoftwareVersion:(LinkSoftwareType)type callback:(void(^_Nullable)(NSInteger code, NSInteger state, LinkSDKSoftwareModel * _Nullable softwareModel))block;


/// 上传升级文件
/// @param type ：软件类型
/// @param filePath ：文件本地路径
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// @param progressBlock ：固件升级进度，total问总文件大小，now为当前已传输文件大小
- (void)sendUpgradeFile:(LinkSoftwareType)type filePath:(NSString *_Nonnull)filePath callback:(void(^_Nullable)(NSInteger code, NSInteger state))block progressBlock:(void(^_Nullable)(double total, double now))progressBlock;


/// 通知设备升级
/// @param type ：软件类型
/// @param filePath ：文件本地路径
/// @param block ：函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)softwareUpdate:(LinkSoftwareType)type filePath:(NSString *_Nonnull)filePath callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 获取设备软件版本信息(OTA功能标准化版本信息)
/// @param block :函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值。0代表不支持OTA升级，1代表支持OTA升级。
- (void)getOtaSupportState:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 查询设备功能支持
/// @param cap : 查询的功能
/// @param block :函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值。0代表不支持所查询的功能，1代表支持所查询的功能。
- (void)queryDeviceCapability:(LinkCapability)cap block:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 更改文件状态
/// @param fileURL :文件路径url
/// @param block :函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state对应LinkStateCode值。
- (void)changFileState:(NSString *_Nonnull)fileURL block:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 录像中文件加锁（预览）
/// @param block :函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state对应LinkStateCode值。
- (void)recLock:(void(^_Nullable)(NSInteger code, NSInteger state))block;


// 获取某一路摄像头状态
/// @param index 入参为摄像头索引，从0开始
/// @param block :函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值。0表示摄像头未连接，1表示已连接
- (void)getCameraState:(int)index callback:(void(^_Nullable)(NSInteger code, NSInteger state))block;

/// 获取设备ID
/// @param block :函数回调，返回请求状态code及state。当code异常时，state直接忽视。
/// state为负值时对应LinkStateCode值。deviceID：设备ID
- (void)getDeviceID:(void(^_Nullable)(NSInteger code, NSInteger state, NSString * _Nullable deviceID))block;

/// 停止文件拷贝
/// @param block :函数回调，返回请求状态code及state。code异常时，state内容直接忽略。
/// state对应LinkStateCode值。
- (void)stopFileCopy:(void(^_Nullable)(NSInteger code, NSInteger state))block;


/// 打开心跳
/// @param block ：函数回调，返回请求状态code。
- (void)openHeartRate:(void(^_Nullable)(NSInteger code))block;

/// 关闭心跳
- (void)closeHeartRate;

/// 设置心跳间隔
/// @param interval ：
/// @param block ：函数回调，返回请求状态code。
- (void)setHeartRateInterval:(int)interval block:(void(^_Nullable)(NSInteger code))block;

@end

