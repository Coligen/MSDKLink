#
# Be sure to run `pod lib lint MSDKLink.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MSDKLink'
  s.version          = '0.2.0'
  s.summary          = 'A short description of Link SDK'

  s.description      = 'Coligen Link SDK'

  s.homepage         = 'https://github.com/Coligen'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhoubing@coligen.com' => 'zhoubing@coligen.com' }
  s.source           = { :git => 'https://github.com/Coligen/MSDKLink.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'
  
  s.source_files = 'MSDKLink/Classes/**/*'
  s.vendored_frameworks = 'MSDKLink/**/*.framework'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 arm64' }

end
