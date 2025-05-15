
#import <Foundation/Foundation.h>
#import "link_code_def.h"


@interface LinkSDKModel : NSObject

@end



@interface LinkSDKFileModel : NSObject

//文件名
@property (nonatomic, copy) NSString *name;
//缩略图地址
@property (nonatomic, copy) NSString *thumbURL;
//下载地址
@property (nonatomic, copy) NSString *downloadURL;
//在线地址
@property (nonatomic, copy) NSString *onlineURL; 
//option地址
@property (nonatomic, copy) NSString *optionURL;
//文件类型
@property (nonatomic, assign) LinkDirType type;
//保留字段(保存删除)
@property (nonatomic, copy) NSString *param;
//本地播放地址
@property (nonatomic, copy) NSString *localURL;

//时间戳
@property (nonatomic, assign) NSInteger timestamp;

//文件大小
@property (nonatomic, assign) NSInteger size;


@end

@interface LinkSDKSpaceModel : NSObject

//总容量
@property (nonatomic, assign) NSInteger total;
//可用容量
@property (nonatomic, assign) NSInteger free;

@end

@interface LinkSDKLiveStreamModel : NSObject
// 工作模式
@property (nonatomic, assign) LinkWorkMode workMode;
// 实时流地址
@property (nonatomic, copy) NSString *liveURL;

@end

@interface LinkSDKOptionModel : NSObject

// 选项
@property (nonatomic, copy) NSString *option;

//索引
@property (nonatomic, assign) int index;

//扩展字段
@property (nonatomic, copy) NSString *extend;

// 是否可设置
@property (nonatomic, assign) BOOL enabled;


@end


@interface LinkSDKCMDModel : NSObject

// 命令
@property (nonatomic, assign) LinkCommand cmd;

// 命令描述
@property (nonatomic, copy) NSString *name;

// 激活状态
@property (nonatomic, assign) NSInteger active;

// 是否可设置
@property (nonatomic, assign) BOOL enabled;

// 菜单类型
@property (nonatomic, assign) NSInteger type;

// 菜单分类
@property (nonatomic, assign) NSInteger group;

// 菜单排序
@property (nonatomic, assign) NSInteger order;

// 规则限定
@property (nonatomic, copy) NSString *rule;

// 命令选项集合
@property (nonatomic, strong) NSMutableArray<LinkSDKOptionModel *> *options;

@end

@interface LinkSDKSoftwareModel : NSObject

// 产品名称(设备名称)
@property (nonatomic, copy) NSString *productName;
// 软件定版时间
@property (nonatomic, assign) int buildDate;
// 软件内部版本(x.y.z格式)
@property (nonatomic, copy) NSString *buildVersion;
// 适用地区(使用ISO 3166-1 两位代码)
@property (nonatomic, copy) NSString *locale;
// 软件类型
@property (nonatomic, assign) int softwareType;

@end



